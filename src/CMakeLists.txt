cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

# Subdirectories:
add_subdirectory( parser )

# --------------------------------------
# SOURCES AND INCLUDES
# --------------------------------------
set( source_files
	internationalization.cpp
	serialize.cpp
	traceObject.cpp
	traceLogger.cpp
	traceLogger_textfile.cpp
	traceSerializer.cpp
	traceViewer.cpp
	traceIdMap.cpp
	traceIdMap_gen.cpp
	objects_gen.cpp
	traceProcessor.cpp
	traceObjectBuilder.cpp
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
# STRUS TRACELOG LIBRARY
# Library for generate method call traces and introspection of strus runs
# -------------------------------------------
add_library( strus_tracelog SHARED libstrus_tracelog.cpp ${source_files} )
target_link_libraries( strus_tracelog ${Boost_LIBRARIES} )
set_target_properties(
    strus_tracelog
    PROPERTIES
    DEBUG_POSTFIX "_d"
    SOVERSION "${STRUS_MAJOR_VERSION}.${STRUS_MINOR_VERSION}"
    VERSION ${STRUS_VERSION}
)

# ------------------------------
# INSTALLATION
# ------------------------------
install( TARGETS strus_tracelog
           LIBRARY DESTINATION ${LIB_INSTALL_DIR}/strus )

