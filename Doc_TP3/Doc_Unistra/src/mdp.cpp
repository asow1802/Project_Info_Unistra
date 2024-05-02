#include <cmath>

#include "mdp.hpp"

//Constructeurs
        template <class S, class A> 
        mdp <S, A>::mdp (){
               ns = 0;
               na = 0;
               state = nullptr;
               action = nullptr;
               reset = nullptr;
               possible_action = nullptr;
               environnement = nullptr;
               is_terminal = nullptr;
        }
        template <class S, class A> 
        mdp <S, A>::mdp (const mdp <S, A> & p){
               ns = p.ns;
               na = p.na;
               for (int i = 0; i < ns; i++)
               {
                  state[i] = p.state[i];
               }
               for (int j = 0; j < na; j++)
               {
                  action[j] = p.action[j];
               }
               reset = p.reset;
               possible_action = p.possible_action;
               environnement = p.environnement;
               is_terminal = p.is_terminal;
            }
//Destructeurs
        template <class S, class A>
        mdp <S, A>::~ mdp () 
        {
                delete [] state;
                delete [] action;
                //delete [] reset;
                //delete [] possible_action;
                //delete [] environnement;
                //delete [] is_terminal;
               }
//Surcharge d'opérateurs
        template<class S, class A> 
        mdp < S, A> & mdp <S, A>::operator = (const mdp <S, A> & p) {
                if (&p != this)
                {
                  this->ns = p.ns;
                  this->na = p.na;
                  for (int i = 0; i < ns; i++)
                      {
                           this->state[i] = p.state[i];
                      }
                  for (int j = 0; j < na; j++)
                      {
                            this->action[j] = p.action[j];
                      }
                        
                  this->reset = p.reset;
                  this->possible_action = p.possible_action;
                  this->is_terminal = p.is_terminal;
                        
                }

                return *this;
        }
        template<class S, class A>
        S& mdp<S, A>::operator[](int s) {
        return state[s];
       }
       template<class S, class A>
       A& mdp<S, A>::operator()(int a) {
        return action[a];
      }
               

