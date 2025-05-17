#ifndef OPERATIONFACTORY_H
#define OPERATIONFACTORY_H

#include "Operation.h"
#include <QString>
#include <memory>

class OperationFactory {
public:
    static OperationFactory& instance();
    std::unique_ptr<Operation> create(const QString& op) const;

private:
    OperationFactory() = default;
};

#endif // OPERATIONFACTORY_H