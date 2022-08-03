#对于其他组件,只需要按需求改:
#项目名称. 头文件目录. 连接库目录. 链接库即可(拷贝过去修改使用)
#不建议复制该文件,学习使用注释较多
#建议复制Another/CmakeLists.txt 删除了注释简洁干净

cmake_minimum_required(VERSION 3.8)     #指定CMake版本号
project(Hello)                          #指定项目名
option(GROUP_BY_EXPLORER ON)            # 启用文件结构与资源管理器保持一致
option(USE_SOLUTION_FOLDERS ON)         # 启用VS项目文件夹分类
set(CMAKE_CXX_STANDARD 11)              #设置c++版本

#递归查找文件夹下的.h .hpp .ini文件并保存到 HEAD_FILES
file(GLOB_RECURSE HEADER_FILES *.h *.hpp *.ini)

#递归查找文件夹下的.cpp .c文件并保存到 SOURCE_FILES
file(GLOB_RECURSE SOURCE_FILES *.cpp *.c)

#递归查找文件夹下的.hlsl文件并保存到 SHADER_FILES
file(GLOB_RECURSE SHADER_FILES *.hlsl)

set(CppFile ${HEADER_FILES} ${SOURCE_FILES})
set(AllFile ${CppFile} ${SHADER_FILES})

foreach(fileItem ${AllFile})
    # Get the directory of the source file
    # 获得source文件的路径, 输出到PARENT_DIR变量中
    get_filename_component(PARENT_DIR "${fileItem}" DIRECTORY)
    # Remove common directory prefix to make the group
    # 移除PARENT_DIR目录前缀, 仅留下相对目录下各个文件的路径, 输出到GROUP变量中
    string(REPLACE "${CMAKE_CURRENT_SOURCE_DIR}" "" GROUP "${PARENT_DIR}")
    # Make sure we are using windows slashes
    # 将GROUP反斜杠替换成斜杠, 输出到GROUP变量中
    string(REPLACE "/" "\\" GROUP "${GROUP}")
    # Group into "Source Files" and "Header Files"
    set(GROUP "${GROUP}")
    source_group("${GROUP}" FILES "${fileItem}")
endforeach()

# 将 AllFile 里面的所有文件编译为 Hello 静态库
add_library(${PROJECT_NAME} ${AllFile})

# 设置 Hello 为 Component 文件夹下
set_target_properties(${PROJECT_NAME} PROPERTIES FOLDER "Component")

# 设置 hlsl 为 shader 资源文件. 不让 VS 编译它们
set_property(SOURCE ${SHADER_FILES} PROPERTY VS_TOOL_OVERRIDE "shader")

# 设置程序工作目录为 cmake 工作目录
set_property(TARGET ${PROJECT_NAME} PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

# 头文件目录
target_include_directories(${PROJECT_NAME} PUBLIC
    ${PROJECT_COMPONENT_DIR}
)

# 链接库 (如果有才需要)
#target_link_libraries(${PROJECT_NAME} PUBLIC 
#    GameTimer
#    Exception
#)

# 链接库目录 (如果有才需要)
# target_link_directories(${PROJECT_NAME} PUBLIC
#   ... 
# )