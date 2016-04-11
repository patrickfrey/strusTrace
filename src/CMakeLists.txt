cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

# Subdirectories:
add_subdirectory( parser )

# --------------------------------------
# SOURCES AND INCLUDES
# --------------------------------------
set( libstrus_trace_source_files
	internationalization.cpp
	serialize.cpp
	traceObject.cpp
	traceLogger.cpp
	traceSerializer.cpp
	traceViewer.cpp
	traceViewer_gen.cpp
	objects_gen.cpp
)

include_directories(
	"${Boost_INCLUDE_DIRS}"
	"${Intl_INCLUDE_DIRS}"
	"${PROJECT_SOURCE_DIR}/include"
	"${strus_INCLUDE_DIRS}"
	"${strusanalyzer_INCLUDE_DIRS}" )
link_directories(
	"${Boost_LIBRARY_DIRS}"
	"${strus_LIBRARY_DIRS}"
	"${strusanalyzer_LIBRARY_DIRS}" )


# -------------------------------------------
# STRUS TRACE LIBRARY
# Library for data introspection of strus runs
# -------------------------------------------
add_library( strus_trace SHARED ${libstrus_trace_source_files} )
target_link_libraries( strus_trace ${Boost_LIBRARIES} )
set_target_properties(
    strus_trace
    PROPERTIES
    DEBUG_POSTFIX "_d"
    SOVERSION "${STRUS_MAJOR_VERSION}.${STRUS_MINOR_VERSION}"
    VERSION ${STRUS_VERSION}
)

# ------------------------------
# INSTALLATION
# ------------------------------
install( TARGETS strus_trace
           LIBRARY DESTINATION ${LIB_INSTALL_DIR}/strus )

