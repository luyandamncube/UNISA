import numpy as np
import pandas as pd
import argparse

def get_equations(key: str):
    """
    Maps keywords to specific differential equations and analytical solutions.
    """
    if key.lower() == "assignment1":
        def f(x, y):
            return -3 * x**2 * y**2
        def y_exact(x):
            return 2 / (2 * x**3 + 1)
        return f, y_exact
    else:
        raise ValueError(f"Unknown equation keyword: {key}")

def run_modified_euler(f, y_exact, h: float, y0: float = 2.0, x_end: float = 1.0) -> pd.DataFrame:
    x_vals = np.arange(0, x_end + h, h)
    y_vals = [y0]
    errors = [0]
    f_xy_vals = [f(0, y0)]
    y_p_vals = [np.nan]
    f_new_vals = [np.nan]
    y_new_vals = [y0]

    for i in range(1, len(x_vals)):
        x_i = x_vals[i - 1]
        y_i = y_vals[-1]

        f_xy = f(x_i, y_i)
        y_p = y_i + h * f_xy
        y_c1 = y_i + (h / 2) * (f_xy + f(x_i + h, y_p))
        y_next = y_i + (h / 2) * (f_xy + f(x_i + h, y_c1))
        f_new = f(x_i + h, y_c1)
        true_val = y_exact(x_vals[i])
        error = abs(true_val - y_next)

        y_vals.append(y_next)
        errors.append(error)
        f_xy_vals.append(f_xy)
        y_p_vals.append(y_p)
        f_new_vals.append(f_new)
        y_new_vals.append(y_next)

    return pd.DataFrame({
        'x': x_vals,
        'y': y_vals,
        'Exact y': y_exact(x_vals),
        'Error': errors,
        'f(x,y)': f_xy_vals,
        'yp': y_p_vals,
        'fnew': f_new_vals,
        'ynew': y_new_vals
    })

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Modified Euler Method with 2 corrections")

    parser.add_argument('--equation', type=str, required=True,
                        help="Choose a predefined equation, e.g., 'assignment1'")
    parser.add_argument('--step-size', type=float, required=True,
                        help="Step size (e.g. 0.1)")
    parser.add_argument('--y0', type=float, default=2.0, help="Initial y value (default: 2.0)")
    parser.add_argument('--x-end', type=float, default=1.0, help="Final x value (default: 1.0)")

    args = parser.parse_args()

    f, y_exact = get_equations(args.equation)

    df = run_modified_euler(f, y_exact, args.step_size, args.y0, args.x_end)

    print(df.to_string(index=False))
