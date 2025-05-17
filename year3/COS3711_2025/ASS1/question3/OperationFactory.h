#ifndef OPERATIONFACTORY_H
#define OPERATIONFACTORY_H

#include "Operation.h"
#include <QString>

class OperationFactory {
public:
    static OperationFactory& instance();
    Operation* create(const QString& opSymbol) const;

private:
    OperationFactory() = default;
};

#endif // OPERATIONFACTORY_H