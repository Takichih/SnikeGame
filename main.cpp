
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>
#include "Map.h"
#include "Player.h"
#include "Snike.h"

#include "methodes.h"

using namespace std;

int main ()
{   
    setup();
    while (!Player.getLose()){  
        drow();
        input();
        move(TheSnike);
        usleep(150000);       
    }
    cout << "Game over !" << endl;
   
  return 0;
}

