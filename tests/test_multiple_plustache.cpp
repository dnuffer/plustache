#include <string>
#include <iostream>
#include <fstream>
#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>

#include "template.hpp"
#include "plustache_types.hpp"
#include "gmock_to_boost.hpp"

// The fixture for testing class Foo.
struct MultipleTest
{
    std::string result_string;
    std::string result_file;
    std::string template_string;
    std::string expected;
    PlustacheTypes::ObjectType ctx;
    std::string file;
    MultipleTest()
    {
		 SetUp();
    }

    virtual ~MultipleTest()
    {
		 TearDown();
    }

    virtual void SetUp()
    {
        template_string = "<title>{{title}}</title>\n";
        template_string += "Hi I am {{name}}{{lastname}}.\n";
        template_string += "I like {{pet}}.{{!comment}}\n";
        file = "multiple.mustache";

        std::ofstream myfile;
        myfile.open(file.c_str());
        myfile << template_string;
        myfile.close();

        ctx["title"] = "Multiple Mustaches";
        ctx["name"] = "Daniel";
        ctx["pet"] = "turtles";
        Plustache::template_t t;
        result_string = t.render(template_string, ctx);
        result_file = t.render(file, ctx);
    }

    virtual void TearDown()
    {
        remove(file.c_str());
    }

};

// Tests that multiple mustache tags are replaced
TEST_F(MultipleTest, TestMultipleMustacheFromString)
{
    expected = "<title>Multiple Mustaches</title>\n";
    expected += "Hi I am Daniel.\n";
    expected += "I like turtles.\n";
    EXPECT_EQ(expected, result_string);
}

TEST_F(MultipleTest, TestMultipleMustacheFromFile)
{
    expected = "<title>Multiple Mustaches</title>\n";
    expected += "Hi I am Daniel.\n";
    expected += "I like turtles.\n";
    EXPECT_EQ(expected, result_file);
}
