cmake_minimum_required(VERSION 3.30)
project(SDLTesting)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(external/SDL EXCLUDE_FROM_ALL)
add_subdirectory(external/SDL_image EXCLUDE_FROM_ALL)

add_executable(${PROJECT_NAME} main.cpp)

if (MSVC)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SUBSYSTEM:WINDOWS")
else()
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mwindows")
endif()

install(FILES $<TARGET_RUNTIME_DLLS:${PROJECT_NAME}> TYPE BIN)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2_image::SDL2_image SDL2::SDL2main SDL2::SDL2)