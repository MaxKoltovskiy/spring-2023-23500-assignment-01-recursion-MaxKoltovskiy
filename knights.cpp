#include <iostream>
#include <unistd.h>

bool is_solved(int board[][5], int rows, int cols) {
    for(int i = 0; i< rows; i++) {
        for(int j = 0; j< cols; j++) {
            if(board[i][j] == 0) {
                return false;
            }
        }
    }

    return true;
}
void print_board(int board[][5], int num_rows, int num_cols) {
    std::cout << "[0;0H\n";

    for (int i=0; i < num_rows; i++){
        for(int j = 0; j< num_cols; j++){
            if(board[i][j] < 10) std::cout<< " ";
            std::cout << board[i][j]<< " ";
        }
        std::cout<< "\n";
    }
}
void knights_tour(int board[][5], int row, int col, int num_rows, int num_cols, bool& solved, int order) {
    if(is_solved(board, num_rows, num_cols)) {
        solved = true;
        usleep(80000);
        print_board(board, num_rows, num_cols);
        return;
    }
    
    if(row >= num_rows || row < 0 || col >= num_cols || col < 0 || board[row][col] != 0) {
        return;
    }
    if(!solved) board[row][col] = order;
    usleep(80000);
    print_board(board, num_rows, num_cols);

    
    /*
    .8.1.
    7...2
    ..N..
    6...3
    .5.4.
    */
    if(!solved) knights_tour(board, row-2, col+1, num_rows, num_cols, solved, order+1);
    if(!solved) knights_tour(board, row-1, col+2, num_rows, num_cols, solved, order+1);
    if(!solved) knights_tour(board, row+1, col+2, num_rows, num_cols, solved, order+1);
    if(!solved) knights_tour(board, row+2, col+1, num_rows, num_cols, solved, order+1);

    if(!solved) knights_tour(board, row+2, col-1, num_rows, num_cols, solved, order+1);
    if(!solved) knights_tour(board, row+1, col-2, num_rows, num_cols, solved, order+1);
    if(!solved) knights_tour(board, row-1, col-2, num_rows, num_cols, solved, order+1);
    if(!solved) knights_tour(board, row-2, col-1, num_rows, num_cols, solved, order+1);

    if(!solved) board[row][col] = 0;
}

int main()
{
    int board[5][5];
    int num_rows = 5;
    int num_cols = 5;
    bool solved = false;

    for(int i = 0; i< num_rows; i++) {
        for(int j = 0; j< num_cols; j++) {
            board[i][j] = 0;
        }
    }

    knights_tour(board, 0, 0, num_rows,num_cols, solved, 1);

    return 0;
}