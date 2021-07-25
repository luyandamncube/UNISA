# https://www.geeksforgeeks.org/gauss-seidel-method/
import pandas as pd
import numpy as np

x = [0.00, 0.00, 0.00]  
ITERATION_LIMIT = 25
seperator = '-----------------------------------------------------'
num_arr = [0,1,2]
temp_arr = []

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

def seidel(a, x ,b):    
    n = len(a)                   
    for i in range(0, ITERATION_LIMIT):   
        print(f"iteration {i+1}: {seperator}")   
        for j in range(0, n):        
            d = b[j] 
            num_arr.remove(j)  
            for k in range(0, n):  
                if(j != k):
                    d-=a[j][k] * x[k]     
            x[j] = d / a[j][j]
            temp = b[j]
            if (j == 1 and i > 0):
                temp = x[0]
            print(f"x_{j+1} = 1/{a[j][j]} × ({round(temp,5)} - {a[j][num_arr[0]]} × {round(x[num_arr[0]],5)} - {a[j][num_arr[1]]} × {round(x[num_arr[1]],5)}) = {round(x[j],5)}")   
            num_arr.append(j)
            num_arr.sort()        
       
   
def getInputA():    
    # initialize the matrix
    a = np.array([
        [0.25, 0.1, -0.35],
        [0.5, 0.40, 0.10],
        [0.25, 0.5, 0.25]
    ], dtype=float)
    return a

def getInputB():
    # initialize the RHS vector
    b = np.array([0.9, 0.6, 0.5], dtype=float)
    return b

if __name__ == "__main__":
    A = getInputA()
    b = getInputB()
    printArray(A, b, 2)
    print()
    seidel(A, x, b)