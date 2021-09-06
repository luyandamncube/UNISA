# https://www.youtube.com/watch?v=_Qp3f_b42xg&ab_channel=JordanBarry
import numpy as np
import pandas as pd
np.set_printoptions(formatter={'float': lambda x: "{0:0.4f}".format(x)})

seperator = '-----------------------------------------------------'
def printArray(array,precision):
    df=pd.DataFrame(data=array[0:,0:],
                    index=[i+1 for i in range(array.shape[0])],
                    columns=['x'+str(i+1) for i in range(array.shape[1])])

    pd.set_option("display.precision", precision)
    if (precision > 2):
        pd.set_option('display.float_format', lambda x: "{0:0.4f}".format(x))
    print(df)

def getInput():
    a=[
        [0.05, 0.07, 0.06, 0.05],
        [0.07, 0.10, 0.08, 0.07],
        [0.06, 0.08, 0.10, 0.09],
        [0.05, 0.07, 0.09, 0.10],
    ]

    return a

def getRowsColumns(array):
    #get rows and columns
    rows=np.shape(a)[0]
    cols=np.shape(a)[1]
    x=np.zeros(cols-1)
    return(rows,cols,x)
   
def lu_decomposition(A):
    # https://www.programmersought.com/article/5607937285/
    n=len(A[0])
    L = np.zeros([n,n])
    U = np.zeros([n, n])
    counter  = 0 
    for i in range(n):
        counter = counter +  1
        L[i][i]=1
        if i==0:
            U[0][0] = A[0][0]
            for j in range(1,n):
                U[0][j]=A[0][j]
                L[j][0]=A[j][0]/U[0][0]

        else:
                for j in range(i, n):#U
                    temp=0
                    for k in range(0, i):
                        temp = temp+L[i][k] * U[k][j]
                    U[i][j]=A[i][j]-temp
                for j in range(i+1, n):#L
                    temp = 0
                    for k in range(0, i ):
                        temp = temp + L[j][k] * U[k][i]
                    L[j][i] = (A[j][i] - temp)/U[i][i]
        
        print(f"ITERATION: {counter}")
        print(f"L\n")
        printArray(L,4)
        print(f"U\n")
        printArray(U,4)
        print(seperator)
    return L,U

if __name__ == "__main__":
    a = getInput()
    L,U = lu_decomposition(a)
