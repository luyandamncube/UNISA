cmake_minimum_required(VERSION 3.16)
project(StyledCalculatorApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_add_executable(StyledCalculatorApp
    main.cpp
    CalculatorWindow.cpp
    Operation.cpp
    OperationFactory.cpp

    CalculatorWindow.h
    OperationFactory.h
    FocusableSpinBox.h
)

target_link_libraries(StyledCalculatorApp PRIVATE Qt6::Widgets)
