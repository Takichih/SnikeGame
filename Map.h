

#ifndef MAP_H
#define MAP_H

class Map
{
public:
  Map ();
  Map (const Map& orig);
  
  void setWidthX(int p_widthX);
  void setHeightY(int p_heightY);
  void setFruitX(int p_fruitX);
  void setFruitY(int p_fruitY);
  
  int getWidthX()const;
  int getHeightY()const;
  int getFruitX()const;
  int getFruitY()const;
  
  
  virtual ~Map ();
private:
  int m_widthX;
  int m_heightY;
  int m_fruitX;
  int m_fruitY;

};

#endif /* MAP_H */

