cmake_minimum_required(VERSION 3.8)
project(Binary_Tree)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c binaryTree.h)
add_executable(Binary_Tree ${SOURCE_FILES} binaryTree.h)