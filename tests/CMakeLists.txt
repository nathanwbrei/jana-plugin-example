

set (SAMPLE_PLUGIN_TESTS_SOURCES
        catch2.hpp
        tests_main.cc
        integration_tests.cc
        random_source_tests.cc
        shower_factory_tests.cc
        )

add_executable(sample_plugin_tests ${SAMPLE_PLUGIN_TESTS_SOURCES})

find_package(JANA REQUIRED)

target_include_directories(sample_plugin_tests PUBLIC ../src)
target_include_directories(sample_plugin_tests PUBLIC ${JANA_INCLUDE_DIR})

target_link_libraries(sample_plugin_tests sample_plugin)
target_link_libraries(sample_plugin_tests ${JANA_LIBRARY})

install(TARGETS sample_plugin_tests DESTINATION bin)

