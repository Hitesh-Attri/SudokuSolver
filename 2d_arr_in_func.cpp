#include<iostream>

using namespace std;

void input( int ** arr, int row, int col){
    cout << "Enter array elements: \n"; 
    for( int i = 0 ; i < row; i++){
        cout << "for row " << i+1 << endl;
        for( int j = 0 ; j < col; j++){
            cin >> arr[i][j];
        }cout << endl; 
    }
}

void display( int ** arr, int row, int col){
    cout << "Array elements are: \n\n"; 
    for( int i = 0 ; i < row; i++){
        for( int j = 0 ; j < col; j++){
            cout << "\t" << arr[i][j];
        }cout << endl; 
    }
}

void initialize( int ** arr, int row, int col){
    for( int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            arr[i][j] = 0;
        }
    }
}

int main()
{
    int row,col;
    cout << "enter row and col: ", cin  >> row >> col;

    // dynamically creating array of pointer of sizee = row
    int **arr = new int *[row];

    // dynaically allocating memory of size = col,  for each row
    for(int r = 0; r < row; r++){
        arr[r] = new int [col];
    }

    initialize(arr,row,col);
    display(arr,row,col);
    input(arr,row,col);
    display(arr,row,col);

    // deallocating the dynamic memory
    // 
    for( int i = 0; i < row; i++){
        delete []arr[i];
    }
    delete [] arr;

    return 0;
}