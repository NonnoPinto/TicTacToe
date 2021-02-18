#include "TicTacToe.h"

using namespace std;

char TicTacToe::printPlayer(int n){
   if (n==-1)
      return 'X';
   else
      return 'O';
}

bool TicTacToe::winner(){
   int pos = 0;
   
   //horizontal
   for (int i = 0; i<3; i++){
      pos = i*3;
      if (cells[pos] == cells[pos+1] && cells[pos+1] == cells[pos+2]){
         
         int tmp = cells[pos];
         
         for (int k = 0; k<9; k++)
            cells[k] = 10;
         
         cells[pos] = tmp;
         cells[pos+1] = tmp;
         cells[pos+2] = tmp;
         
         win = true;

         return true;
      }
   }
   
   //vertical
   for (int i = 0; i<3; i++){
      pos = i;
      if (cells[pos] == cells[pos+3] && cells[pos+3] == cells[pos+6]){
         
         int tmp = cells[pos];
         
         for (int k = 0; k<9; k++)
            cells[k] = 10;
         
         cells[pos] = tmp;
         cells[pos+3] = tmp;
         cells[pos+6] = tmp;
         
         win = true;

         return true;
      }
   }
   
   //cross
   if (cells[0] == cells[4] && cells[4] == cells[8]){
         int tmp = cells[0];
         
         for (int k = 0; k<9; k++)
            cells[k] = 10;
         
         cells[0] = tmp;
         cells[4] = tmp;
         cells[8] = tmp;

         win = true;

         return true;
   }

   if (cells[2] == cells[4] && cells[4] == cells[6]){
         int tmp = cells[2];
         
         for (int k = 0; k<9; k++)
            cells[k] = 10;
         
         cells[2] = tmp;
         cells[4] = tmp;
         cells[6] = tmp;

         win = true;

         return true;
   }

   return false;
}

bool TicTacToe::tie(){
   for (int i = 1; i<10; i++)
      if (cells[i-1] == (int)i)
         return false;
   return true;
}

void TicTacToe::play(int n, const int player){
      while(n < 0 || n > 8){
         cout << "Dai non rompere il cazzo e metti un numero che vada bene\n";
         cin >> n;
         n--;
      }
      while(cells[n] == -1 || cells[n] == 0){
         cout << "Hey, furbacchione! Non puoi scrivere sopra la cella di un altro! Riprova!\n";
         cin >> n;
         n--;
      }
      
      if (player == 1)
         cells[n] = -1;
      else
         cells[n] = 0;
}

void TicTacToe::stamp(){
   cout << "                         ";
   cout << "-------------------------";
      cout << endl;

   for (int i = 8; i >= 0 ; i--){
      cout << "                         ";
      for (int k = 2; k >=0; k--){
         switch(cells[i-k]){
            case 0: cout << "|   O" << "   ";
               break;
            case -1: cout << "|   X" << "   ";
               break;
            case 10: cout << "|   -   ";
               break;
            default: cout << "|   " << cells[i-k] << "   ";
         }
      }
      i -=2 ;
      cout << "|";
      cout << endl;
      cout << "                         ";
      cout << "-------------------------";
      cout << endl;
   }

   cout << endl;
}