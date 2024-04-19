#include <cmath>

#include "quadrangle.hpp"

#ifndef TOL
        #define TOL     1.e-9
#endif

double quadrangle::aire() 
{
    return 0.5 * ((M_p1 ^ M_p2) + (M_p2 ^ M_p3) 
                + (M_p3 ^ M_p4) + (M_p4 ^ M_p1));
}

point quadrangle::barycentre() 
{
    return ((M_p1 + M_p2) * (M_p1 ^ M_p2) 
          + (M_p2 + M_p3) * (M_p2 ^ M_p3) 
          + (M_p3 + M_p4) * (M_p3 ^ M_p4) 
          + (M_p4 + M_p1) * (M_p4 ^ M_p1)) 
          * (1. / 6. / this->aire());
}

// Renvoie vrai si le point p appartient au quadrangle, faux sinon.
bool quadrangle::contient_point(point p) 
{
        double l = (M_p1 - p) ^ (M_p2 - p);
        double m = (M_p2 - p) ^ (M_p3 - p);
        double n = (M_p3 - p) ^ (M_p4 - p);
        double o = (M_p4 - p) ^ (M_p1 - p);

        return  ((l * m > - TOL) && (m * n > - TOL) && (n * o > - TOL));
}

bool quadrangle::operator < (const quadrangle & q)
{
        return this->get_h() < q.get_h();
}

bool quadrangle::operator > (const quadrangle & q)
{
        return this->get_h() > q.get_h();
}

bool quadrangle::operator == (const quadrangle & q)
{
        return (fabs(this->get_h() - q.get_h()) < TOL);
}

bool quadrangle::operator != (const quadrangle & q)
{
        return !((* this) == q);
}

// Test constructeurs, accesseurs, mutateurs
int quadrangle::testu_1 () 
{ 
        int ret = 0;
        quadrangle q = quadrangle(point(1,2), point(4,2), 
                                  point(1,6), point(-1, 3));

        if ((q.get_p1() == point(1,2)) && (q.get_p2() == point(4,2)) 
         && (q.get_p3() == point(1,6)) && (q.get_p4() == point(-1,3))) 
                ret += 1;

        point p = point(1, 3);

        q.set_p1(p); q.set_p2(p); q.set_p3(p); q.set_p4(p);

        if ((q.get_p1() == p) && (q.get_p2() == p) && (q.get_p3() == p) 
         && (q.get_p4() == p) && (q.get_ns() == 4)) 
                ret += 1;
        
        quadrangle q1;
        q1.set_p3(point(3,0));

        if (fabs(q1.get_h() - sqrt(10)) < TOL) 
                ret += 1;

        return ret / 3;
}

// Test aire, barycentre
int quadrangle::testu_2 () 
{ 
        int ret = 0;
        quadrangle q = quadrangle(point(0, 0), point(1, -1), 
                                  point(2, 0), point(1, 1));

        if (fabs(q.aire() - 2) < TOL) 
                ret += 1;

        if (q.barycentre() == point(1,0)) 
                ret += 1;

        return ret / 2;
}

// Test contient_point.
int quadrangle::testu_3 () 
{ 
    int ret = 0;
    quadrangle q = quadrangle(point(0, 0), point(1, -1),
                              point(2, 0), point(1, 1));
    if (q.contient_point(point(1, 0.5)))
        ret += 1;
    
    if (! q.contient_point(point(-1, 0))) 
        ret += 1;

    return ret / 2;
}

// Test comparaisons.
int quadrangle::testu_4 () 
{ 
        int ret = 0;

        quadrangle q1; // h = 1
        quadrangle q2(point(), point(0,2), point(2,2), point(2,0)); // h = 2
        quadrangle q3(point(0.5, 0.5), point(0.5,1.5),
                      point(1.5,1.5), point(1.5,0.5)); // h = 1

        if ((q1 == q3) && (q1 != q2) && (q1 < q2) && (q2 > q3)) 
                ret += 1;

        return ret;
}

int quadrangle::all_testu ()
{
        int ret = 0;
        ret += quadrangle::testu_1();
        ret += quadrangle::testu_2();
        ret += quadrangle::testu_3();
        ret += quadrangle::testu_4();
        std::cout << ret << "/4 tests de quadrangle passés !" << std::endl;
        return 4 - ret;
}

std::ostream & operator << (std::ostream & out, const quadrangle & q)
{
        out << "(" << q.M_p1 << "," << q.M_p2;
        out << "," << q.M_p3 << "," << q.M_p4; 
        out << ")";
        return out;
}

std::istream & operator >> (std::istream & in, quadrangle & q)
{
        double x, y;

        std::cout << "Entrez les coordonnées du premier point: ";
        in >> x >> y;
        q.set_p1(point(x,y));

        std::cout << "Entrez les coordonnées du deuxième point: ";
        in >> x >> y;
        q.set_p2(point(x,y));

        std::cout << "Entrez les coordonnées du troisième point: ";
        in >> x >> y;
        q.set_p3(point(x,y));

        std::cout << "Entrez les coordonnées du quatrième point: ";
        in >> x >> y;
        q.set_p4(point(x,y));
        
        return in;
}

