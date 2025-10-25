cmake_minimum_required(VERSION 3.22)
project(color_printer)

set(CMAKE_CXX_STANDARD 20)

include_directories("include")

add_library(color_printer SHARED
    src/color_printer.cpp
)


# 添加测试用的程序
add_executable(color_printer_test src/colorPinterTest.cpp)

target_link_libraries(color_printer_test PUBLIC color_printer)

target_include_directories(color_printer_test PUBLIC include/)

# 安装测试程序
install(TARGETS color_printer_test
        RUNTIME DESTINATION bin
)

# 安装库
install(TARGETS color_printer
    EXPORT ${PROJECT_NAME}
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

# 安装头文件
install(DIRECTORY include/
    DESTINATION include
    FILES_MATCHING PATTERN "*.h"
)

message(STATUS "CMAKE_INSTALL_PREFIX--${CMAKE_INSTALL_PREFIX}")

# 生成包配置文件
include(CMakePackageConfigHelpers)

# 写入包版本文件
write_basic_package_version_file(
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
    VERSION 1.0.0
    COMPATIBILITY SameMajorVersion
)

# 配置包配置文件
configure_package_config_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/${PROJECT_NAME}Config.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    INSTALL_DESTINATION lib/cmake/${PROJECT_NAME}
)

# 安装包配置文件
install(FILES
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
    DESTINATION lib/cmake/${PROJECT_NAME}
)

# 安装导出目标
install(EXPORT ${PROJECT_NAME}
    FILE ${PROJECT_NAME}Targets.cmake
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION lib/cmake/${PROJECT_NAME}
)