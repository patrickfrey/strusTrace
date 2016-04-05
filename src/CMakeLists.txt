cmake_minimum_required(VERSION 2.6 FATAL_ERROR)

# --------------------------------------
# SOURCES AND INCLUDES
# --------------------------------------
set( libstrus_shadow_source_files
	internationalization.cpp
	serialize.cpp
	traceLogger.cpp
	traceSerializer.cpp
	traceViewer.cpp
	traceViewer_gen.cpp
)

include_directories(
	"${Boost_INCLUDE_DIRS}"
	"${Intl_INCLUDE_DIRS}"
	"${PROJECT_SOURCE_DIR}/include" )
link_directories(
	"${Boost_LIBRARY_DIRS}"
	"${PROJECT_SOURCE_DIR}/utils" )


# -------------------------------------------
# STRUS SHADOW LIBRARY
# Library for data introspection of strus runs
# -------------------------------------------
add_library( strus_shadow SHARED ${libstrus_shadow_source_files} )
target_link_libraries( strus_shadow ${Boost_LIBRARIES} )
set_target_properties(
    strus_shadow
    PROPERTIES
    DEBUG_POSTFIX "_d"
    SOVERSION "${STRUS_MAJOR_VERSION}.${STRUS_MINOR_VERSION}"
    VERSION ${STRUS_VERSION}
)

# ------------------------------
# INSTALLATION
# ------------------------------
install( TARGETS strus_shadow
           LIBRARY DESTINATION ${LIB_INSTALL_DIR}/strus )

