#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <cmath>
#include <initializer_list>
#include <algorithm>
#include "point.hpp"
#include "segment.hpp"

template <class S, class A>  class  mdp 
{
   private:
      int ns, na;
      S *state;
      A *action;
   public:
      S *reset(int n, S *s){
        return s[n];
      }
      int *possible_action(S s, A const &a){
        int n;
        for (int i = 0; i < ns; i++)
        {
                if (state[i] == s)
                {
                        n = i;
                } 
        }
        a  = new A[na - n];
        return (na -a);
        
      }

      void *environnement(S sta, A act, double &n, S &s){
        return NULL;
      }
      bool *is_terminal(S s, int n){
        return s[n+1] == NULL;
      }
};
#endif
