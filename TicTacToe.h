/*Easy not-graphic Tic Tac Toe game for two players*/

#include <iostream>

class TicTacToe {
public :
   TicTacToe(){
      for (int i = 0; i<9; i++)
         cells[i] = i+1;
   };

   bool winner();

   bool tie();

   void play(int n, const int player);

   void stamp();

   char printPlayer(int n);

   bool win = false;

private:
   int cells[9];
};