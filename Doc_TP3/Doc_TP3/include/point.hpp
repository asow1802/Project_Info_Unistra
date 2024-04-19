#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

class point 
{

private:

        double M_x; // abscisse
        double M_y; // ordonnée

public:

        // Constructeurs et destructeur

        point () : M_x(0.), M_y(0.) {}
        point (double x, double y) : M_x(x), M_y(y) {}
        point (const point & p) : M_x(p.M_x), M_y(p.M_y) {}

        ~ point () {}

        // Accesseurs et mutateurs

        double get_x () const { return M_x; }
        double get_y () const { return M_y; }

        void set_x (double x) { M_x = x; }
        void set_y (double y) { M_y = y; }

        // Autres méthodes

        point operator + (const point &);
        point operator - (const point &);
        point operator * (const double);
        point & operator = (const point &);
        double operator , (const point &);
        double operator ^ (const point &);
        bool operator < (const point &);
        bool operator > (const point &);
        bool operator == (const point &);
        bool operator != (const point &);

        double norme () const;

        // Tests

        static int testu_1 (); // static: appelable sans instance de classe
        static int testu_2 ();
        static int testu_3 ();
        static int all_testu ();

        // Autre

        friend std::ostream & operator << (std::ostream &, const point &);
};

#endif
