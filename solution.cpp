#include <iostream>

using namespace std;

int** init_matrix(int n) {
    int **matrix = new int*[n];
    for(int i = 0; i < n; i++) {
        matrix[i] = new int[n];
        for(int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    return matrix;
}

void Print(int **matrix, int n) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void check_another(int **matrix, int row, int col, int l) {
    if(matrix[row][col] == 1 or matrix[row][col] == 2){
        matrix[row][col] = 2;
        //print("row: ", row, " col: ", col)
        if(row + 1 < l-1){
            if(matrix[row+1][col] != 2){
                //print("row+1: ", row+1, " col: ", col)
                check_another(matrix, row+1, col, l);
            }
        }
        if(row - 1 > 0){
            if(matrix[row-1][col] != 2){
                //print("row-1: ", row-1, " col: ", col)
                check_another(matrix, row-1, col, l);
            }
        }
        if(col + 1 < l-1){
            if(matrix[row][col+1] != 2){
                //print("row: ", row, " col+1: ", col+1)
                check_another(matrix, row, col+1, l);
            }
        }
        if(col - 1 > 0){
            if(matrix[row][col-1] != 2) {
                //print("row: ", row, " col-1: ", col-1)
                check_another(matrix, row, col-1, l);
            }
        }
    }
}

void remuveIslands(int **matrix, int n) {
    // 1 -> black
    // 0 -> white 
    // remuve all black pixels, which not conected to the border 

    for(int i = 1; i < n-1; i++) {
        if(matrix[0][i] == 1)
            check_another(matrix, 1, i, n);
        if(matrix[n-1][i] == 1)
            check_another(matrix, n-2, i, n);
        if(matrix[i][0] == 1)
            check_another(matrix, i, 1, n);
        if(matrix[i][n-1] == 1)
            check_another(matrix, i, n-2, n);
    }
}

void make_ready(int **matrix, int l){
    for(int i = 1; i < l-1; i++) {
        for(int j = 1; j < l-1; j++) {
            if(matrix[i][j] == 1)
                matrix[i][j] = 0;
            else if(matrix[i][j] == 2)
                matrix[i][j] = 1;
        }
    }
}

int main() {
    int n;
    cin >> n;
    int** matrix = init_matrix(n);

    cout << "_____________\n";
    remuveIslands(matrix, n);

    make_ready(matrix, n);

    Print(matrix, n);

    return 0;
}