cmake_minimum_required(VERSION 3.0)

project(net)

# Specify the required C++ standard
if(CMAKE_VERSION GREATER "3.1.2")
    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    set(CMAKE_CXX_EXTENSIONS OFF)
else()
    if(CMAKE_COMPILER_IS_GNUCXX)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
    endif()
endif()

include_directories(include/)

add_executable(${CMAKE_PROJECT_NAME}
    src/Operation.cpp
    src/ops.cpp
    src/OperationList.cpp
    src/utils.cpp
    src/net.cpp
)
