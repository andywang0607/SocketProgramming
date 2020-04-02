cmake_minimum_required(VERSION "3.7.1")
SET(CMAKE_C_COMPILER C:/MinGW/bin/gcc.exe)

project("ClientSocket")


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)



add_executable(ClientSocket ClientSocket.cpp)



if(WIN32)
  target_link_libraries(ClientSocket WS2_32)

endif()


project("ServerSocket")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)


add_executable(ServerSocket ServerSocket.cpp)
if(WIN32)
  target_link_libraries(ServerSocket WS2_32)

endif()

