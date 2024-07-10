
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "kbhit.h"
#include <unistd.h>
#include "Map.h"
#include "Player.h"
#include "Snike.h"

Map SnikeMap;
Player Player;
Snike TheSnike;


  void shift_right(int array[], int size){
    for (int i=size-2; i>=0; i--)
    {
      array[i+1]= array[i];
    }
  }
  void setup(){
    srand(time(NULL));
    SnikeMap.setWidthX (25);
    SnikeMap.setHeightY (25);         
    SnikeMap.setFruitX((rand() % (SnikeMap.getWidthX()-2) +1));
    SnikeMap.setFruitY((rand() % (SnikeMap.getHeightY()-2)+1));
    TheSnike.setHeadX ((rand() % (SnikeMap.getWidthX()-2) +1)); 
    TheSnike.setHeadY ((rand() % (SnikeMap.getHeightY()-2)+1));
    }
  void drow(){
     system("clear"); //For Windows, use system("cls")
  for (int i=0; i<SnikeMap.getWidthX(); i++){
      for(int j=0; j<SnikeMap.getHeightY(); j++){
          if (i==0 || i==SnikeMap.getWidthX()-1) std::cout << "::";
          else if(j==0 || j==SnikeMap.getHeightY()-1) std::cout << "..";
          else if(i==TheSnike.getHeadY () && j==TheSnike.getHeadX ()) std::cout << "@ ";
          else if(i==SnikeMap.getFruitY() && j==SnikeMap.getFruitX()) std::cout << "$ "; 
          else {
              bool printed = false;
              for (int z=0; z<TheSnike.getTailN (); z++){
                  if (TheSnike.getTailX ()[z]==j && TheSnike.getTailY ()[z]==i)
                    {
                      std::cout << "o ";
                      printed = true;
                      break;
                    }
                }
              if (!printed) std::cout << "  ";
            }
        }
      std::cout << "\n";
    }
  std::cout << "Score: " << Player.getScore() << std::endl;
  }
  
  void input(){
     if(kbhit()){
     char c = getch();
     switch(c)
       {
       case 'w': TheSnike.setCurrentDir (Snike::Move_Up); break;
       case 's': TheSnike.setCurrentDir (Snike::Move_Down); break;
       case 'd': TheSnike.setCurrentDir (Snike::Move_Right); break;
       case 'a': TheSnike.setCurrentDir (Snike::Move_Left); break;
       case 'x': exit(0);
       }
   } 
  }
  
void move(Snike& theSnike)
{
    shift_right(TheSnike.getTailX (), 50);
    shift_right(TheSnike.getTailY (), 50);
    TheSnike.getTailX ()[0]= TheSnike.getHeadX ();
    TheSnike.getTailY ()[0]= TheSnike.getHeadY ();

    switch (TheSnike.getCurrentDir()) {
        case Snike::Move_Up:
            if (TheSnike.getPreviousDir() != Snike::Move_Down) {
                TheSnike.setHeadY(TheSnike.getHeadY() - 1);
            } else {
                TheSnike.setHeadY(TheSnike.getHeadY() + 1); // Continuer dans la direction précédente
            }
            break;

        case Snike::Move_Down:
            if (TheSnike.getPreviousDir() != Snike::Move_Up) {
                TheSnike.setHeadY(TheSnike.getHeadY() + 1); ;
            } else {
                TheSnike.setHeadY(TheSnike.getHeadY() - 1); // Continuer dans la direction précédente
            }
            break;

        case Snike::Move_Right:
            if (TheSnike.getPreviousDir() != Snike::Move_Left) {
                TheSnike.setHeadX(TheSnike.getHeadX() + 1);
            } else {
                TheSnike.setHeadX(TheSnike.getHeadX() - 1); // Continuer dans la direction précédente
            }
            break;

        case Snike::Move_Left:
            if (TheSnike.getPreviousDir() != Snike::Move_Right) {
                TheSnike.setHeadX(TheSnike.getHeadX() - 1);
            } else {
                TheSnike.setHeadX(TheSnike.getHeadX() + 1); // Continuer dans la direction précédente
            }
            break;
    }

    //TheSnike.setPreviousDir(TheSnike.getCurrentDir());
       

    if (TheSnike.getHeadX ()<= 0 || TheSnike.getHeadX ()>= SnikeMap.getWidthX() - 1 
        || TheSnike.getHeadY ()<= 0 || TheSnike.getHeadY () >= SnikeMap.getHeightY() - 1) 
        {
            Player.setLose(true);
        }
    else
        for (int i=0; i<TheSnike.getTailN (); i++){
            if(TheSnike.getHeadX () == TheSnike.getTailX ()[i] && TheSnike.getHeadY ()== TheSnike.getTailY ()[i])
            {
                Player.setLose(true);
            }
        }
  
        // Check if the snake eats the fruit
    if (TheSnike.getHeadX () == SnikeMap.getFruitX() && TheSnike.getHeadY () == SnikeMap.getFruitY()) {
            Player.setScore(Player.getScore() + 10);
            TheSnike.setTailN (TheSnike.getTailN()+1);
            SnikeMap.setFruitX((rand() % (SnikeMap.getWidthX() - 2) + 1)); 
            SnikeMap.setFruitY((rand() % (SnikeMap.getHeightY() - 2) + 1));
        }
    
     
}
