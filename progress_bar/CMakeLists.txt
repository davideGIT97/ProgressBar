cmake_minimum_required(VERSION 3.24)
project(progress_bar)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)

find_package(Qt6Widgets REQUIRED)

add_executable(progress_bar main.cpp File.h Subject.h Observer.h Loader.h Loader.cpp MainWindow.h MainWindow.cpp CustomException.h)


target_link_libraries(progress_bar Qt::Widgets)

