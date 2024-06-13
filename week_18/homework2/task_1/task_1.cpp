#include <iostream>


struct ComplexNumber {

    double real;
    double imaginary;

};

ComplexNumber Add(ComplexNumber a, ComplexNumber b)
{
    ComplexNumber result;
    result.real = a.real + b.real;
    result.imaginary = a.imaginary + b.imaginary;
    return result;
}

ComplexNumber subtract(ComplexNumber a, ComplexNumber b)
{
    ComplexNumber result;
    result.real = a.real - b.real;
    result.imaginary = a.imaginary - b.imaginary;
    return result;
}

ComplexNumber multiply(ComplexNumber a, ComplexNumber b)
{
    ComplexNumber result;
    result.real = a.real * b.real - a.imaginary * b.imaginary;
    result.imaginary = a.real * b.imaginary + a.imaginary * b.real;
    return result;
}

ComplexNumber divide(ComplexNumber a, ComplexNumber b)
{
    ComplexNumber result;
    result.real = (a.real * b.real + a.imaginary * b.imaginary) / (b.real * b.real + b.imaginary * b.imaginary);
    result.imaginary = a.real * b.imaginary - a.imaginary * b.real / (b.real * b.real + b.imaginary * b.imaginary);
    return result;
}
int main()
{
    ComplexNumber num1 = { 1,2 };
    ComplexNumber num2 = { 3,3 };

    std::cout << Add(num1, num2).real <<" " << Add(num1, num2).imaginary <<"i"<< std::endl;

    std::cout << subtract(num1, num2).real << " " << subtract(num1, num2).imaginary << "i" << std::endl;

    std::cout << multiply(num1, num2).real << " " << multiply(num1, num2).imaginary << "i" << std::endl;

    std::cout << divide(num1, num2).real << " " << divide(num1, num2).imaginary << "i" << std::endl;

    return 0;
}

