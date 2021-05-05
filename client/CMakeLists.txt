###########################################################################
## This file is part of the minilockcpp distribution 
## (https://github.com/mrom1/minilockcpp).
## Copyright (c) 2021 mrom1.
##
## This program is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation, version 3.
##
## This program is distributed in the hope that it will be useful, but
## WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
## General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program. If not, see <http://www.gnu.org/licenses/>.
###########################################################################



###########################################################################
## Drawbot Client GUI
###########################################################################
find_package(Qt5 COMPONENTS Widgets Qml Core Quick REQUIRED)
find_package(OpenCV REQUIRED)

include_directories(
    ${Qt5Widgets_INCLUDE_DIRS}
    ${QtQml_INCLUDE_DIRS}
    ${OpenCV_INCLUDE_DIRS})

add_definitions(${Qt5Widgets_DEFINITIONS} ${QtQml_DEFINITIONS} ${${Qt5Quick_DEFINITIONS}})
qt5_add_resources(QT_RESOURCES qml.qrc)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(client main.cpp 
    QImageController.cpp QImageController.h 
    QImageItem.cpp QImageItem.h 
    ImageProvider.cpp ImageProvider.h 
    ${QT_RESOURCES})

target_link_libraries(client
    Qt5::Widgets
    Qt5::Qml
    Qt5::Quick
    ${OpenCV_LIBS}
    )
