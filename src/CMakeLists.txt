add_library (plustacheStatic STATIC
    context.cpp
    template.cpp
)

add_executable (plustache main.cpp)
target_link_libraries (plustache plustacheStatic boost_regex)
