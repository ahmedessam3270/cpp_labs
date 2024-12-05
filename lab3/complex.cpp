#include "stdio.h"
#include <iostream>

using namespace std;

class Complex
{
private:
    int real;
    int imag;

public:
    // Constructors function
    Complex (int real , int image){
        this->real= real;
        this->imag = image;
    }

    Complex (int real){
        this->real= real;
        this->imag = 0;
    }

    Complex (){
        this->real = 0;
        this->imag = 0;
    }
    // Copy Constructor 

    Complex (const Complex &instance){
        this->real = instance.real;
        this->imag = instance.imag;
    }

    // Destructor function
    ~Complex (){
        cout << "The Object is now Dead :(" << endl;
    }

    // Setter Member functions
    void setReal(int value)
    {
        real = value;
    }
    void setImag(int value)
    {
        imag = value;
    }
    // setComplex
    void setComplex(int realValue, int imagValue)
    {
        real = realValue;
        imag = imagValue;
    }

    // Getter member functions
    int getReal()
    {
        return real;
    }
    int getImag()
    {
        return imag;
    }

    Complex add(Complex &otherObject)
    {
        Complex result;
        result.setComplex(
            real + otherObject.real,
            imag + otherObject.imag);
        return result;
    }
    Complex sub(Complex &otherObject)
    {
        Complex result;
        result.setComplex(
            real - otherObject.real,
            imag - otherObject.imag);
        return result;
    }

    // Operators Overloading

    // plus operator with an integar
    Complex operator+(int real){
        this->real = this->real + real;
        return *this;
    }

    // plus operator with another complex
    Complex operator+(Complex addedComplex){
        Complex c;
        c.real =this->real + addedComplex.real;
        c.imag =this->imag + addedComplex.imag;
        return c;
    }

      // minus operator with an integar
    Complex operator-(int real){
        this->real = this->real - real;
        return *this;
    }

    // minus operator with another complex
    Complex operator-(Complex addedComplex){
        Complex c;
        c.real =this->real - addedComplex.real;
        c.imag =this->imag - addedComplex.imag;
        return c;
    }

    // Prefix operator  
    Complex operator++ (){
        this->real++;
        this->imag++;
        return *this;
    }

    // Postfix operator
    Complex operator++(int unusedInt){
        Complex  temp;
        temp = *this;
        this->real++;
        this->imag++;
        return temp;
    }

    void display() {
    if (real == 0 ) {
        if (imag != 0) {
            cout << imag << "j" << endl;
        } else {
            cout << "No Data" << endl;
        }
    } else {
        if (imag == 0) {
            cout << real << endl;
        } else {
            cout << real << (imag > 0 ? "+" : "") << imag << "j" << endl;
        }
    }
}
};

int main()
{
    /*Complex num_1;
    num_1.setComplex(13, 0);
    // real only
    num_1.display();

    Complex num_2;
    num_2.setComplex(0, -49);
    //imag only
    num_2.display();


    Complex num_3;
    num_3.setComplex(0, 0);
    // 0 0 case
    num_3.display();


    Complex result = num_1.add(num_2);
    //full case negative
    result.display();

    result.setImag(12);
    //full case positive
    result.display();*/

    Complex c(43,2);
    c.display();
    Complex c_temp;
    c_temp = c++;
    c_temp.display();
    c.display();
    Complex test;
    test = c + 3;
    cout << "test display :";
    test.display();
    Complex complexAddingResult;
    complexAddingResult = c + c_temp;
    cout << "Complex adding result :";
    complexAddingResult.display();

    Complex complexSubtractingResult;
    complexSubtractingResult = c - c_temp;
    cout << "Complex subtracting result :";
    complexSubtractingResult.display();
}