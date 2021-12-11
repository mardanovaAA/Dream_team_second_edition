cmake_minimum_required(VERSION 3.16)
project(life-like_cellular_automaton)

set(CMAKE_CXX_STANDARD 17)

set(APP_USABLES usables/)
include_directories(${APP_USABLES})

set(SOURCE_FILES
        headers/Automaton.h headers/Rules.h headers/Cell.h src/Rules.cpp src/Automaton.cpp headers/AutomatonView.h src/AutomatonView.cpp src/Cell.cpp)


add_executable(life-like_cellular_automaton
        main.cpp
        src/App.cpp
        headers/App.h

        ${SOURCE_FILES}
        )

# include SFML

include_directories(headers /usr/include D:/Me/MIPT/SFML-2.5.1/include)

if (WIN32)
set(SFML_DIR ../SFML-2.5.1/lib/cmake/SFML)
file(GLOB BINARY_DEP_DLLS "../SFML-2.5.1/bin/*.dll")
file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)

target_link_libraries(life-like_cellular_automaton sfml-graphics sfml-audio)