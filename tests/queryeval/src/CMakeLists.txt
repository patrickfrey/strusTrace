cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

include_directories(  
   "${Boost_INCLUDE_DIRS}"
   "${Intl_INCLUDE_DIRS}"
   "${PROJECT_SOURCE_DIR}/include" 
   "${PROJECT_SOURCE_DIR}/src"
   "${strus_INCLUDE_DIRS}"
   "${strusanalyzer_INCLUDE_DIRS}"
)

link_directories(
   "${Boost_LIBRARY_DIRS}"
   "${PROJECT_SOURCE_DIR}/src"
   "${strusanalyzer_LIBRARY_DIRS}"
   "${strus_LIBRARY_DIRS}"
)

add_executable( testQueryEval testQueryEval.cpp)
target_link_libraries( testQueryEval strus_base strus_tracelog strus_error strus_storage strus_database_leveldb strus_textproc strus_analyzer strus_segmenter_textwolf strus_queryeval strus_queryproc strus_base ${Boost_LIBRARIES} ${Intl_LIBRARIES})
