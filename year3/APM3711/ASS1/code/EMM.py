import numpy as np
import pandas as pd

# Define the differential equation
def f(x, y):
    return -3 * x**2 * y**2

# Analytical solution
def y_exact(x):
    return 2 / (2 * x**3 + 1)

# Modified Euler method with 2 corrections
def modified_euler(h):
    x_vals = np.arange(0, 1 + h, h)
    y_vals = [2]  # initial condition y(0) = 2
    errors = [0]  # initial error is 0

    for i in range(1, len(x_vals)):
        x_i = x_vals[i - 1]
        y_i = y_vals[-1]

        # Predictor
        y_p = y_i + h * f(x_i, y_i)

        # Corrector 1
        y_c1 = y_i + (h / 2) * (f(x_i, y_i) + f(x_i + h, y_p))

        # Corrector 2
        y_next = y_i + (h / 2) * (f(x_i, y_i) + f(x_i + h, y_c1))

        # Calculate true value and error
        true_val = y_exact(x_vals[i])
        error = abs(true_val - y_next)

        # Store result
        y_vals.append(y_next)
        errors.append(error)

    df = pd.DataFrame({
        'x': x_vals,
        'y_numeric': y_vals,
        'y_exact': y_exact(x_vals),
        'error': errors
    })
    return df

# Run the method with h = 0.2 and h = 0.1
df_h_02 = modified_euler(0.2)
df_h_01 = modified_euler(0.1)

import ace_tools as tools; tools.display_dataframe_to_user(name="Modified Euler (h = 0.2)", dataframe=df_h_02)
tools.display_dataframe_to_user(name="Modified Euler (h = 0.1)", dataframe=df_h_01)
