cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

include_directories(  
   "${Boost_INCLUDE_DIRS}"
   "${Intl_INCLUDE_DIRS}"
   "${PROJECT_SOURCE_DIR}/include" 
   "${PROJECT_SOURCE_DIR}/src"
   "${strusbase_INCLUDE_DIRS}"
   "${strus_INCLUDE_DIRS}"
   "${strusanalyzer_INCLUDE_DIRS}"
)

link_directories(
   "${Boost_LIBRARY_DIRS}"
   "${CMAKE_CURRENT_BINARY_DIR}/../../../src"
   "${strusbase_LIBRARY_DIRS}"
   "${strus_LIBRARY_DIRS}"
   "${strusanalyzer_LIBRARY_DIRS}"
)

add_executable( testQueryEval testQueryEval.cpp)
target_link_libraries( testQueryEval strus_storage_objbuild strus_analyzer_objbuild strus_base strus_traceobj strus_traceproc_std strus_error strus_storage strus_database_leveldb strus_textproc strus_analyzer strus_segmenter_textwolf strus_segmenter_cjson strus_queryeval strus_queryproc strus_base ${Boost_LIBRARIES} ${Intl_LIBRARIES})
