#include "Operation.h"
#include <stdexcept>

double Addition::compute(double a, double b) const {
    return a + b;
}

double Subtraction::compute(double a, double b) const {
    return a - b;
}

double Multiplication::compute(double a, double b) const {
    return a * b;
}

double Division::compute(double a, double b) const {
    if (b == 0.0) throw std::runtime_error("Division by zero");
    return a / b;
}