#include <stdio.h>

char board[9]={'0','1','2','3','4','5','6','7','8'};
void print_board(char* board);
int win_check(char* board);
int main(void){
    int x;
    int o;
    int turns=0;
    while (1) {
        print_board(board);
        while (1){
            printf("Input Player 1: ");
            scanf("%d", &x);
            if (x>=0 && x<9 && board[x]!='X' && board[x]!='O'){
                board[x]='X';
                print_board(board);
                turns++;
                printf("%i \n", turns);
                if (turns>=4) {
                    int n= win_check(board);
                    if (n==1) {
                        printf("Player 1 won!!");
                        return 0;
                }
                }
                break;
            }
            else {
                printf("Enter a valid number");
            }
        }

        fflush(stdin);
        while (1){
            printf("Input Player 2: ");
            scanf("%i", &o);
            if (o>=0 && o<9 && board[o]!='X' && board[o]!='O'){
                board[o]='O';
                turns++;
                printf("%i \n", turns);
                if (turns>=4) {
                    int n= win_check(board);
                    if (n==1) {
                        printf("Player 2 won!!");
                        return 0;
                }
                }
                break;
            }
            else {
                printf("Enter a valid number\n");
            }
        }
        if (turns>8){
            print_board(board);
            printf("Tie");
            return 0;
        }
    }
}

void print_board(char* board) {
    for (int i = 1; i<=9; i++) {
        printf("%c |", board[i-1]);

        if (i != 0 && i%3==0){
            printf("\n __ __ __ \n");
        }
    }
    printf("\n");

}
int win_check(char* board) {
    // printf("I got called");
    for (int i = 0; i<3 ;i++){
        //horizontal
        if (board[i*3]==board[i*3+1] && board[i*3+1] ==board[i*3+2]){
            return 1;
        }
        //vertical
        else if (board[i]==board[i+3]&& board[i+3]==board[i+6]){
            return 1;
        }
        //diagonal
        else if (board[i*2]==board[i*2+4] && board[i*2+4]==board[i*2+8]) {
            return 1;
        }
        
    }
    return 0;
          
}