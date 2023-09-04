# CMakeLists

# CMake 最低版本号要求
cmake_minimum_required(VERSION 3.26.1)

# 配置 vcpkg
set(CMAKE_PREFIX_PATH "E:\\GitHub\\vcpkg\\packages")

# 项目信息
project(Example VERSION 1.0.0 LANGUAGES C CXX)

# 指定为C++17 版本
set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

# 查找目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(src DIR_SRCS)

# # 添加 子文件夹中的文件
# set(DIR_IMGUI
# "${CMAKE_SOURCE_DIR}/src/imgui/imgui_impl_dx11.cpp"
# "${CMAKE_SOURCE_DIR}/src/imgui/imgui_impl_win32.cpp"
# "${CMAKE_SOURCE_DIR}/src/Sntui/Sntui.cpp"
# )

# 引入 include 目录
include_directories(${CMAKE_SOURCE_DIR}/include)

# 引入 lib 中的 *.lib 文件
link_directories(${CMAKE_SOURCE_DIR}/lib)

# 指定生成目标 第一个参数为你需要构建的dll的名字，第二个为类型 后面为 *.cpp文件
add_library(Example SHARED ${DIR_SRCS} ${DIR_IMGUI})

# 从系统文件中引入 d3d11.lib
target_link_libraries(Example PUBLIC d3d11)

# # 引入 imgui
# find_package(imgui CONFIG REQUIRED)
# target_link_libraries(Example PRIVATE imgui::imgui)

# # 引入 minhook
# find_package(minhook CONFIG REQUIRED)
# target_link_libraries(Example PRIVATE minhook::minhook)

# # 引入 spdlog
# find_package(spdlog CONFIG REQUIRED)
# target_link_libraries(Example PRIVATE spdlog::spdlog)

# add_library(${PROJECT_NAME} )
set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

# 配置导出目录
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY out)

# 为dll设置linker
# 指定dll的生成目录，这里是：./out
SET_TARGET_PROPERTIES(${CPACK_PROJECT_NAME} PROPERTIES LINKER_LANGUAGE C
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
    LIBRARY_OUTPUT_DIRECTORY ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
    OUTPUT_NAME ${CPACK_PROJECT_NAME}
    PREFIX ""
    SUFFIX ".asi")