add_executable (plustache_tests
    test_change_delimiter.cpp
    test_collections_plustache.cpp
    test_html_escape_plustache.cpp
    test_inverted_sections.cpp
    test_multiple_plustache.cpp
    test_nested_sections_plustache.cpp
    test_partials_plustache.cpp
    tests.cpp
    test_sections_plustache.cpp
    test_simple_plustache.cpp
)
target_link_libraries (plustache_tests plustacheStatic boost_regex boost_unit_test_framework)

add_test(plustache_tests plustache_tests)
