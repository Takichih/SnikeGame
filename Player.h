
#ifndef PLAYER_H
#define PLAYER_H

class Player
{
public:
  Player ();
  Player (const Player& orig);
  virtual ~Player ();
  
  void setLose(bool p_lose);
  void setScore(int p_score);
  bool getLose()const;
  int  getScore()const;
  
private:
   bool m_lose;
   int  m_score;
};

#endif /* PLAYER_H */

