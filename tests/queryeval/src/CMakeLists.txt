cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

include_directories(  
   ${Boost_INCLUDE_DIRS}
   "${Intl_INCLUDE_DIRS}"
   "${TRACE_INCLUDE_DIRS}"
   "${MAIN_SOURCE_DIR}" 
   "${strusbase_INCLUDE_DIRS}"
   "${strus_INCLUDE_DIRS}"
   "${strusanalyzer_INCLUDE_DIRS}"
)

link_directories(
   ${Boost_LIBRARY_DIRS}
   "${Intl_INCLUDE_DIRS}"
   "${TRACE_LIBRARY_DIRS}"
   "${strusbase_LIBRARY_DIRS}"
   "${strus_LIBRARY_DIRS}"
   "${strusanalyzer_LIBRARY_DIRS}"
)

add_executable( testQueryEvalTrace testQueryEvalTrace.cpp)
target_link_libraries( testQueryEvalTrace strus_storage_objbuild strus_analyzer_objbuild strus_base strus_traceobj strus_traceproc_std strus_error strus_storage strus_database_leveldb strus_textproc strus_analyzer strus_segmenter_textwolf strus_segmenter_cjson strus_queryeval strus_queryproc strus_base strus_filelocator ${Boost_LIBRARIES} ${Intl_LIBRARIES})
