# https://en.wikipedia.org/wiki/Successive_over-relaxation
import pandas as pd
import numpy as np

seperator = '-----------------------------------------------------'
num_arr = [0,1,2,3]

def printArray(A, b, precision):
    Ab=np.array([np.array(xi) for xi in A])
    df=pd.DataFrame(data=A[0:,0:],
                    index=[i+1 for i in range(A.shape[0])],
                    columns=['x'+str(i+1) for i in range(A.shape[1])])

    df['b'] = b
    pd.set_option("display.precision", precision)
    if (precision > 2):
        pd.set_option('display.float_format', lambda x: "{0:0.4f}".format(x))
    print(df)

def sor_solver(A, b, omega, initial_guess, convergence_criteria):
    """
    This is an implementation of the pseudo-code provided in the Wikipedia article.
    Arguments:
        A: nxn numpy matrix.
        b: n dimensional numpy vector.
        omega: relaxation factor.
        initial_guess: An initial solution guess for the solver to start with.
        convergence_criteria: The maximum discrepancy acceptable to regard the current solution as fitting.
    Returns:
        phi: solution vector of dimension n.
    """
    step = 0
    phi = initial_guess[:]
    residual = np.linalg.norm(np.matmul(A, phi) - b)  # Initial residual
    while residual > convergence_criteria:

        print(f"iteration {step +1 } : {seperator}")
        for i in range(A.shape[0]):
            sigma = 0
            num_arr.remove(i) 
            for j in range(A.shape[1]):
                if j != i:
                    sigma += A[i, j] * phi[j]
            phi[i] = (1 - omega) * phi[i] + (omega / A[i, i]) * (b[i] - sigma)

            print(f"x_{i+1} = (1 - {omega}) × ??? + ({omega} / {A[i, i]})[{b[i]} - {A[i][num_arr[0]]} × {round(phi[num_arr[0]],5)} -{A[i][num_arr[1]]} × {round(phi[num_arr[1]],5)}- {A[i][num_arr[2]]} × {round(phi[num_arr[2]],5)}] = {round(phi[i],5)}") 
            num_arr.append(i)
            num_arr.sort()        
        residual = np.linalg.norm(np.matmul(A, phi) - b)
        step += 1
        # print("Step {} Residual: {:10.6g}".format(step, residual))
        
    return phi

def getInputA():    
    # initialize the matrix
    # a = np.array([
    #     [0.05, 0.07, 0.06, 0.05],
    #     [0.07, 0.10, 0.08, 0.07],
    #     [0.06, 0.08, 0.10, 0.09],
    #     [0.05, 0.07, 0.09, 0.10],
    # ], dtype=float)
    a = np.array([
        [0.06, 0.08, 0.07, 0.08],
        [0.08, 0.20, 0.09, 0.07],
        [0.07, 0.09, 0.20, 0.10],
        [0.06, 0.08, 0.10, 0.20],
    ], dtype=float)
    # a = np.array([
    #     [2.141, -2.718, 1.414, -1.732],
    #     [9.869, 2.718, -7.389, 0.428],
    #     [2.236, -2.449, 1, -1.414],
    #     [31.006, 7.389, -2.645, 0.111],
    # ], dtype=float)
    return a

def getInputB():
    # initialize the RHS vector
    # b = np.array([0.23, 0.32, 0.33, 0.31], dtype=float)
    # b = np.array([3.316, 0 , 3.141, 1.414], dtype=float)
    b = np.array([0.29, 0.44, 0.46, 0.44], dtype=float)
    return b



if __name__ == "__main__":
    A = getInputA()
    b = getInputB()
    printArray(A, b, 2)
    print()
    # An example case that mirrors the one in the Wikipedia article
    residual_convergence = 1e-8
    omega = 0.5  # Relaxation factor
    initial_guess = np.zeros(4)
    phi = sor_solver(A, b, omega, initial_guess, residual_convergence)
    print(phi)

