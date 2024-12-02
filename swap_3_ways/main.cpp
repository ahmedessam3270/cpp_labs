#include <iostream>
using namespace std;


void swapPointer(int *a, int *b);
void swapReference(int &a, int &b);
int main() {

int x = 10;
int z = 33;

cout << "Before swap x = " << x << endl;
cout << "Before swap z = " << z << endl;
swapReference(x, z);
cout << "After swap x = " << x << endl;
cout << "After swap z = " << z << endl;

// swaping by value, I can't do it using another function with another scope
// after calling the function the values will not be changed
// as the scope will be deterorated after the function ends
int a = 19,b = 67;
cout << "Before swap a = " << a << endl;    
cout << "Before swap b = " << b << endl;
int temp = a;
a = b;
b = temp;
cout << "After swap a = " << a << endl;
cout << "After swap b = " << b << endl;

// swaping by pointer
int num1 = 10;
int num2 = 20;
cout << "Before swap num1 = " << num1 << endl;
cout << "Before swap num2 = " << num2 << endl;
swapPointer(&num1, &num2);
cout << "After swap num1 = " << num1 << endl;
cout << "After swap num2 = " << num2 << endl;

return 0;
}

void swapPointer (int *a, int *b) {
int temp = *a;
*a = *b;
*b = temp;
}

void swapReference (int &a, int &b) {
int temp = a;
a = b;
b = temp;
}