cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

# Subdirectories:
add_subdirectory( parser )

# --------------------------------------
# SOURCES AND INCLUDES
# --------------------------------------
set( source_files_proc
	${CMAKE_CURRENT_BINARY_DIR}/internationalization.cpp
	logUtils.cpp
	traceLogger_json.cpp
	traceLogger_dump.cpp
	traceLogger_breakpoint.cpp
	traceLogger_count.cpp
)

set( source_files_obj
	internationalization.cpp
	traceSerializer.cpp
	traceObject.cpp
	objects_gen.cpp
	objectIds_gen.cpp
	traceObjectBuilder.cpp
)

include_directories(
	${Boost_INCLUDE_DIRS}
	"${Intl_INCLUDE_DIRS}"
	"${TRACE_INCLUDE_DIRS}"
	"${strusbase_INCLUDE_DIRS}"
	"${strus_INCLUDE_DIRS}"
	"${strusanalyzer_INCLUDE_DIRS}" 
	"${CMAKE_CURRENT_BINARY_DIR}"
	"${MAIN_SOURCE_DIR}"
)

link_directories(
	${Boost_LIBRARY_DIRS}
	"${strusbase_LIBRARY_DIRS}"
	"${strus_LIBRARY_DIRS}"
	"${strusanalyzer_LIBRARY_DIRS}" 
)


# -------------------------------------------
# STRUS TRACE LIBRARIES
# -------------------------------------------
add_library( strus_traceobj SHARED libstrus_traceobj.cpp ${source_files_obj} )
target_link_libraries( strus_traceobj strus_base ${Boost_LIBRARIES} ${Intl_LIBRARIES} )
set_target_properties(
    strus_traceobj
    PROPERTIES
    DEBUG_POSTFIX "${CMAKE_DEBUG_POSTFIX}"
    SOVERSION "${STRUS_MAJOR_VERSION}.${STRUS_MINOR_VERSION}"
    VERSION ${STRUS_VERSION}
)

add_library( strus_traceproc_std SHARED libstrus_traceproc_std.cpp ${source_files_proc} )
target_link_libraries( strus_traceproc_std strus_base  ${Boost_LIBRARIES} ${Intl_LIBRARIES} )
set_target_properties(
    strus_traceproc_std
    PROPERTIES
    DEBUG_POSTFIX "${CMAKE_DEBUG_POSTFIX}"
    SOVERSION "${STRUS_MAJOR_VERSION}.${STRUS_MINOR_VERSION}"
    VERSION ${STRUS_VERSION}
)

# ------------------------------
# INSTALLATION
# ------------------------------
install( TARGETS strus_traceobj
           LIBRARY DESTINATION ${LIB_INSTALL_DIR}/strus )

install( TARGETS strus_traceproc_std
           LIBRARY DESTINATION ${LIB_INSTALL_DIR}/strus )


