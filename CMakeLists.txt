cmake_minimum_required(VERSION 3.16)
cmake_minimum_required(VERSION 3.16)

project(ObjectGeorienteerdeTechnieken LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

qt_add_executable(ObjectGeorienteerdeTechnieken
    main.cpp
    mainwindow.cpp
    mainwindow.h
    shape.h
    circle.h
    rectangle.h
    drawingtool.h
    LICENSE.txt
    README.md
    .gitignore
)

target_link_libraries(ObjectGeorienteerdeTechnieken
    PRIVATE
        Qt6::Core
        Qt6::Gui
        Qt6::Widgets
)
