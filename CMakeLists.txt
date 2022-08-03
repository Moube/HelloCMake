cmake_minimum_required(VERSION 3.8) # 版本号
project(AllProject)                 # 项目名

# 启用VS解决方案文件夹
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# 设置Component与Libraries路径
set(PROJECT_COMPONENT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Component)
set(PROJECT_LIBRARIES_DIR ${CMAKE_CURRENT_SOURCE_DIR}/Libraries)

# 添加所有需要的子目录到 allSubDir
list(APPEND allSubDir "Component")
list(APPEND allSubDir "Libraries")
list(APPEND allSubDir "MainApp")
list(APPEND allSubDir "AnotherApp")

# 遍历生成
foreach(dirname ${allSubDir})
    add_subdirectory(${dirname})
endforeach()

# 最终生成的项目文件. 会有 ALL_BUILD 和 ZERO_CHECK. 将它们放置在 Other 文件夹下
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "Other")