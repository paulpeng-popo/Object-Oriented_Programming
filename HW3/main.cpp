#include <iostream>
#include "Complex.h"

using std::cout;
using std::endl;

int main()
{
    Complex a(77, 66.3);
    Complex b(a);
    int i = 1;

    cout << i++ << ": (" << a.Real() << ',' << a.Imag() << ')' << endl; // 1
    cout << i++ << ": " << b << endl;                                   // 2
    cout << i++ << ": " << Norm(b) << endl;                             // 3
    cout << i++ << ": " << b.Norm() << endl;                            // 4
    cout << i++ << ": " << Abs(b) << endl;                              // 5
    cout << i++ << ": " << b.Abs() << endl;                             // 6
    cout << i++ << ": " << Arg(b) << endl;                              // 7
    cout << i++ << ": " << b.Arg() << endl;                             // 8

    a = Complex(12, 33.2);
    cout << i++ << ": " << a << endl;                                   // 9
    cout << i++ << ": " << 1+a << endl;                                 // 10

    cout << i++ << ": " << a++ << endl;                                 // 11
    cout << i++ << ": " << ++a << endl;                                 // 12

    b = a.Polar(5.6, 1.8);

    cout << i++ << ": " << a << endl;                                   // 13
    cout << i++ << ": " << b << endl;                                   // 14

    b = Polar(6.5, 8.1);
    cout << i++ << ": " << b << endl;                                   // 15

    cout << i++ << ": " << a+b << endl;                                 // 16
    cout << i++ << ": " << a-b << endl;                                 // 17
    cout << i++ << ": " << a*b << endl;                                 // 18
    cout << i++ << ": " << a/b << endl;                                 // 19

    a /= b;
    cout << i++ << ": " << a << endl;                                   // 20
    a /= Complex(4, 3);
    cout << i++ << ": " << a << endl;                                   // 21

    a *= b;
    cout << i++ << ": " << a << endl;                                   // 22
    a *= Polar(5.1, 5.1);
    cout << i++ << ": " << a << endl;                                   // 23

    a += b;
    b -= a;
    cout << i++ << ": " << b << endl;                                   // 24

    if (!(a == b))
    cout << i++ << ": " << "OK" << endl;                                // 25
    if (a != b)
    cout << i++ << ": " << "OK" << endl;                                // 26
}
