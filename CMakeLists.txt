cmake_minimum_required(VERSION 3.10.0)
project(adventureGame VERSION 0.1.0 LANGUAGES C CXX)
add_executable(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/source/main.cpp)

#CMake VSCODE plugin setup
include(CTest)
enable_testing()
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

#VCPKG libraries
find_package(fmt CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)

#Local libraries precompiled
target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/libs/)    #Use this for .h together with .lib files
target_link_libraries(${PROJECT_NAME} PRIVATE kba/include/kba) 
#target_link_options(${PROJECT_NAME} PRIVATE /NODEFAULTLIB:MSVCRTD) #/NODEFAULTLIB:MSVCRTD is specified, because else it will raise an error

#Local libraries (here you can referece the as lib.h , without the path)
#set(KBA_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs/kba/) # Set the directory where your library source files reside                    #Use this for .h with .cpp files
#add_library(kba STATIC ${CMAKE_CURRENT_SOURCE_DIR}/libs/kba/source/kba.cpp) # Add the library as a target
#target_include_directories(kba PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/libs/kba/include/) # Include directories for the library
#target_link_libraries(${PROJECT_NAME} PRIVATE kba) # Link the library to the main executable