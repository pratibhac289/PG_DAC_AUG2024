//2. Write a C++ program to swap three numbers using function templates.

#include <iostream>
using namespace std;

// Function template to swap three numbers
template <typename T>
void swapThree(T &a, T &b, T &c) {
    T temp;
   
    temp = a;
    a = b;
    b = c;
    c = temp;
}

int main() {
    
    int x = 1, y = 2, z = 3;
    cout << "Before swap (int): x = " << x << ", y = " << y << ", z = " << z << endl;
    swapThree(x, y, z);
    cout << "After swap (int): x = " << x << ", y = " << y << ", z = " << z << endl;
}
