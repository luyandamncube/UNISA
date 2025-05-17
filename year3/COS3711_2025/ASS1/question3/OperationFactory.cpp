#include "OperationFactory.h"

OperationFactory& OperationFactory::instance() {
    static OperationFactory factory;
    return factory;
}

Operation* OperationFactory::create(const QString& opSymbol) const {
    if (opSymbol == "+")
        return new Addition();
    else if (opSymbol == "-")
        return new Subtraction();
    else if (opSymbol == "*")
        return new Multiplication();
    else if (opSymbol == "/")
        return new Division();
    else
        return nullptr;
}