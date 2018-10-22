cmake_minimum_required(VERSION 2.8)
project(stream_client)

# Variables
set(SOURCES_DIR src)
set(HEADERS_DIR src)
set(LIBS_DIR libs)

# Qt flags
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

set (SOURCES
    ${SOURCES_DIR}/main.cpp
    ${SOURCES_DIR}/streamclientmanager.cpp
    ${SOURCES_DIR}/ui/widgets/ipinputbox.cpp
    ${SOURCES_DIR}/ui/subpanels/addresssubpanel.cpp
    )

set (HEADERS
    ${HEADERS_DIR}/streamclientmanager.hpp
    ${HEADERS_DIR}/ui/widgets/ipinputbox.hpp
    ${HEADERS_DIR}/ui/subpanels/addresssubpanel.hpp
    )

# App
add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    )
include_directories(${HEADERS_DIR})

# Qt
find_package(Qt5Widgets REQUIRED)
target_link_libraries(${PROJECT_NAME} Qt5::Widgets)

# Vlc-qt
set(VLCQT_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(VLCQT_BUILD_TESTS OFF CACHE BOOL "" FORCE)
add_subdirectory(${LIBS_DIR}/vlc-qt)
target_link_libraries(${PROJECT_NAME} Core)
include_directories(${CMAKE_BINARY_DIR}/${LIBS_DIR}/vlc-qt/include)
