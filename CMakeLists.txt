cmake_minimum_required(VERSION 3.16)

project(PhysicsEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt automoc / autouic / autorcc
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# --- Qt ---
find_package(Qt6 REQUIRED COMPONENTS
    Widgets
    Gui
    OpenGL
    OpenGLWidgets
)

# --- Sources ---
include_directories(include)

set(PROJECT_SOURCES
    src/main.cpp
    src/engine.cpp
    include/engine.h
    ui/mainwindow.ui
    src/mainwindow.cpp
    include/mainwindow.h
)

set(CMAKE_AUTOUIC_SEARCH_PATHS ui)

# --- Executable ---
qt_add_executable(PhysicsEngine
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
    resources.qrc
)

target_include_directories(PhysicsEngine PRIVATE include)

# --- Link Qt ---
target_link_libraries(PhysicsEngine PRIVATE
    Qt6::Widgets
    Qt6::Gui
    Qt6::OpenGL
    Qt6::OpenGLWidgets
)

# --- Windows / macOS flags ---
set_target_properties(PhysicsEngine PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

qt_finalize_executable(PhysicsEngine)
