cmake_minimum_required(VERSION 3.10.0)
project(adventureGame VERSION 0.1.0 LANGUAGES C CXX)

#CMake VSCODE plugin setup
include(CTest)
enable_testing()
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_executable(${PROJECT_NAME} main.cpp)

#VCPKG libraries
find_package(fmt CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)

#Local libraries
target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/dependencies/)
#target_link_libraries(${PROJECT_NAME} PRIVATE kba)