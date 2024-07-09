
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "kbhit.h"
#include <unistd.h>

using namespace std;

class Map{
public:
  int widthX;
  int heightY;
  int fruitX;
  int fruitY;
};

class Player{
public:
  bool lose;
  int score;
  
};
enum Direction {Move_Up = 1, Move_Down, Move_Right, Move_Left};
class Snike{
public:
  int headX;
  int headY;
  int corp;
  Direction Dir = Move_Right;
  int tail_N = 0;
  int tail_X[50];
  int tail_Y[50];
};
void shift_right(int array[], int size){
  for (int i=size-2; i>=0; i--){
      array[i+1]= array[i];
    }
}

Map SnikeMap;
Player Player;
Snike TheSnike;

void setup()
{
  srand(time(NULL));
  SnikeMap.widthX  = 20;
  SnikeMap.heightY = 20;
  SnikeMap.fruitX  = rand() % (SnikeMap.widthX-2) +1;
  SnikeMap.fruitY  = rand() % (SnikeMap.heightY-2)+1;
  TheSnike.headX   = rand() % (SnikeMap.widthX-2) +1;
  TheSnike.headY   = rand() % (SnikeMap.heightY-2)+1;   
}
void drow(){
  system("clear"); //For Windows, use system("cls")
  for (int i=0; i<SnikeMap.widthX; i++){
      for(int j=0; j<SnikeMap.heightY; j++){
          if (i==0 || i==SnikeMap.widthX-1) cout << "* ";
          else if(j==0 || j==SnikeMap.heightY-1) cout << "* ";
          else if(i==TheSnike.headY && j==TheSnike.headX) cout << "O ";
          else if(i==SnikeMap.fruitY && j==SnikeMap.fruitX) cout << "$ "; 
          else {
              bool printed = false;
              for (int z=0; z<TheSnike.tail_N; z++){
                  if (TheSnike.tail_X[z]==j && TheSnike.tail_Y[z]==i)
                    {
                      cout << "o ";
                      printed = true;
                      break;
                    }
                }
              if (!printed) cout << "  ";
            }
        }
      cout << "\n";
    }
  cout << "Score: " << Player.score << endl;
}

void input(){
 if(kbhit()){
     char c = getch();
     switch(c)
       {
       case 'w': TheSnike.Dir = Move_Up; break;
       case 's': TheSnike.Dir = Move_Down; break;
       case 'd': TheSnike.Dir = Move_Right; break;
       case 'a': TheSnike.Dir = Move_Left; break;
       case 'x': exit(0);
       }
   } 
}

void move(){
  shift_right(TheSnike.tail_X, 50);
  shift_right(TheSnike.tail_Y, 50);
  TheSnike.tail_X[0]= TheSnike.headX;
  TheSnike.tail_Y[0]= TheSnike.headY;
  
  switch(TheSnike.Dir)
    {
        case Move_Up   :TheSnike.headY--; break;
        case Move_Down :TheSnike.headY++; break;
        case Move_Right:TheSnike.headX++; break;
        case Move_Left :TheSnike.headX--; break;
    }
  
   if (TheSnike.headX <= 0 || TheSnike.headX >= SnikeMap.widthX - 1 || TheSnike.headY <= 0 || TheSnike.headY >= SnikeMap.heightY - 1) {
        Player.lose = true;
    }
 

    // Check if the snake eats the fruit
    if (TheSnike.headX == SnikeMap.fruitX && TheSnike.headY == SnikeMap.fruitY) {
        Player.score += 10;
        TheSnike.tail_N++;
        SnikeMap.fruitX = rand() % (SnikeMap.widthX - 2) + 1;
        SnikeMap.fruitY = rand() % (SnikeMap.heightY - 2) + 1;
    }
}

int main ()
{
    setup();
    while (!Player.lose){
        
        drow();
        input();
        move();
        usleep(150000);       
    }
    cout << "Game over !" << endl;
   
  return 0;
}

