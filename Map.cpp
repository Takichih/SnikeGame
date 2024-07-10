

#include "Map.h"

Map::Map () { }

Map::Map (const Map& orig) { }

Map::~Map () { }

  void Map::setWidthX(int p_widthX){
    m_widthX = p_widthX;
  }
  void Map::setHeightY(int p_heightY){
    m_heightY = p_heightY;
  }
  void Map::setFruitX(int p_fruitX){
    m_fruitX = p_fruitX;
  }
  void Map::setFruitY(int p_fruitY){
    m_fruitY = p_fruitY;
  }
  
  int Map::getWidthX()const{
    return m_widthX;
  }
  int Map::getHeightY()const{
    return m_heightY;
  }
  int Map::getFruitX()const{
    return m_fruitX;
  }
  int Map::getFruitY()const{
    return m_fruitY;
  }
  

