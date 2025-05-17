cmake_minimum_required(VERSION 3.16)
project(BankingApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)


find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(BankingApp
    main.cpp
    MainWindow.cpp
    Transaction.cpp
    TransactionList.cpp
    MainWindow.h
    Transaction.h
    TransactionList.h
)


target_link_libraries(BankingApp Qt6::Widgets)
