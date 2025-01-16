#!/bin/bash

# 设置项目名称和目标文件夹
PROJECT_NAME="test"
EXECUTABLE="${PROJECT_NAME}"

# 查找所有的.cpp和.h文件
CPP_FILES=$(find . -type f -name "*.cpp")
HEADER_FILES=$(find . -type f -name "*.h")

echo ${CPP_FILES}

g++ -std=c++20 -g -Wall -Werror ${CPP_FILES} -o test && ./test