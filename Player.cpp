
#include "Player.h"

Player::Player () { }

Player::Player (const Player& orig) { }

Player::~Player () { }

  void Player::setLose(bool p_lose){
    m_lose = p_lose;
  }
  void Player::setScore(int p_score){
    m_score = p_score;
  }
  bool Player::getLose()const{
    return m_lose;
  }
  int Player::getScore()const{
    return m_score;
  }
