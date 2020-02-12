

set (SAMPLE_PLUGIN_SOURCES
        sample_plugin.cc
		hit.h
		shower.h
		shower_factory.cc
		shower_factory.h
		random_source.cc
		random_source.h
		stdout_processor.cc
		stdout_processor.h
)

add_library(sample_plugin SHARED ${SAMPLE_PLUGIN_SOURCES})

find_package(JANA REQUIRED)
target_include_directories(sample_plugin PUBLIC ${JANA_INCLUDE_DIR})
target_link_libraries(sample_plugin ${JANA_LIBRARY})
set_target_properties(sample_plugin PROPERTIES PREFIX "" OUTPUT_NAME "sample_plugin" SUFFIX ".so")
install(TARGETS sample_plugin DESTINATION plugins)

