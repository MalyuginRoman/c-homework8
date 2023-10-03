cmake_minimum_required(VERSION 3.7.2)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})

project(boost_test VERSION ${PROJECT_VERSION})
set(CMAKE_CXX_STANDARD 17)

message(STATUS "CMAKE_TOOLCHAIN_FILE: ${DCMAKE_TOOLCHAIN_FILE}")

configure_file(version.h.in version.h)

find_package (Boost REQUIRED program_options)

if (Boost_FOUND)
    include_directories (${Boost_INCLUDE_DIRS})
    add_executable(boost_test
    bayan.cpp
    hasher.cpp
    utils.cpp
    main.cpp)
    target_link_libraries(boost_test ${Boost_LIBRARIES})
endif ()



install(TARGETS boost_test RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT example@example.com)

include(CPack)
