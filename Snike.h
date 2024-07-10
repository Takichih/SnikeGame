

#ifndef SNIKE_H
#define SNIKE_H

class Snike
{
  
public:

  Snike ();
  Snike (const Snike& orig);
  virtual ~Snike ();
  
  enum Direction {Move_Up = 1, Move_Down, Move_Right, Move_Left};
  
  void setHeadX(int p_headX);
  void setHeadY(int p_headY);
  void setCorp(int p_corp);
  void setTailN(int p_tail_N);
  void setTailY(int p_tail_X[]);
  void setTailX(int p_tail_Y[]);
  void setCurrentDir(Direction p_currentDir);
  
  int getHeadX()const;
  int getHeadY()const;
  int getCorp()const;
  int getTailN()const;
  int* getTailY();
  int* getTailX();
  Direction getCurrentDir()const;
  
  Direction getPreviousDir()const;
  void setPreviousDir(Direction p_PreviousDir);
  
private:
  int m_headX;
  int m_headY;
  int m_corp;
  int m_tail_N = 0;
  int m_tail_X[50];
  int m_tail_Y[50];
  Direction m_currentDir;
  Direction m_previousDir;

};

#endif /* SNIKE_H */

