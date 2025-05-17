cmake_minimum_required(VERSION 3.16)
project(CalculatorApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(CalculatorApp
    main.cpp
    Operation.cpp
    OperationFactory.cpp
    CalculatorWindow.cpp
)

target_link_libraries(CalculatorApp Qt6::Widgets)
