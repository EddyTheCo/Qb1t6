cmake_minimum_required(VERSION 3.11 FATAL_ERROR)

include(local_conf.cmake OPTIONAL)
project(Qtb1t6 VERSION 0.1 DESCRIPTION "IOTA-QT b1t6 encoding " LANGUAGES CXX)

set(default_build_type "Release")
if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
	message(STATUS "Setting build type to '${default_build_type}' as none was specified.")
	set(CMAKE_BUILD_TYPE "${default_build_type}" CACHE
		STRING "Choose the type of build." FORCE)
	# Set the possible values of build type for cmake-gui
	set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
		"Debug" "Release" "MinSizeRel" "RelWithDebInfo")
endif()

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(qb1t6 include/encoding/qb1t6.hpp qb1t6.cpp)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/FindQt.cmake)

target_link_libraries(qb1t6 PUBLIC  Qt6::Core )

target_include_directories(qb1t6 PUBLIC  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	"$<INSTALL_INTERFACE:include>")

install(TARGETS qb1t6 EXPORT qb1t6Targets DESTINATION lib)
install(DIRECTORY include/ DESTINATION include/)

install(EXPORT qb1t6Targets
	FILE qb1t6Targets.cmake
	DESTINATION lib/cmake/qb1t6
	)
include(CMakePackageConfigHelpers)
# generate the config file that is includes the exports
configure_package_config_file(${CMAKE_CURRENT_SOURCE_DIR}/Config.cmake.in
	"${CMAKE_CURRENT_BINARY_DIR}/qb1t6Config.cmake"
	INSTALL_DESTINATION "lib/cmake/qb1t6"
	NO_SET_AND_CHECK_MACRO
	NO_CHECK_REQUIRED_COMPONENTS_MACRO
	)
write_basic_package_version_file(
	"${CMAKE_CURRENT_BINARY_DIR}/qb1t6ConfigVersion.cmake"
	VERSION "0.1.1.0"
	COMPATIBILITY AnyNewerVersion
	)
install(FILES
	${CMAKE_CURRENT_BINARY_DIR}/qb1t6Config.cmake
	${CMAKE_CURRENT_BINARY_DIR}/qb1t6ConfigVersion.cmake
	DESTINATION lib/cmake/qb1t6
	)
export(EXPORT qb1t6Targets
	FILE "${CMAKE_CURRENT_BINARY_DIR}/qb1t6Targets.cmake"
	)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
endif()
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    add_subdirectory(tests)
endif()
