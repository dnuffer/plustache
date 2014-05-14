#include <string>
#include <map>
#include <iostream>
#include <fstream>
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "template.hpp"
#include "plustache_types.hpp"

#include "gmock_to_boost.hpp"

// The fixture for testing class Foo.
struct ChangeDelimiterTest
{
    std::string result_string;
    std::string result_file;
    std::string template_string;
    std::string result_notfound;
    PlustacheTypes::ObjectType ctx;
    std::string file;

    ChangeDelimiterTest()
    {
        template_string = "Hi I am {{name}}.\n";
        template_string += "{{=<\% \%>=}}";
        template_string += "I like <\%pet\%>.";

        file = "multiple.mustache";

        std::ofstream myfile;
        myfile.open (file.c_str());
        myfile << template_string;
        myfile.close();

        ctx["name"] = "Daniel";
        ctx["pet"] = "turtles";
        Plustache::template_t t;
        result_string = t.render(template_string, ctx);
        Plustache::template_t t2;
        result_file = t2.render(file, ctx);
    }

    ~ChangeDelimiterTest()
    {
        remove(file.c_str());
    }
};

// Tests that a simple mustache tag is replaced
TEST_F(ChangeDelimiterTest, TestChangeDelimiterFromString)
{
    std::string expected = "Hi I am Daniel.\n";
           expected += "I like turtles.";
    EXPECT_EQ(expected, result_string);
}

TEST_F(ChangeDelimiterTest, TestChangeDelimiterFromFile)
{
    std::string expected = "Hi I am Daniel.\n";
           expected += "I like turtles.";
    EXPECT_EQ(expected, result_file);
}
