cmake_minimum_required(VERSION 3.16)

project(massiv VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick Qml Widgets)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appmassiv
    main.cpp
    matrixmanager.cpp
    matrixmanager.h
    mainwindow.cpp
    mainwindow.h
)

set(UI_FILES
    mainwindow.ui
)

qt6_wrap_ui(UI_HEADERS ${UI_FILES})

set_target_properties(appmassiv PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_include_directories(appmassiv PRIVATE ${CMAKE_BINARY_DIR})
target_sources(appmassiv PRIVATE ${UI_HEADERS})

target_link_libraries(appmassiv
    PRIVATE Qt6::Quick
    Qt6::Qml
    Qt6::Widgets
)

include(GNUInstallDirs)
install(TARGETS appmassiv
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
