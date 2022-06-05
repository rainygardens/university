#include <iostream>
#include "wymierna.hpp"

using namespace obliczenia;

int main()
{
    using namespace std;

    // constructors testing    

    wymierna rational1(4, 20);
    cout << "wymierna 1: " << rational1.get_licznik() << " / " << rational1.get_mianownik() << endl;
    wymierna rational2(5);
    cout << "wymierna 2: " << rational2.get_licznik() << " / " << rational2.get_mianownik() << endl;
    
    // operators testing
    wymierna sum(rational1 + rational2);
    cout << "suma: " << sum.get_licznik() << " / " << sum.get_mianownik() << endl;
    wymierna sub(rational2 - rational1);
    cout << "różnica: " << sub.get_licznik() << " / " << sub.get_mianownik() << endl;
    wymierna mult(rational1 * rational2);
    cout << "iloczyn: " << mult.get_licznik() << " / " << mult.get_mianownik() << endl;
    wymierna divi(rational1 / rational2);
    cout << "iloraz: " << divi.get_licznik() << " / " << divi.get_mianownik() << endl; 

    cout << "operator odwrotności:" << endl;
    wymierna minus_sum(!sum);
    cout << minus_sum.get_licznik() << " / " << minus_sum.get_mianownik() << endl;
    
    cout << sum << endl;
    int castedint = int(rational1);
    double casteddouble = double(rational1);

    cout << castedint << endl;
    cout << casteddouble << endl;

    // exceptions testing
    wymierna irrational(10, -536);
    wymierna irrational2(10, 0);
}