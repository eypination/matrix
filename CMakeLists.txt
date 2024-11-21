cmake_minimum_required(VERSION 3.16)

# Название проекта
project(massiv VERSION 0.1 LANGUAGES CXX)

# Установить стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Найти необходимые модули Qt
find_package(Qt6 6.5 REQUIRED COMPONENTS Quick Qml Widgets)

# Стандартная настройка проекта
qt_standard_project_setup(REQUIRES 6.5)

# Добавить исполняемый файл
qt_add_executable(appmassiv
    main.cpp
    matrixmanager.cpp
    matrixmanager.h
    mainwindow.cpp
    mainwindow.h
)

# Указать файл UI
set(UI_FILES
    mainwindow.ui
)

# Генерация UI-заголовков
qt6_wrap_ui(UI_HEADERS ${UI_FILES})

# Установить свойства целевого файла
set_target_properties(appmassiv PROPERTIES
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_include_directories(appmassiv PRIVATE ${CMAKE_BINARY_DIR})
target_sources(appmassiv PRIVATE ${UI_HEADERS})

# Линковка с модулями Qt
target_link_libraries(appmassiv
    PRIVATE Qt6::Quick
    Qt6::Qml
    Qt6::Widgets
)

# Установка
include(GNUInstallDirs)
install(TARGETS appmassiv
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
