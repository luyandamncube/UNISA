#ifndef OPERATION_H
#define OPERATION_H

class Operation {
public:
    virtual ~Operation() = default;
    virtual double compute(double a, double b) const = 0;
};

class Addition : public Operation {
public:
    double compute(double a, double b) const override;
};

class Subtraction : public Operation {
public:
    double compute(double a, double b) const override;
};

class Multiplication : public Operation {
public:
    double compute(double a, double b) const override;
};

class Division : public Operation {
public:
    double compute(double a, double b) const override;
};

#endif // OPERATION_H