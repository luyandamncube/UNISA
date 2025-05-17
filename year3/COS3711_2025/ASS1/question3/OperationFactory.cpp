#include "OperationFactory.h"

OperationFactory& OperationFactory::instance() {
    static OperationFactory factory;
    return factory;
}

std::unique_ptr<Operation> OperationFactory::create(const QString& op) const {
    if (op == "+") return std::make_unique<Addition>();
    if (op == "-") return std::make_unique<Subtraction>();
    if (op == "*") return std::make_unique<Multiplication>();
    if (op == "/") return std::make_unique<Division>();
    return nullptr;
}