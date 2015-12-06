cmake_minimum_required(VERSION 2.8)

project(imageLSB)
#set (HEADERS
#src/CImg.h
#src/options.h
#)
 
#set (SOURCES
#src/main.cpp
#src/options.cpp
#)

file(GLOB SOURCES
src/*.cpp
)
file(GLOB HEADERS
src/*.h
)


add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PUBLIC pthread png jpeg)
add_definitions(-Dcimg_display=0 -Dcimg_use_png -Dcimg_use_jpeg -Dcimg_use_openmp)
