import numpy as np
# from sympy import *
import sympy as sym

# define what is the variable
x = sym.symbols('x')
# define the function
# f(x) = x^2 - 4x-5
f = x**2-4*x-5


xn = 1
for i in range(10):
    xn = xn - float(f.evalf(subs= {x:xn})) / float(f.evalf(subs= {x:xn}))
    print(f'The {i+1} iteration xn is {xn:.2} and f(xn) is {float(f.evalf(subs= {x:xn})):.2}')