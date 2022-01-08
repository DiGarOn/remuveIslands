def check_another(matrix, mas):
    row = mas[0]
    col = mas[1]
    l = len(matrix)
    if(matrix[row][col] == 1 or matrix[row][col] == 2):
        matrix[row][col] = 2
        #print("row: ", row, " col: ", col)
        if(row + 1 < l-1):
            if(matrix[row+1][col] != 2):
                #print("row+1: ", row+1, " col: ", col)
                check_another(matrix, [row+1, col])
        if(row - 1 > 0):
            if(matrix[row-1][col] != 2):
                #print("row-1: ", row-1, " col: ", col)
                check_another(matrix, [row-1, col])
        if(col + 1 < l-1):
            if(matrix[row][col+1] != 2):
                #print("row: ", row, " col+1: ", col+1)
                check_another(matrix, [row, col+1])
        if(col - 1 > 0):
            if(matrix[row][col-1] != 2):
                #print("row: ", row, " col-1: ", col-1)
                check_another(matrix, [row, col-1])
    
def remuveIslands(matrix):
    # 1 -> black
    # 0 -> white 
    # remuve all black pixels, which not conected to the border  
    l = len(matrix)
    
    for i in range(1, l-1):
        if(matrix[0][i] == 1):
            check_another(matrix, [1,i])
        if(matrix[l-1][i] == 1):
            check_another(matrix, [l-2,i])
        if(matrix[i][0] == 1):
            check_another(matrix, [i,1])
        if(matrix[i][l-1] == 1):
            check_another(matrix, [i,l-2])
    
def Print(matrix):
    l = len(matrix)
    for i in range(l):
        for j in range(l):
            print(matrix[i][j], end = " ")
        print("\n")

def make_ready(matrix):
    l = len(matrix)
    for i in range(1, l-1):
        for j in range(1, l-1):
            if(matrix[i][j] == 1):
                matrix[i][j] = 0
            elif(matrix[i][j] == 2):
                matrix[i][j] = 1

if __name__ == '__main__':
    matrix = []
    #len
    n = int(input())
    for i in range(n):
        matrix.append(list(map(int, input().split())))
    
    print("__________")
    remuveIslands(matrix)

    make_ready(matrix)
    
    Print(matrix)
