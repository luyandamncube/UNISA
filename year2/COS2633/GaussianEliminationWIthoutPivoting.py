# https://www.youtube.com/watch?v=_Qp3f_b42xg&ab_channel=JordanBarry
import numpy as np
import pandas as pd
np.set_printoptions(formatter={'float': lambda x: "{0:0.4f}".format(x)})

seperator = '-----------------------------------------------------'
def printArray(array,precision):
    df=pd.DataFrame(data=a[0:,0:],
                    index=[i+1 for i in range(a.shape[0])],
                    columns=['x'+str(i+1) for i in range(a.shape[1])])

    pd.set_option("display.precision", precision)
    if (precision > 2):
        pd.set_option('display.float_format', lambda x: "{0:0.4f}".format(x))
    print(df)

def getInput():
    #define a matrix 
    # a=np.array([
    #     [3,-2,2,3],
    #     [2,3,14,1],
    #     [3,3,5,8],  
    # ], dtype=float)


    # a=np.array([
    #     [0.06, 0.08, 0.07, 0.08, 0.29],
    #     [0.08, 0.20, 0.09, 0.07, 0.44],
    #     [0.07, 0.09, 0.20, 0.10, 0.46],
    #     [0.06, 0.08, 0.10, 0.20, 0.44],
    # ], dtype=float)

    a=np.array([
        [0.05, 0.07, 0.06, 0.05, 0.23],
        [0.07, 0.10, 0.08, 0.07, 0.32],
        [0.06, 0.08, 0.10, 0.09, 0.33],
        [0.05, 0.07, 0.09, 0.10, 0.31],
    ], dtype=float)
    return a

def getRowsColumns(array):
    #get rows and columns
    rows=np.shape(a)[0]
    cols=np.shape(a)[1]
    x=np.zeros(cols-1)
    return(rows,cols,x)

def forwardElimination(array,rows,cols):
    # number of steps: n -1
    for i in range (cols-1):
        print("\n")
        if i == cols-2:
            print('last row')
            
        if i < cols-2:
            for j in range (i+1,rows):
                
                # if(i+2 ==rows):
                #     # hacky fix for last iteration
                #     print('start hacky fix')
                #     numerator = round(0.1200,4)
                #     denominator = round(0.0054,4)
                # else:
                numerator = round(a[j,i],4)
                denominator = round(a[i,i],4)    
                if (numerator != 0 and denominator !=0):
                     # a[j,:] =- (numerator/denominator)*a[i,:]+a[j,:]
                    print(f'R{j+1}: R{j+1} - ({numerator})/({denominator}) * R{i+1}')
                    # print(f'R{j+1}: {a[j,:]} - ({numerator})/({denominator}) * {a[i,:]}')
                    # print(F'MULTIPLIER: { (numerator/denominator)}')
                    # print(f"BEFORE:\nnumerator:{numerator}\ndenominator:{denominator}\nR{j+1}:{a[j,:]}\nR{i+1}:{a[i,:]}\n")
        
                    a[j,:] = a[j,:] - (numerator/denominator)*a[i,:]
                    # print(f"AFTER:\nnumerator:{numerator}\ndenominator:{denominator}\nR{j+1}:{a[j,:]}\nR{i+1}:{a[i,:]}\n")
        
                # printArray(a,4)
            print(f"\n[{i+2}] {seperator}")
            printArray(a,4)
            
    return a     

def backSubstitution(array,x,cols,rows):
    # arange: start from a particular point
    for i in np.arange(rows-1,-1,-1):
        x[i] = (a[i,-1]-a[i,0:cols-1]@x)/a[i,i]
    print(f"\nBACK SUBSTITUTION: \nsolution matrix\n{x}") 

if __name__ == "__main__":
    a = getInput()
    print(f"\n[{1}] {seperator}")
    printArray(a,2)
    rows,cols,x = getRowsColumns(a)
    # print(f"\nrows: {rows}, cols {cols}, x {x}")
    a = forwardElimination(a,rows,cols)
    print(f"\nFORWARD ELIMINATION: \nrow echelon form")
    print('\n'+seperator)
    backSubstitution(a,x,cols,rows)
