#ifndef MDP_HPP
#define MDP_HPP

#include <cmath>
#include <initializer_list>
#include <algorithm>
//#include "point.hpp"
//#include "segment.hpp"

template <class S, class A>  class  mdp 
{
   private:
      int ns, na;
      S *state;
      A *action;
      S (*reset)(int , S *);
      int (*possible_action)(S , A &);
      void (*environnement)(S , A , double &, S &);
      bool (*is_terminal)(S, int);
   public:
   //getter
      int getNS(){
        return ns;
      }
      int getNA(){
        return na;
      }
     A  getRESET(int x, S *s){
        return reset(x,s);
     }
     S getSTATE(int p){
       return state[p];
     }
     S getACTION(int p){
       return action[p];
     }
   //setter
      void setNS(int x){
        this->ns = x;
     }
     void setNA(int x){
        this->na = x;
     }
     void setSTATE(int p, S s){
        this->state[p] = s;
     }
     void setACTION(int p, A a){
        this->action[p] = a;
     }
     void setRESET(S (*res)(int, S *)){
        reset = res;
     }

};
#endif
