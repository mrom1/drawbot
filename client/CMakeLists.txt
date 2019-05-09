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

add_executable(client main.cpp QImageController.cpp QImageController.h QImageItem.cpp QImageItem.h ImageProvider.cpp ImageProvider.h ${QT_RESOURCES})

target_link_libraries(client
    Qt5::Widgets
    Qt5::Qml
    Qt5::Quick
    ${OpenCV_LIBS}
    )
