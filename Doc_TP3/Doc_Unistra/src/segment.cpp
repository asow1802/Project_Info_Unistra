#include <cmath>

#include "segment.hpp"

#ifndef TOL
        #define TOL     1.e-9
#endif

// norme 2
double segment::longueur ()
{
        return sqrt(pow(M_p2.get_x() - M_p1.get_x(), 2) 
                  + pow(M_p2.get_y() - M_p1.get_y(), 2));
}

point segment::milieu ()
{
        point ret;
        ret.set_x(0.5 * (M_p1.get_x() + M_p2.get_x()));
        ret.set_y(0.5 * (M_p1.get_y() + M_p2.get_y()));
        return ret;
}

point segment::intersection (segment s)
{
        point ret;
        double a, b; // Pente et ordonnée à l'origine de * this.
        double as, bs; // Pente et ordonnée à l'origine de s.

        // On extraie les coordonnées pour rendre la suite plus agréable.
        double x1 = M_p1.get_x(), y1 = M_p1.get_y();
        double x2 = M_p2.get_x(), y2 = M_p2.get_y();
        double x3 = s.M_p1.get_x(), y3 = s.M_p1.get_y();
        double x4 = s.M_p2.get_x(), y4 = s.M_p2.get_y();

        // Cas où aucun segment n'est vertical.
        if ((fabs(x2 - x1) > TOL) && (fabs(x4 - x3) > TOL))
        {
                a = (y2 - y1) / (x2 - x1);
                as = (y4 - y3) / (x4 - x3);

                // Cas où les droites ne sont pas parallèles.
                if (fabs(as - a) > TOL) 
                {
                        b = y2 - a * x2;
                        bs = y4 - as * x4;
                        ret.set_x((bs - b) / (a - as));
                        ret.set_y(a * ret.get_x() + b);
                }
                else
                        std::cout << "Erreur: pas d'intersection, segments "
                                     "parallèles" << std::endl;
                
        }
        else
        {
                if ((fabs(x2 - x1) < TOL) && (fabs(x4 - x3) < TOL))
                        std::cout << "Erreur: pas d'intersection, segments "
                                     "parallèles" << std::endl;
                else if (fabs(x2 - x1) < TOL) // Cas où * this est vertical.
                {
                        as = (y4 - y3) / (x4 - x3);
                        bs = y4 - as * x4;
                        ret.set_x(x2);
                        ret.set_y(as * ret.get_x() + bs);
                }
                else // Cas où s est vertical.
                {
                        a = (y2 - y1) / (x2 - x1);
                        b = y2 - a * x2;
                        ret.set_x(x4);
                        ret.set_y(a * ret.get_x() + b);
                }
        }        
        return ret;
}

// Test des constructeurs, accesseurs, mutateurs.
// Renvoie 0 si le test n'est pas bon, 1 sinon.
int segment::testu_1 () { 
        int ret = 0;
        segment s;

        if ((s.M_p1 == point(0,0)) && (s.M_p2 == point(0,1))) 
                ret += 1;

        point p = point(7,4);
        s = segment(p);

        if ((s.M_p1 == point(0,0)) && (s.M_p2 == p)) 
                ret += 1;

        point p1 = point(2,-3);
        s = segment(p, p1);

        if ((s.M_p1 == p) && (s.M_p2 == p1)) 
                ret += 1;

        s = segment();
        s.set_p1(p);
        s.set_p2(p1);

        if ((s.get_p1() == p) && (s.get_p2() == p1)) 
                ret += 1;

        segment s_(s);

        if ((s_.get_p1() == p) && (s_.get_p2() == p1)) 
                ret += 1;

        return ret / 5;
}

// Test de longueur et milieu.
int segment::testu_2() { 
        int ret = 0;
        point p1 = point(2, 1);
        point p2 = point(5, 5);
        segment s = segment(p1, p2);

        if (abs(s.longueur() - 5) < TOL) 
                ret += 1;

        if (s.milieu() == point(3.5, 3)) 
                ret += 1;

        return ret / 2;
}

// Test de l'intersection.
int segment::testu_3() { 
        int ret = 0;
        point p1 = point(-2, 0);
        point p2 = point(-1, -2);
        point p3 = point(1, -1);
        point p4 = point(3, 1);
        segment s1 = segment(p1, p2);
        segment s2 = segment(p3, p4);
        point inters = point(-2./3, -8./3);

        if (inters == s1.intersection(s2)) 
                ret += 1;

        point p5 = point(1, 4);
        s2.set_p2(p5);
        inters = point(1, -6);

        if (inters == s1.intersection(s2)) 
                ret += 1;

        return ret / 2;
}

int segment::all_testu ()
{
        int ret = 0;
        ret += segment::testu_1();
        ret += segment::testu_2();
        ret += segment::testu_3();
        std::cout << ret << "/3 tests de segment passés !" << std::endl;
        return 3 - ret;
}

std::ostream & operator << (std::ostream & out, const segment & s)
{
        out << s.M_p1 << " " << s.M_p2;
        return out;
}