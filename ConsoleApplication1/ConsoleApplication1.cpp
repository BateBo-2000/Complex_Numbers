#include <iostream>
#include "ComplexNumber.h"

int main() {
    using std::cout;
    using std::cin;
    using std::endl;

    ComplexNumber a(3, 4);
    ComplexNumber b(1, -2);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    cout << "Unary +a = " << +a << endl;
    cout << "Unary -a = " << -a << endl;

    ComplexNumber c = a + b;
    cout << "a + b = " << c << endl;

    c = a - b;
    cout << "a - b = " << c << endl;

    c = a * b;
    cout << "a * b = " << c << endl;

    c = a / b;
    cout << "a / b = " << c << endl;

    c += a;
    cout << "c += a " << c << endl;

    c *= b;
    cout << "c *= b " << c << endl;

    cout << "a == b " << (a == b ? "true" : "false") << endl;
    cout << "a != b " << (a != b ? "true" : "false") << endl;

    cout << "3 + a = " << (3 + a) << endl;
    cout << "-3.14 * b = " << (-3.14 * b) << endl;

    ComplexNumber z;
    z.Re(10);
    z.Im(20);
    cout << "z after setters = " << z << endl;
    cout << "z.Re() = " << z.Re() << ", z.Im() = " << z.Im() << endl;

    ComplexNumber inputZ;
    cout << "Enter a complex number (real + i imag): ";
    cin >> inputZ;
    cout << "You entered: " << inputZ << endl;

    return 0;
}
