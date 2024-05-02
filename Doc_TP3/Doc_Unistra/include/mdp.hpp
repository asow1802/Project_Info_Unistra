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
      S getSTATE(int p){
         return state[p];
      }
      A getACTION(int p){
         return action[p];
      }
      S  getRESET(int x, S *s){
         return reset(x,s);
      }
      int getPOSSIBLE_ACTION(S s, A &a){
         return possible_action(s, *a);
      }
      bool getIS_TERMINAL(S s, int n){
         return is_terminal(s, n);
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
      void POOSIBLE_ACTION(int (*poss_act)(S, A&)){
         possible_action = poss_act;
      }
      void setIS_TERMINAL(bool (*is_ter)(S, int)){
         is_terminal = is_ter;
      }
   //Signatures des constructeurs
      mdp();
      mdp(const mdp &p);
   //Destructeurs
      ~mdp();
   //Operateurs
      mdp & operator = (const mdp &);
      S& operator[](int);
      A& operator()(int);
};
#endif