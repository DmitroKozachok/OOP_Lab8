cmake_minimum_required(VERSION 3.16)

project(Lab8 LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Multimedia)

qt_standard_project_setup()

qt_add_executable(Lab8
    main.cpp
    mainwindow.h
    mainwindow.cpp
    mainwindow.ui
    track.h
    track.cpp
    localtrack.h
    localtrack.cpp
    streamtrack.h
    streamtrack.cpp
    playlist.h
    playlist.cpp
    player.h
    player.cpp
)

target_link_libraries(Lab8
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Multimedia
)
