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
    
    scale = [max([abs(array[i][j]) for j in range(rows)]) for i in range(rows)] 
        
    # number of steps: n -1
    for i in range (cols-1):
        print(f'\nS= {scale}')
        pivot(array, rows, i, scale)
        # print("\n")            
        if i < cols-2:
            for j in range (i+1,rows):
                numerator = round(a[j,i],4)
                denominator = round(a[i,i],4)    
                if (numerator != 0 and denominator !=0):
                    print(f'R{j+1}: R{j+1} - ({numerator})/({denominator}) * R{i+1}')
                    a[j,:] = a[j,:] - (numerator/denominator)*a[i,:]
            print(f"\n[{i+2}] {seperator}")
            printArray(a,4)
            print("\n")
            
    if array[rows-1][rows-1] == 0: 
        print('No unique solution')
        exit()
    return a     

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
    a = getInput()
    print(f"\nFORWARD ELIMINATION: \nrow echelon form")
    # print('\n'+seperator)
    print(f"\n[{1}] {seperator}")
    printArray(a,2)
    rows,cols,x = getRowsColumns(a)
    # print(f"\nrows: {rows}, cols {cols}, x {x}")
    
 
    a = forwardElimination(a,rows,cols)
    backSubstitution(a,x,cols,rows)
