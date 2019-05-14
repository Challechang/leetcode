cmake_minimum_required(VERSION 3.7)
project(leetcode)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Solution.cpp Solution.h)
add_executable(leetcode ${SOURCE_FILES})

set(TENCENT_ARRAY_STRING tencent/array_string/Solution.cpp tencent/array_string/Solution.h)
add_executable(tencent_array_string ${TENCENT_ARRAY_STRING})

file(GLOB_RECURSE HUAWEI ${PROJECT_SOURCE_DIR}/huawei/*.cpp)

foreach (FILE ${HUAWEI})
    get_filename_component(RELATIVE_NAME ${FILE} NAME_WE)
    add_executable(${RELATIVE_NAME} ${FILE})
endforeach ()