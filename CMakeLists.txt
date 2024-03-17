cmake_minimum_required(VERSION 3.25.0)
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
find_package(rapidjson CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt rapidjson)

#Local libraries
target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/dependencies/)
#target_link_libraries(${PROJECT_NAME} PRIVATE kba)






#SLET
#INCLUDE_DIRECTORIES(C:/dev/vcpkg/installed/x64-windows/include)
#LINK_DIRECTORIES(C:/dev/vcpkg/installed/x64-windows/lib) 