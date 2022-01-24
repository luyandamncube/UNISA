# https://www.geeksforgeeks.org/gauss-seidel-method/
import pandas as pd
import numpy as np

# CHANGE THIS FOR 3 DIGITS
# x = [0.00, 0.00, 0.00, 0.00]  
# x = [3.00, 0.00, 3.00, 1.00] 

x = [0.00, 0.00, 0.00]

ITERATION_LIMIT = 25
seperator = '-----------------------------------------------------'
# CHANGE THIS FOR 3 DIGITS
# num_arr = [0,1,2,3]
num_arr = [0,1,2]

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
    print(f'LEN: {n}')               
    for i in range(0, ITERATION_LIMIT):   
        print(f"iteration {i+1}: {seperator}")   
        for j in range(0, n):        
            d = b[j] 
            num_arr.remove(j)  
            for k in range(0, n):  
                # print(k)
                if(j != k):
                    d-=a[j][k] * x[k]     
            x[j] = d / a[j][j]
            temp = b[j]
            # ADD THIS IN FOR 3 DIGITS
            if (j == 1 and i > 0):
                temp = x[0]
            print(f"x_{j+1} = 1/{a[j][j]} × ({round(temp,5)} - {a[j][num_arr[0]]} × {round(x[num_arr[0]],5)} - {a[j][num_arr[1]]} × {round(x[num_arr[1]],5)} - {a[j][num_arr[2]]} × {round(x[num_arr[2]],5)}) = {round(x[j],5)}")   
            num_arr.append(j)
            num_arr.sort()        
       
   
def getInputA():    
    # initialize the matrix
    a = np.array([
        [4.63, -1.21, 3.22],
        [-3.07, 5.48, 2.11],
        [1.26, 3.11, 4.57],
    ], dtype=float)
    # a = np.array([
    #     [0.05, 0.07, 0.06, 0.05],
    #     [0.07, 0.10, 0.08, 0.07],
    #     [0.06, 0.08, 0.10, 0.09],
    #     [0.05, 0.07, 0.09, 0.10],
    # ], dtype=float)
    # a = np.array([
    #     [0.06, 0.08, 0.07, 0.08],
    #     [0.08, 0.20, 0.09, 0.07],
    #     [0.07, 0.09, 0.20, 0.10],
    #     [0.06, 0.08, 0.10, 0.20],
    # ], dtype=float)
    # a = np.array([
    #     [2.141, -2.718, 1.414, -1.732],
    #     [9.869, 2.718, -7.389, 0.428],
    #     [2.236, -2.449, 1, -1.414],
    #     [31.006, 7.389, -2.645, 0.111],
    # ], dtype=float)
    return a

def getInputB():
    # initialize the RHS vector
    b = np.array([2.22, -3.17,5.11], dtype=float)
    # b = np.array([3.316, 0 , 3.141, 1.414], dtype=float)
    # b = np.array([0.29, 0.44, 0.46, 0.44], dtype=float)
    return b

if __name__ == "__main__":
    A = getInputA()
    b = getInputB()
    printArray(A, b, 2)
    print()
    seidel(A, x, b)