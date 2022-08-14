#include<iostream>
#include<math.h>

using namespace std;

// ok
void display( int matrix[][9], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << matrix[i][j] << " ";
            if(j == 2 || j == 5){cout << "\t";}
        }cout << endl;
        if(i == 2 || i == 5){cout << endl;}
    }
}

bool isAllow(int matrix[][9], int i, int j, int num, int n){
    //row check
    // for( int col = 0; col < n; col++){
    //     if(matrix[i][col] == num){ return false; }
    // }
    // //col check
    // for( int row = 0; row < n; row++){
    //     if( matrix[row][j] == num){ return false; }
    // }

    for( int x = 0 ; x < n; x++){
        if(matrix[i][x] == num || matrix[x][j] == num){
            return false;
        }
    }



    // sub matrix checking
    int root_n = sqrt(n);
    int s_i = i - i % root_n;
    int s_j = j - j % root_n;

    for( int row = s_i; row < s_i + root_n; row++){
        for( int col = s_j; s_j < s_j + root_n; col++){
            if( matrix[row][col] == num ){
                return false;
            }
        }
    }

    return true;
}

bool sudokuSolver(int matrix[][9], int i, int j, int n){
    //  base case
    if( i == n){  
        display(matrix, n);
        return true;
    }

    // for keeping i,j inside matrix bound
    // we have to check this condition before, 
    // bcz there w'll be some value present at arr[i][10] / or runtime err
    if( j == n ){
        return sudokuSolver(matrix, i+1, 0, n); // i + 1 for next row;
    }

    // if cell already filled( means fixed cell numbers )
    if( matrix[i][j] != 0 ){
        return sudokuSolver(matrix, i, j+1, n);
    }

    // filling cell with allowed number
    for(int number = 1; number <= 9; number++){
        // check if the number is allowed
    
        if( isAllow(matrix, i, j, number, n) ){
            matrix[i][j] = number;
            bool filled = sudokuSolver(matrix, i, j+1, n);
            if( filled ){
                return true;
            }
            // backtracking... reverting the changes
            matrix[i][j] = 0;
        }
    }
    return false;
}

int main()
{
    int n = 9;
    // int matrix[9][9] = {
    //     {0, 0, 7, 1, 0, 0, 0, 6, 0},
    //     {1, 0, 5, 2, 0, 8, 0, 0, 0},
    //     {6, 0, 0, 0, 0, 7, 1, 2, 0},
    //     {3, 1, 2, 4, 0, 5, 0, 0, 8},
    //     {0, 0, 6, 0, 9, 0, 2, 0, 0},
    //     {0, 0, 0, 0, 0, 3, 0, 0, 1},
    //     {0, 0, 1, 0, 0, 4, 9, 8, 6},
    //     {8, 0, 3, 9, 0, 6, 0, 0, 0},
    //     {0, 6, 0, 0, 8, 2, 7, 0, 3}
    // };

    int matrix[9][9] = {
   {3, 0, 6, 5, 0, 8, 4, 0, 0},
   {5, 2, 0, 0, 0, 0, 0, 0, 0},
   {0, 8, 7, 0, 0, 0, 0, 3, 1},
   {0, 0, 3, 0, 1, 0, 0, 8, 0},
   {9, 0, 0, 8, 6, 3, 0, 0, 5},
   {0, 5, 0, 0, 9, 0, 6, 0, 0},
   {1, 3, 0, 0, 0, 0, 2, 5, 0},
   {0, 0, 0, 0, 0, 0, 0, 7, 4},
   {0, 0, 5, 2, 0, 6, 3, 0, 0}
};

    sudokuSolver(matrix, 0, 0, n);
   // display(matrix,n);
    
    return 0;
}