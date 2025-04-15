import numpy as np

# Define system functions
def U(t, x0, x1, x2, x3):
    return x2

def V(t, x0, x1, x2, x3):
    return x3

def W(t, x0, x1, x2, x3):
    return (t + 1) * x0 * x1 - x3 + np.cos(t)

def X(t, x0, x1, x2, x3):
    return x2 + x0 * x1

# Initial values
h = 0.2
tn = 0

x0n = 2
x2n = 1
x1n = 3
x3n = -1

# Compute k1 values
kx0 = h * U(tn, x0n, x1n, x2n, x3n)
kx1 = h * V(tn, x0n, x1n, x2n, x3n)
kx2 = h * W(tn, x0n, x1n, x2n, x3n)
kx3 = h * X(tn, x0n, x1n, x2n, x3n)

# Intermediate step values for k2
t_half = tn + (3/2)*h
u_half = x0n + (3/2)*kx0
v_half = x1n + (3/2)*kx1
up_half = x2n + (3/2)*kx2
vp_half = x3n + (3/2)*kx3

# Compute k2 values
kx0_2 = h * U(t_half, u_half, v_half, up_half, vp_half)
kx1_2 = h * V(t_half, u_half, v_half, up_half, vp_half)
kx2_2 = h * W(t_half, u_half, v_half, up_half, vp_half)
kx3_2 = h * X(t_half, u_half, v_half, up_half, vp_half)

# Final values using weighted combination
x0_02 = x0n + (2/3)*kx0 + (1/3)*kx0_2
x1_02 = x1n + (2/3)*kx1 + (1/3)*kx1_2
x2_02 = x2n + (2/3)*kx2 + (1/3)*kx2_2
x3_02 = x3n + (2/3)*kx3 + (1/3)*kx3_2

x0_02, x1_02, x2_02, x3_02
