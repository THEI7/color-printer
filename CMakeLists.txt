cmake_minimum_required(VERSION 3.22)
project(color_printer)

set(CMAKE_CXX_STANDARD 20)

include_directories("include")

add_library(color_printer SHARED
    src/color_printer.cpp
)

install(TARGETS color_printer
    EXPORT ${PROJECT_NAME}
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)