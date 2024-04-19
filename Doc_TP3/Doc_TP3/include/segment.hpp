#ifndef SEGMENT_HPP
#define SEGMENT_HPP

#include "point.hpp"

class segment 
{

private:

        point M_p1;
        point M_p2;

public:

        // Constructeurs et destructeur

        segment () : M_p1(0., 0.), M_p2(0., 1.) {}
        segment (point p) : M_p1(0., 0.), M_p2(p) {}
        segment (point p1, point p2) : M_p1(p1), M_p2(p2) {}

        ~segment () {};

        // Accesseurs et mutateurs

        point get_p1 () const { return M_p1; }
        point get_p2 () const { return M_p2; }

        void set_p1 (point p1) { M_p1 = p1; }
        void set_p2 (point p2) { M_p2 = p2; }

        // Autres méthodes

        double longueur ();
        point milieu ();
        point intersection (segment s);

        // Tests

        static int testu_1 ();
        static int testu_2 ();
        static int testu_3 ();
        static int all_testu ();

        // Autre

        friend std::ostream & operator << (std::ostream &, const segment &);
};

#endif
