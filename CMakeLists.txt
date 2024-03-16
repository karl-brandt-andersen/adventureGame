cmake_minimum_required(VERSION 3.28.0)

set(CMAKE_TOOLCHAIN_FILE "C:/dev/vcpkg/scripts/buildsystems/vcpkg.cmake")

project(adventureGame VERSION 0.1.0 LANGUAGES C CXX)

#include(CTest)
#enable_testing()

add_executable(${PROJECT_NAME} main.cpp)

set(CMAKE_PREFIX_PATH "C:/dev/vcpkg/installed/x64-windows/share")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

find_package(fmt CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)

#TIL EGNE BIBLIOTEKER, LÆR AT LAVE EGNE BIBLIOTEKER
target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/dependencies/)
target_link_libraries(${PROJECT_NAME} PRIVATE kba)

