cmake_minimum_required(VERSION 3.5)

project(contractapp VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# QtCreator supports the following variables for Android, which are identical to qmake Android variables.
# Check https://doc.qt.io/qt/deployment-android.html for more information.
# They need to be set before the find_package( ...) calls below.

#if(ANDROID)
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
#    if (ANDROID_ABI STREQUAL "armeabi-v7a")
#        set(ANDROID_EXTRA_LIBS
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libcrypto.so
#            ${CMAKE_CURRENT_SOURCE_DIR}/path/to/libssl.so)
#    endif()
#endif()

find_package(QT NAMES Qt6 Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets REQUIRED)
find_package(Qt6PrintSupport REQUIRED)

set(PROJECT_SOURCES
        main.cpp
        Widget/PersonWidget.cpp
        Widget/PersonWidget.h
        Widget/PersonWidget.ui
        Dialog/PersonDialog.h Dialog/PersonDialog.cpp Dialog/PersonDialog.ui
        MainWindow.cpp
        MainWindow.h
        MainWindow.ui
        Widget/ContractWidget.cpp Widget/ContractWidget.h Widget/ContractWidget.ui Widget/PersonDatabaseWidget.cpp Widget/PersonDatabaseWidget.h Widget/PersonDatabaseWidget.ui Widget/PatternWidget.cpp Widget/PatternWidget.h Widget/PatternWidget.ui)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(contractapp
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
else()
    if(ANDROID)
        add_library(contractapp SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(contractapp
            ${PROJECT_SOURCES}
        )
    endif()
endif()

include_directories("../contractapp-core")

target_link_libraries(contractapp PRIVATE contractapp-core)
target_link_libraries(contractapp PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(contractapp PRIVATE Qt6::PrintSupport)


set_target_properties(contractapp PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(contractapp)
endif()


