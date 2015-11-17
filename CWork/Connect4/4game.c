
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct board {
  char cells[7][6];
  int nextFree[8];
  char player;
  int row, column;
  int moves;
};


void displayBoard(struct board b){
  printf("\n 1 2 3 4 5 6 7\n");
  for (int i = 5; i > -1; i--){
    for (int j = 0; j < 7; j++){
      printf(" %c", b.cells[j][i]);
    }
    printf("\n");
  }}


  struct board cleanBoard(){
    struct board b;
    memset(b.nextFree, 0, sizeof(b.nextFree));
    memset(b.cells, '0', sizeof(b.cells));
    b.player = 'A';
    return b;
  }


  char changeplayer(char player) {
    if (player == 'A'){
      return 'B';
    } else return 'A';
  }


  struct board position(struct board b, char *text){
    if(strlen(text) != 1){
      b.row = b.column = -1;
      return b;
    }

    int row = (text[0] - 48);
    if (row < 1 || row > 7 ){
      b.row = b.column = -1;
      return b;
    }

    if (b.nextFree[(row-1)] > 5 ){
      b.row = b.column = -1;
      return b;
    }

    b.row = (row-1);
    b.column = b.nextFree[(row-1)];
    return b;
  }


  struct board move(struct board b) {
    b.cells[b.row][b.nextFree[b.row]] = b.player;
    b.nextFree[b.row] = b.nextFree[b.row] + 1;
    b.moves++;
    b.player = changeplayer(b.player);
    displayBoard(b);
    return b;
  }


  bool line(char p, char w, char x, char y, char z){
    if (p == w && p == x && p == y && p == z) return true;
    return false;
  }


  bool win(struct board b){
    for (int i = 0; i < 7; i++){
      for(int j = 0; j < 3; j++){
        if (line(changeplayer(b.player), b.cells[i][j], b.cells[i][(j+1)], b.cells[i][(j+2)], b.cells[i][(j+3)]) == true) return true;
      }
    }
    for (int n = 0; n < 6; n++){
      for (int m = 0; m < 3; m++){
        if (line(changeplayer(b.player), b.cells[m][n], b.cells[(m+1)][n], b.cells[(m+2)][n], b.cells[(m+3)][n]) == true) return true;
      }
    }
    if (line(changeplayer(b.player), b.cells[0][2], b.cells[1][3], b.cells[2][4], b.cells[3][5]) == true) return true;
    if (line(changeplayer(b.player), b.cells[0][3], b.cells[1][2], b.cells[2][1], b.cells[3][0]) == true) return true;
    if (line(changeplayer(b.player), b.cells[3][5], b.cells[4][4], b.cells[5][3], b.cells[6][2]) == true) return true;
    if (line(changeplayer(b.player), b.cells[3][0], b.cells[4][1], b.cells[5][2], b.cells[6][3]) == true) return true;
    for(int i = 0; i < 2; i++){
      if (line(changeplayer(b.player), b.cells[(4-i)][i], b.cells[(3-i)][(i+1)], b.cells[(2-i)][(i+2)], b.cells[(1-i)][(i+3)]) == true) return true;
      if (line(changeplayer(b.player), b.cells[(6-i)][(i+1)], b.cells[(5-i)][(i+2)], b.cells[(4-i)][(i+3)], b.cells[(3-i)][(i+4)]) == true) return true;
      if (line(changeplayer(b.player), b.cells[(2+i)][i], b.cells[(3+i)][(i+1)], b.cells[(4+i)][(i+2)], b.cells[(5+i)][(i+3)]) == true) return true;
      if (line(changeplayer(b.player), b.cells[(i)][(i+1)], b.cells[(1+i)][(i+2)], b.cells[(2+i)][(i+3)], b.cells[(3+i)][(i+4)]) == true) return true;
    }
    for (int i = 0; i < 3; i++){
      if (line(changeplayer(b.player), b.cells[i][i], b.cells[(i+1)][(i+1)], b.cells[(i+2)][(i+2)], b.cells[(i+3)][(i+3)]) == true) return true;
      if (line(changeplayer(b.player), b.cells[(i+1)][(i+1)], b.cells[(i+2)][(i+2)], b.cells[(i+3)][(i+3)], b.cells[(i+4)][(i+4)]) == true) return true;
      if (line(changeplayer(b.player), b.cells[(5-i)][i], b.cells[(4-i)][(i+1)], b.cells[(3-i)][(i+2)], b.cells[(2-i)][(i+3)]) == true) return true;
      if (line(changeplayer(b.player), b.cells[(6-i)][i], b.cells[(5-i)][(i+1)], b.cells[(4-i)][(i+2)], b.cells[(3-i)][(i+3)]) == true) return true;
    }
    return false;
  }


  int main(){
    struct board b = cleanBoard();
    bool form;
    char input[100];
    size_t ln;
    displayBoard(b);
    while(win(b) == false && b.moves < 42) {
      form = false;
      while (form == false) {
        printf("%c enter a move > \n", b.player);
        fgets(input, sizeof(input), stdin);
        ln = strlen(input) - 1;
        if (input[ln] == '\n')
        input[ln] = '\0';
        b = position(b, input);
        if (b.row != -1){
          b = move(b);
          form = true;
        }
        else printf("Invalid move, try again\n");
      }
    }
    if (win(b) == true){
      printf("Player %c wins!\n", b.player);}
      else {printf("Its a draw\n");}
      return 0;
    }
