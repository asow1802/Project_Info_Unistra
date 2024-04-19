#include <cmath>

#include "triangle.hpp"

#ifndef TOL
        #define TOL     1.e-9
#endif

bool triangle::operator < (const triangle & t)
{
        return this->get_h() < t.get_h();
}

bool triangle::operator > (const triangle & t)
{
        return this->get_h() > t.get_h();
}

bool triangle::operator == (const triangle & t)
{
        return (fabs(this->get_h() - t.get_h()) < TOL);
}

bool triangle::operator != (const triangle & t)
{
        return !((* this) == t);
}

double triangle::aire () 
{
    return 0.5 * fabs((M_p1 ^ M_p2) + (M_p2 ^ M_p3) + (M_p3 ^ M_p1));
}


point triangle::barycentre () 
{
    point ret;
    ret = ((M_p1 + M_p2) * (M_p1 ^ M_p2) 
         + (M_p2 + M_p3) * (M_p2 ^ M_p3) 
         + (M_p3 + M_p1) * (M_p3 ^ M_p1)) 
        * (1. / 6 / this->aire());
    return ret;    
}

bool triangle::contient_point (point p)
{
        double u = (M_p1 - p) ^ (M_p2 - p);
        double v = (M_p2 - p) ^ (M_p3 - p);
        double w = (M_p3 - p) ^ (M_p1 - p);

        // Pour savoir si u, v et w ont le même signe, on les teste deux à 
        // deux.

        return (u * v > - TOL) && (v * w > - TOL);
}


// Test de constructeurs, accesseurs et mutateurs, set h.
int triangle::testu_1() 
{ 
        int ret = 0;
        triangle t1; 

        if ((t1.get_p1() == point(0,0)) && (t1.get_p2() == point(1,0))
            && (t1.get_p3() == point(0,1)) 
            && (fabs(t1.get_h() - sqrt(2) < TOL)))
                ret += 1;

        point p1(4,5);      
        point p2(5,4);      
        point p3(-1,1);     
        t1.set_p1(p1); 
        t1.set_p2(p2); 
        t1.set_p3(p3); 

        if ((t1.get_p1() == p1) && (t1.get_p2() == p2) && (t1.get_p3() == p3)
            && (t1.get_s1().get_p1() == p1) && (t1.get_s1().get_p2() == p2) 
            && (t1.get_s2().get_p1() == p2) && (t1.get_s2().get_p2() == p3) 
            && (t1.get_s3().get_p1() == p3) && (t1.get_s3().get_p2() == p1) 
            && (t1.get_ns() == 3))
                ret += 1;

        return ret / 2;
}

// Test de comparaison.
int triangle::testu_2() 
{ 
        int ret = 0;
        
        triangle t1; // h = sqrt(2)
        triangle t2(point(), point(0,5), point(2.5, 0.1)); // h = 5
        triangle t3(point(1,1), point(1,2), point(2,1)); // h = sqrt(2)

        if ((t1 == t3) && (t1 != t2) && (t1 < t2) && (t2 > t3)) 
                ret += 1;
        

        return ret;
}

// Test d'aire et barycentre.
int triangle::testu_3() 
{ 
        int ret = 0;
        triangle t = triangle(point(1,2), point(4,2), point(1,6));

        if (fabs(t.aire() - 6) < TOL) 
                ret += 1;

        point p = t.barycentre();

        if (fabs(p.get_x() - 2) < TOL) 
                ret += 1;

        if (fabs(p.get_y() - 10./3) < TOL) 
                ret += 1;

        return ret / 3;
}

// Test de set_h
int triangle::testu_4() 
{ 
        int ret = 0;
        point p1 = point(0, 0);
        point p2 = point(1, 0);
        point p3 = point(0, 1);
        double h_th = sqrt(2);
        triangle t = triangle(p1, p2, p3);

        if (fabs(h_th - t.get_h()) < TOL) 
                ret += 1;

        return ret;
}

// Test de contient_point.
int triangle::testu_5() 
{ 
        int ret = 0;
        point p1(0.5, 0.5);
        point p2(1.5, 3.);
        point p3(3., -1.);
        triangle t(p1, p2, p3);

        point int1(1.5, 0.5);
        point int2(2.4, -0.3);
        point ext1(2., 1.7);
        point ext2(1., -0.5);

        if (t.contient_point(int1) && t.contient_point(int2))
                ret += 1;
        
        if (!(t.contient_point(ext1) && !(t.contient_point(ext2))))
                ret += 1;

        return ret / 2;
}

int triangle::all_testu ()
{
        int ret = 0;
        ret += triangle::testu_1();
        ret += triangle::testu_2();
        ret += triangle::testu_3();
        ret += triangle::testu_4(); 
        ret += triangle::testu_5();
        std::cout << ret << "/5 tests de triangle passés !" << std::endl;
        return ret - 5;
}

