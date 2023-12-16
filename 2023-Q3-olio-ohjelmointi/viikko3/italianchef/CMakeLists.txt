cmake_minimum_required(VERSION 3.25)
project(QtTesti)

set(CMAKE_CXX_STANDARD 20)

set(QT6_PREFIX "C:/Qt_os/6.5.2/msvc2019_64" CACHE PATH "Qt6 Prefix")

list(APPEND CMAKE_MODULE_PATH ${QT6_PREFIX})

find_package(Qt6 REQUIRED COMPONENTS Core)
# This also handles setting CMAKE_AUTOMOC to true
qt_standard_project_setup()
qt_add_executable(QtTesti
        main.cpp
	cheffi.cpp
)
target_link_libraries(QtTesti PRIVATE Qt6::Core)
