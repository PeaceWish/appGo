cmake_minimum_required(VERSION 3.16)
project(appGo VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# 添加Qt6的安装路径
list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew/opt/qt@6")

# 设置包含路径
include_directories(${CMAKE_SOURCE_DIR}/src)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets Network Sql)

# 添加源文件
set(SOURCES
    src/main.cpp
    src/mainwindow.cpp
    src/widgets/appcard.cpp
    src/widgets/appgridview.cpp
    src/widgets/paginationwidget.cpp
)

# 添加头文件
set(HEADERS
    src/mainwindow.h
    src/widgets/appcard.h
    src/widgets/appgridview.h
    src/widgets/paginationwidget.h
)

add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    Qt6::Network
    Qt6::Sql
) 