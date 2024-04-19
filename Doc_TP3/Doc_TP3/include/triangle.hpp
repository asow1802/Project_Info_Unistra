#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <cmath>
#include <initializer_list>
#include <algorithm>
#include "point.hpp"
#include "segment.hpp"

class triangle 
{

private:

        point M_p1;
        point M_p2;
        point M_p3;
        segment M_s1;
        segment M_s2;
        segment M_s3;
        double M_h; // longueur caractéristique
        static const int M_ns = 3; // nombre de sommets


public:

        // Constructeurs et destructeur

        triangle () : M_p1(0., 0.), M_p2(1., 0.), M_p3(0., 1.), 
                      M_s1(M_p1, M_p2), M_s2(M_p2, M_p3), M_s3(M_p3, M_p1)
        {
                this->set_h();
        }

        triangle (point p1, point p2, point p3) : 
                      M_p1(p1), M_p2(p2), M_p3(p3),
                      M_s1(M_p1, M_p2), M_s2(M_p2, M_p3), M_s3(M_p3, M_p1)
        {
                this->set_h();
        }

        ~ triangle () {}

        // Accesseurs et mutateurs

        point get_p1 () const { return M_p1; }
        point get_p2 () const { return M_p2; }
        point get_p3 () const { return M_p3; }

        segment get_s1 () const { return M_s1; }
        segment get_s2 () const { return M_s2; }
        segment get_s3 () const { return M_s3; }

        int get_ns () const { return M_ns; }
        double get_h () const { return M_h; }

        void set_p1 (point p1) 
        { 
                M_p1 = p1; 
                M_s1.set_p1(p1);
                M_s3.set_p2(p1);
                this->set_h();
        }
        void set_p2 (point p2) 
        { 
                M_p2 = p2; 
                M_s1.set_p2(p2);
                M_s2.set_p1(p2);
                this->set_h();
        }
        void set_p3 (point p3) 
        { 
                M_p3 = p3; 
                M_s2.set_p2(p3);
                M_s3.set_p1(p3);
                this->set_h();
        }

        void set_h () 
        {
                double l1 = M_s1.longueur();
                double l2 = M_s2.longueur();
                double l3 = M_s3.longueur();

                M_h = std::max({l1, l2, l3});
        } 

        // Autres méthodes

        bool operator < (const triangle &);
        bool operator > (const triangle &);
        bool operator == (const triangle &);
        bool operator != (const triangle &);
        double aire ();
        point barycentre ();
        bool contient_point (point p);

        // Tests

        static int testu_1();
        static int testu_2();
        static int testu_3();
        static int testu_4();
        static int testu_5();
        static int all_testu();
};

#endif
