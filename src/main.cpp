#include <template.hpp>
#include <context.hpp>
#include <iostream>

int main(int argc, const char *argv[])
{
    using namespace Plustache;
    using namespace std;

    template_t t;
    string str_template;
    str_template = "text {{foo}} text";
    Context ctx;
    ctx.add("foo", "bla");
    string s;
    s = t.render(str_template, ctx);
    cout << s << endl;
    return 0;
}
