

#include "Snike.h"

Snike::Snike () { }

Snike::Snike (const Snike& orig) { }

Snike::~Snike () { }

 void Snike::setHeadX(int p_headX){
   m_headX = p_headX;
 }
  void Snike::setHeadY(int p_headY){
    m_headY = p_headY;
  }
  void Snike::setCorp(int p_corp){
    m_corp = p_corp;
  }
  void Snike::setTailN(int p_tail_N){
    m_tail_N = p_tail_N;
  }
  void Snike::setTailY(int p_tail_X[]){
    for (int i=0; i<50; i++){
        m_tail_X[i] = p_tail_X[i];
      }
    
  }
  void Snike::setTailX(int p_tail_Y[]){
    for (int i=0; i<50; i++){
        m_tail_Y[i] = p_tail_Y[i];
      }
  }
  
  int Snike::getHeadX()const{
    return m_headX;
  }
  int Snike::getHeadY()const{
    return m_headY;
  }
  int Snike::getCorp()const{
    return m_corp;
  }
  int Snike::getTailN()const{
    return m_tail_N;
  }
   int* Snike::getTailY(){
    return m_tail_Y;
  }
  int* Snike::getTailX(){
    return m_tail_X;
  }
  
  void Snike::setDir(Direction p_dir){
    m_dir = p_dir;
  }
  
  
  Snike::Direction Snike::getDir()const{
   return m_dir;
 }
  