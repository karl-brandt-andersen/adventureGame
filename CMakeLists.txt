cmake_minimum_required(VERSION 3.16.0)


project(
    adventureGame 
    VERSION 0.0.1
    DESCRIPTION "Adventure game"
    LANGUAGES CXX
)


add_executable( ${PROJECT_NAME} 
                ${CMAKE_SOURCE_DIR}/src/main.cpp 
                ${CMAKE_SOURCE_DIR}/src/engine.cpp 
                ${CMAKE_SOURCE_DIR}/src/player.cpp 
                ${CMAKE_SOURCE_DIR}/src/hp.cpp 
                ${CMAKE_SOURCE_DIR}/src/animation.cpp
                ${CMAKE_SOURCE_DIR}/src/physics.cpp
                ${CMAKE_SOURCE_DIR}/src/mapLoader.cpp
                ) 


option(BUILD_SHARED_LIBS "Build shared libraries" OFF)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)
set(CMAKE_BUILD_TYPE RelWithDebInfo)


#Add .lib and .h to add in code
add_library(kba STATIC IMPORTED)
set_target_properties(kba PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/libs/kba.lib)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PRIVATE kba)

#Add .cpp and .h and compile to .lib to add to code
#add_library(kba STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/kba.cpp) 
#target_include_directories(kba PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
#target_link_libraries(${PROJECT_NAME} PRIVATE kba)


#Fetch libs
include(FetchContent)
FetchContent_Declare(
    fmt
    GIT_REPOSITORY "https://github.com/fmtlib/fmt.git"
    GIT_TAG 10.2.1
)
FetchContent_MakeAvailable(fmt)
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)
target_include_directories(${PROJECT_NAME} PRIVATE ${FMT_UNCLUDE_DIR})

FetchContent_Declare(SFML
    GIT_REPOSITORY "https://github.com/SFML/SFML.git"
    GIT_TAG 2.6.0)
FetchContent_MakeAvailable(SFML)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics sfml-window sfml-system)
target_include_directories(${PROJECT_NAME} PRIVATE ${SFML_INCLUDE_DIR})


#DLL file for SFML
if(WIN32)
    add_custom_command(
        TARGET ${PROJECT_NAME}
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:${PROJECT_NAME}>
        VERBATIM)
endif()
install(TARGETS ${PROJECT_NAME})


#CMake VSCODE plugin setup
include(CTest)
enable_testing()
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)