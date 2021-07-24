# https://www.youtube.com/watch?v=_Qp3f_b42xg&ab_channel=JordanBarry
import numpy as np
import pandas as pd
np.set_printoptions(formatter={'float': lambda x: "{0:0.4f}".format(x)})

seperator = '-----------------------------------------------------'
def isSquare (m): 
    return all (len (row) == len (m) for row in m)

def printArray(A, b, precision):
    df=pd.DataFrame(data=A[0:,0:],
                    index=[i+1 for i in range(A.shape[0])],
                    columns=['x'+str(i+1) for i in range(A.shape[1])])
    if isSquare(A):
        df['b'] = b
    else:
        df.rename(columns = {'x5':'b'}, inplace = True)

    pd.set_option("display.precision", precision)
    if (precision > 2):
        pd.set_option('display.float_format', lambda x: "{0:0.4f}".format(x))
    print(df)

def getInputA(b=None):    
    A=np.array([
        [0.05, 0.07, 0.06, 0.05],
        [0.07, 0.10, 0.08, 0.07],
        [0.06, 0.08, 0.10, 0.09],
        [0.05, 0.07, 0.09, 0.10],
    ], dtype=float)
    
    Ab=[]
    if len(b) != 0:
        for i in range(A.shape[0]):
            Ab.append(np.append(A[i], b[i]))
            print(A[i])
    return (A,Ab)

def getInputB():
    # initialize the RHS vector
    b = np.array([0.23, 0.32, 0.33, 0.31])
    return b

def getRowsColumns(Ab):
    #get rows and columns
    rows=np.shape(Ab)[0]
    cols=np.shape(Ab)[1]
    x=np.zeros(cols-1)
    return(rows,cols,x)

def forwardElimination(A,rows,cols):
    Ab=np.array([np.array(xi) for xi in A])
    scale = [max([abs(Ab[i][j]) for j in range(rows)]) for i in range(rows)] 
        
    # number of steps: n -1
    for i in range (cols-1):
        print(f'\nS= {scale}')
        pivot(Ab, rows, i, scale)
        # print("\n")            
        if i < cols-2:
            for j in range (i+1,rows):
                numerator = round(Ab[j,i],4)
                denominator = round(Ab[i,i],4)    
                if (numerator != 0 and denominator !=0):
                    print(f'R{j+1}: R{j+1} - ({numerator})/({denominator}) * R{i+1}')
                    Ab[j,:] = Ab[j,:] - (numerator/denominator)*Ab[i,:]
            print(f"\n[{i+2}] {seperator}")
            printArray(Ab,None,4)
            print("\n")
            
    if A[rows-1][rows-1] == 0: 
        print('No unique solution')
        exit()
    return Ab    

def backSubstitution(array,x,cols,rows):
    # arange: start from a particular point
    for i in np.arange(rows-1,-1,-1):
        x[i] = (a[i,-1]-a[i,0:cols-1]@x)/a[i,i]
    print(f"\nBACK SUBSTITUTION: \nsolution matrix\n{x}") 


def pivot(array, rows, i, scale):
  # https://trinket.io/python/041d344e52
  
  first_column = array[:, 0]
  scale_factor = []
  max = -1e100
  for r in range(i, rows):
    a_s = abs(array[r][i]/scale[r])  
    scale_factor.append(a_s)
    if max < abs(a_s):
      max_row = r
      max = a_s

  scale[i], scale[max_row] = scale[max_row], scale[i]
  array[i], array[max_row] = array[max_row], array[i]
  
  print(f"a= {first_column}")
  print(f"scale_factor={scale_factor}")
  print(f"max:{max}\n")
  
if __name__ == "__main__":
    b = getInputB()
    A, Ab = getInputA(b)
    print(f"\nFORWARD ELIMINATION: \nrow echelon form")
    print(f"\n[{1}] {seperator}")
    printArray(A, b, 2)
    rows,cols,x = getRowsColumns(Ab)
    
 
    Ab = forwardElimination(Ab,rows,cols)
    # backSubstitution(a,x,cols,rows)
