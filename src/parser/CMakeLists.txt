cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

# --------------------------------------
# SOURCES AND INCLUDES
# --------------------------------------
set( source_files
	interfaceParser.cpp
	printFrame.cpp
	fillTypeTables.cpp
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
# STRUS TRACE CODE GENERATOR
# Code generator that maps the strus interfaces to a tracing proxy implementation
# -------------------------------------------
add_executable( strusTraceCodeGen strusTraceCodeGen.cpp ${source_files} )
target_link_libraries( strusTraceCodeGen strus_base ${CMAKE_DL_LIBS} ${Intl_LIBRARIES} )


