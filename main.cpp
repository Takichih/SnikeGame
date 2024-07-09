
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
  Direction Dir;
};
Map SnikeMap;
Player Player;
Snike TheSnike;

void setup()
{
  srand(time(NULL));
  SnikeMap.widthX = 30;
  SnikeMap.heightY = 30;
  SnikeMap.fruitX = rand() % (SnikeMap.widthX-2) +1;
  SnikeMap.fruitY = rand() % (SnikeMap.heightY-2) +1;
  TheSnike.headX = rand() % (SnikeMap.widthX-2) +1;
  TheSnike.headY = rand() % (SnikeMap.heightY-2) +1;   
}
void drow(){
  system("clear");
  for (int i=0; i<SnikeMap.widthX; i++){
      for(int j=0; j<SnikeMap.heightY; j++){
          if (i==0 || i==SnikeMap.widthX-1) cout << "* ";
          else if(j==0 || j==SnikeMap.heightY-1) cout << "* ";
          else if(i==SnikeMap.fruitY && j==SnikeMap.fruitX) cout << "$ "; 
          else if(i==TheSnike.headY && j==TheSnike.headX) cout << "O ";
          else cout << "  ";
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
  switch(TheSnike.Dir){
    case Move_Up   : TheSnike.headY--; break;
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

