#https://en.wikipedia.org/wiki/Jacobi_method
import numpy as np
import pandas as pd

ITERATION_LIMIT = 4
num_arr = [0,1,2,3]
seperator = '-----------------------------------------------------'

def printArray(A, b, precision):
    df=pd.DataFrame(data=A[0:,0:],
                    index=[i+1 for i in range(A.shape[0])],
                    columns=['x'+str(i+1) for i in range(A.shape[1])])

    df['b'] = b
    pd.set_option("display.precision", precision)
    if (precision > 2):
        pd.set_option('display.float_format', lambda x: "{0:0.4f}".format(x))
    print(df)

def getInputA():    
    # initialize the matrix
    A = np.array([[0.05, 0.07, 0.06, 0.05],
                [0.07, 0.10, 0.08, 0.07],
                [0.06, 0.08, 0.10, 0.09],
                [0.05, 0.07, 0.09, 0.10]])
    return A

def getInputB():
    # initialize the RHS vector
    b = np.array([0.23, 0.32, 0.33, 0.31])
    return b

def diagDominant(A):
    D = np.diag(np.abs(A)) # Find diagonal coefficients
    S = np.sum(np.abs(A), axis=1) - D # Find row sum without diagonal
    if np.all(D > S):
        print('matrix is diagonally dominant')
    else:
        print('NOT diagonally dominant')

def jacobiMethod(A, b):
    x = np.zeros_like(b)
    ans_arr = []
    for it_count in range(ITERATION_LIMIT):
        if it_count != 0:
            print(seperator)
            print(f"Iteration {it_count}:\n")
        x_new = np.zeros_like(x)
        
        ans_arr.append(x)
        for i in range(A.shape[0]):
            # lower triangle of matrix A[i, :i]
            # upper triangle of matrix A[i, i + 1:]
            s1 = np.dot(A[i, :i], x[:i])
            s2 = np.dot(A[i, i + 1:], x[i + 1:])

            temp_arr = list(A[i, :i])+ list(A[i, i + 1:])
            num_arr.remove(i)
            if it_count != 0:
                print(f"x_{i+1} = 1/{A[i,i]}  [{b[i]}  - {temp_arr[0]} × {round(ans_arr[it_count-1][num_arr[0]],5)} - {temp_arr[1]} × {round(ans_arr[it_count-1][num_arr[1]],5)} - {temp_arr[2]} × {round(ans_arr[it_count-1][num_arr[2]],5)} ] = {round(x[i],5)}")
            x_new[i] = (b[i] - s1 - s2) / A[i, i]
            num_arr.append(i)
            num_arr.sort()

            if x_new[i] == x_new[i-1]:
                break

        if np.allclose(x, x_new, atol=1e-10, rtol=0.):
            break
        x = x_new
    return (x)

if __name__ == "__main__":
    A = getInputA()    
    b = getInputB()
    diagDominant(A)

    printArray(A, b, 2)
    x = jacobiMethod(A, b)
    print(seperator)
    print("Solution:")
    print(x)
    error = np.dot(A, x) - b
    print("Error:")
    print(error)