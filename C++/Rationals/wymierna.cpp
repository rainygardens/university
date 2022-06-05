#include "wymierna.hpp"

using namespace obliczenia;

// constructors
wymierna::wymierna(int licznik, int mianownik)
{
    try
    {
        if(mianownik == 0)
        {
            throw rationalDivisionByZero("Division by 0! \n");
        }
        else if(mianownik < 0)
        {
            int curr_gcd = gcd(licznik, ((-1)*mianownik));
            this->mian = mianownik * (-1) / curr_gcd;
            this->licz = licznik * (-1) / curr_gcd;
            throw rationalNegativeDenumerator("Negative denumerator! \n");
        }
        else
        {
            this->mian = mianownik/gcd(licznik, mianownik);
            this->licz = licznik/gcd(licznik, mianownik);
        }
    }
    catch (rationalDivisionByZero)
    {
        std::cerr << "Object has not been constructed." << std::endl << std::endl;
    }
    catch (rationalNegativeDenumerator)
    {
        std::cerr << "Given number: " << licznik << " / " << mianownik << std::endl;
        std::cerr << "Converted number: " << this->get_licznik() << " / " << this->get_mianownik() << std::endl << std::endl;
    }
};

wymierna::wymierna(int licznik)
{
    this->licz = licznik;
    this->mian = 1;
};

wymierna::wymierna(const wymierna& rational)
{
    this->licz = rational.licz;
    this->mian = rational.mian;
};

wymierna::wymierna(wymierna&& rational)
{
    this->licz = rational.licz;
    this->mian = rational.mian;

    rational.licz = 0;
    rational.mian = 0;
};
// destructor
wymierna::~wymierna() {};

// getters
int wymierna::get_licznik()
{
    return licz;
};
int wymierna::get_mianownik()
{
    return mian;
};

// binary operators
wymierna obliczenia::operator+(wymierna &add1, wymierna &add2)
{
    int add_lcm = lcm(add1.get_mianownik(), add2.get_mianownik());
    int add_licz = (add1.get_licznik()*add_lcm/add1.get_mianownik()) + (add2.get_licznik()*add_lcm/add2.get_mianownik());
    wymierna result(add_licz, add_lcm);
    return result;
};
wymierna obliczenia::operator-(wymierna &sub1, wymierna &sub2)
{
    int sub_lcm = lcm(sub1.get_mianownik(), sub2.get_mianownik());
    int sub_licz = (sub1.get_licznik()*sub_lcm/sub1.get_mianownik()) - (sub2.get_licznik()*sub_lcm/sub2.get_mianownik());
    wymierna result(sub_licz, sub_lcm);
    return result;
};
wymierna obliczenia::operator*(wymierna &mult1, wymierna &mult2)
{
    int mult_licz = mult1.get_licznik() * mult2.get_licznik();
    int mult_mian = mult1.get_mianownik() * mult2.get_mianownik();
    wymierna result(mult_licz, mult_mian);
    return result;
};
wymierna obliczenia::operator/(wymierna &div1, wymierna &div2)
{
    int div_licz = div1.get_licznik() * div2.get_mianownik();
    int div_mian = div1.get_mianownik() * div2.get_licznik();
    wymierna result(div_licz, div_mian);
    return result;
};

// unary operators
wymierna obliczenia::operator-(wymierna &rational)
{
    int new_licz = (-1) * rational.get_licznik();
    int new_mian = rational.get_mianownik();
    wymierna result(new_licz, new_mian);
    return result;
};
wymierna obliczenia::operator!(wymierna &rational)
{
    wymierna result(rational.get_mianownik(), rational.get_licznik());
    return result;
};

// stream operator
std::ostream& obliczenia::operator<<(std::ostream& out, wymierna &rational)
{
    double converted = double(rational);
    out << converted ;
    return out;
};


// type-casting operators
wymierna::operator double()
{
    double converted = (licz / mian);
    return converted;
};

wymierna::operator int()
{
    int converted = licz / mian;
    return converted;
};

// aux functions
int obliczenia::gcd(int arg1, int arg2)
{
    int a = arg1;
    int b = arg2;
    int c;

    while(b != 0)
    {
        c = (a % b);
        a = b;
        b = c;
    }
    return a;
};
int obliczenia::lcm(int arg1, int arg2)
{
    int a = arg1;
    int b = arg2;
    int res = (a * b) / gcd(a, b);
    return res;
};
