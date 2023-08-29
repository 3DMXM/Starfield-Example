# CMakeLists

# CMake 最低版本号要求
cmake_minimum_required(VERSION 3.26.1)

# 项目信息
project(StarfieldNativeTrainer VERSION 1.0.0 LANGUAGES C CXX)

# 指定为C++17 版本
set(CMAKE_CXX_STANDARD 17)

include(CTest)
enable_testing()

# 查找目录下的所有源文件
# 并将名称保存到 DIR_SRCS 变量
aux_source_directory(src/ DIR_SRCS)

# 引入 include 目录
include_directories(${CMAKE_SOURCE_DIR}/include)

# 引入 src/lib 中的 *.lib 文件
link_directories(${CMAKE_SOURCE_DIR}/lib)

# 指定生成目标 第一个参数为你需要构建的dll的名字，第二个为类型
add_library(StarfieldNativeTrainer SHARED ${DIR_SRCS})

# target_link_libraries(StarfieldNativeTrainer PRIVATE MinHook.x64.lib)

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
