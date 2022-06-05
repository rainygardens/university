#ifndef wymierna_hpp
#define wymierna_hpp

#include <iostream>
#include "exceptions.hpp"

namespace obliczenia {
    class wymierna {
        int licz, mian;

    public:
        wymierna(int licznik, int mianownik);
        wymierna(int licznik);
        wymierna(const wymierna& rational);
        wymierna(wymierna&& rational);
        ~wymierna();

        int get_licznik();
        int get_mianownik();

        friend wymierna operator+(wymierna &add1, wymierna &add2);
        friend wymierna operator-(wymierna &sub1, wymierna &sub2);
        friend wymierna operator*(wymierna &mult1, wymierna &mult2);
        friend wymierna operator/(wymierna &div1, wymierna &div2);
        friend wymierna operator-(wymierna &rational); // negative

        friend std::ostream& operator<<(std::ostream& out, wymierna &rational);
        friend std::istream& operator>>(std::istream& in, wymierna &rational);

        operator double();
        operator int();
    };

    wymierna operator+(wymierna &add1, wymierna &add2);
    wymierna operator-(wymierna &sub1, wymierna &sub2);
    wymierna operator*(wymierna &mult1, wymierna &mult2);
    wymierna operator/(wymierna &div1, wymierna &div2);
    wymierna operator-(wymierna &rational);
    wymierna operator!(wymierna &rational);

    std::ostream& operator<<(std::ostream& out, wymierna &rational);
    
    int gcd(int arg1, int arg2);
    int lcm(int arg1, int arg2);
};


#endif