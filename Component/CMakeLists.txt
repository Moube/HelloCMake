cmake_minimum_required(VERSION 3.8)     # 设置CMake版本号
project(Component)                      # 项目名称为 Component

# 添加所有的子目录到 ComponentAllSubDir 变量中
list(APPEND ComponentAllSubDir "Hello")
list(APPEND ComponentAllSubDir "Another")

# 遍历每个组件目录. 调用生成
foreach(dirname ${ComponentAllSubDir})
    add_subdirectory(${dirname})
endforeach()

