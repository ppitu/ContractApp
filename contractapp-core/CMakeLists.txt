cmake_minimum_required(VERSION 3.14)

project(contractapp-core LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Core REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Sql REQUIRED)

add_library(contractapp-core SHARED
  contractapp-core_global.h
  Class/Person.cpp
  Class/Person.h
  Database/DatabaseManager.h Database/DatabaseManager.cpp DatabaseClass/PersonDao.h DatabaseClass/PersonDao.cpp Model/PersonModel.h Model/PersonModel.cpp
  Class/Pattern.h Class/Pattern.cpp DatabaseClass/PatternDao.h DatabaseClass/PatternDao.cpp Model/PatternModel.h Model/PatternModel.cpp
)

target_link_libraries(contractapp-core PRIVATE Qt${QT_VERSION_MAJOR}::Core)
target_link_libraries(contractapp-core PRIVATE Qt${QT_VERSION_MAJOR}::Sql)

target_compile_definitions(contractapp-core PRIVATE CONTRACTAPPCORE_LIBRARY)
