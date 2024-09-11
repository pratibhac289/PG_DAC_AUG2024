//1. Using class templates in C++ perform various operations such as addition,
//subtraction, multiplication, division and modulus.
//Template questions

#include <iostream>
using namespace std;

// Overloaded modulus function for integral types
int modulus(int a, int b) {
    if (b != 0)
        return a % b;
    else {
        cout << "Division by zero error!" << endl;
        return 0;
    }
}

// Base template for modulus function for non-integral types
template <typename T>
T modulus(T a, T b) {
    cout << "Modulus operation not valid for non-integral types!" << endl;
    return 0;
}

template <typename T> // T is a template parameter stands for "type"
class Calculate {
public:
    T add(T a, T b) {
        return a + b;
    }

    T subtract(T a, T b) {
        return a - b;
    }

    T divide(T a, T b) {
        if (b != 0)
            return a / b;
        else {
            cout << "Division by zero error!" << endl;
            return 0;
        }
    }

    T modulus(T a, T b) {
        return ::modulus(a, b); // Call the global modulus function
    }
};

int main() {
    Calculate<int> intCalc;
    cout << "Addition (int): " << intCalc.add(10, 5) << endl;
    cout << "Subtraction (int): " << intCalc.subtract(3, 17) << endl;
    cout << "Division (int): " << intCalc.divide(6, 3) << endl;
    cout << "Modulus (int): " << intCalc.modulus(7,3) << endl;

    Calculate<double> doubleCalc;
    cout << "Modulus (double): " << doubleCalc.modulus(10.5, 5.2) << endl;

    return 0;
}

