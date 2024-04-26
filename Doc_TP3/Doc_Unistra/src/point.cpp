#include <cmath>

#include "point.hpp"

#ifndef TOL
        #define TOL     1.e-9
#endif

point point::operator + (const point & p)
{
        point ret;
        ret.M_x = M_x + p.M_x;
        ret.M_y = M_y + p.M_y;
        return ret;
}

point point::operator - (const point & p)
{
        point ret;
        ret.M_x = M_x - p.M_x;
        ret.M_y = M_y - p.M_y;
        return ret;
}

point point::operator * (const double a)
{
        return point(M_x * a, M_y * a);
}

point & point::operator = (const point & p)
{
        if (& p != this)
        {
                M_x = p.M_x;
                M_y = p.M_y;
        }
        return * this;
}

double point::operator , (const point & p)
{
        double ret = M_x * p.M_x + M_y * p.M_y;
        return ret;
}

double point::operator ^ (const point & p)
{
        double ret = M_x * p.M_y - M_y * p.M_x;
        return ret;
}

bool point::operator < (const point & p)
{
        return this->norme() < p.norme();
}

bool point::operator > (const point & p)
{
        return this->norme() > p.norme();
}

bool point::operator == (const point & p)
{
        return (fabs(M_x - p.M_x) < TOL) && (fabs(M_y - p.M_y) < TOL);
}

bool point::operator != (const point & p)
{
        return !((* this) == p);
}

double point::norme () const
{
        return sqrt(M_x * M_x + M_y * M_y);
}

// Test des constructeurs, accesseurs, mutateurs, opérateurs =, !=, ==.
// Renvoie 0 si le test n'est pas bon, 1 sinon.
int point::testu_1 ()
{
        int ret = 0;
        point p1_ = point(3, -4);
        point p1(p1_);

        if ((fabs(p1.M_x - 3.) < TOL) && (fabs(p1.M_y + 4.) < TOL))
                ret += 1;

        point p;

        if ((fabs(p.M_x) < TOL) && (fabs(p.M_y) < TOL))
                ret += 1;

        p.set_x(10.);
        p.set_y(56.);
        
        if ((fabs(p.get_x() - 10.) < TOL) && (fabs(p.get_y() - 56.) < TOL))
                ret += 1;

        if (p == point(10., 56.))
                ret += 1;
        
        if (p != point(10., 42.))
                ret += 1;

        p = p1;
        if (p == p1)
                ret += 1;

        return ret / 6;
}

// Test des opérations
int point::testu_2 () 
{ 
        int ret = 0;
        point p1 = point(1, -6);
        point p2 = point(-3, 4);

        if (p1 + p2 == point(-2, -2)) 
                ret += 1;

        if (p1 - p2 == point(4, -10)) 
                ret += 1;

        if (fabs((p1,p2) + 27) < TOL) 
                ret += 1;

        if (fabs((p1^p2) + 14) < TOL) 
                ret += 1;

        if (fabs(p1.norme() - sqrt(37)) < TOL) 
                ret += 1;

        point p3 = point(1, -1);
        point p4 = p1 - p2 + p3;
        if ((fabs(p4.M_x - 5.) < TOL) && (fabs(p4.M_y + 11.) < TOL))
                ret += 1;

        point p5 = p4 * 2;

        if ((fabs(p5.M_x - 10.) < TOL) && (fabs(p5.M_y + 22.) < TOL))
                ret += 1;

        return ret / 6;
}

// Test des comparaisons
int point::testu_3 () 
{ 
    int ret = 0;
    point p = point(1, 2);
    point q = point(3, -7);

    if (p < q) 
        ret += 1;

    if (!(p > q)) 
        ret += 1;

    return ret / 2;
}

int point::all_testu ()
{
        int ret = 0;
        ret += point::testu_1();
        ret += point::testu_2();
        ret += point::testu_3();
        std::cout << ret << "/3 tests de point passés !" << std::endl;
        return 3 - ret;
}

std::ostream & operator << (std::ostream & out, const point & p)
{
        out << "(" << p.M_x << "," << p.M_y << ")";
        return out;
}