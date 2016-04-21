cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

add_subdirectory(src)

add_test( TraceQueryEval src/testQueryEval path=storage out.txt res.txt )
