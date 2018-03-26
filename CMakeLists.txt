cmake_minimum_required(VERSION 3.0.0 FATAL_ERROR)

project(SFINAETest)
set(CMAKE_CXX_STANDARD 11)

find_package(Boost REQUIRED)

add_executable(app main.cpp)
target_include_directories(app PUBLIC
	${Boost_INCLUDE_DIR}
)
target_link_libraries(app
	${BOOST_LIBRARIES}
)
