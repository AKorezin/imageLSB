cmake_minimum_required(VERSION 2.8)

project(imageLSB)
set (HEADERS 
	src/CImg.h)
 
set (SOURCES 
	src/main.cpp)

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PUBLIC pthread)
