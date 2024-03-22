cmake_minimum_required(VERSION 3.15.0)
project(
    adventureGame 
    VERSION 0.0.1
    DESCRIPTION ""
    LANGUAGES C CXX
    )
add_executable(${PROJECT_NAME} ${CMAKE_SOURCE_DIR}/src/main.cpp)

#CMake VSCODE plugin setup
include(CTest)
enable_testing()
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

include(FetchContent)

FetchContent_Declare(
    fmt
    GIT_REPOSITORY "https://github.com/fmtlib/fmt.git"
    GIT_TAG 10.2.1
)
FetchContent_MakeAvailable(fmt)
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)




#THIS NEEDS TO BE FIXED
#Local libraries precompiled 
#target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/libs/)    #Use this for .h together with .lib files
#target_link_libraries(${PROJECT_NAME} PRIVATE /kba/include/kba.h) 
#target_link_options(${PROJECT_NAME} PRIVATE /NODEFAULTLIB:MSVCRTD) #/NODEFAULTLIB:MSVCRTD is specified, because else it will raise an error


#Local libraries (here you can referece the as lib.h , without the path)  #Use this for .h with .cpp files
add_library(kba STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/kba.cpp) # Add the library as a target
target_include_directories(kba PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include) # Include directories for the library
target_link_libraries(${PROJECT_NAME} PRIVATE kba) # Link the library to the main executable