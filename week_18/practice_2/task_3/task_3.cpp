#include <iostream>


struct fraction
{
    int numerator;
    int denominator;
    int total = 0;
};

void ReductionFraction(fraction& fraction)
{
    for (size_t i = 2; i < fraction.numerator && i < fraction.denominator; ++i)
    {
        if ((fraction.numerator % i == 0) && (fraction.denominator % i == 0))
        {
            fraction.numerator /= i;
            fraction.denominator /= i;
        }
    }
}

fraction Add(fraction& fraction_1, fraction& fraction_2)
{
    fraction result;

    if (fraction_1.denominator == fraction_2.denominator)
    {
        result.numerator = fraction_1.numerator + fraction_2.numerator;
        result.denominator = fraction_1.denominator;
    }
    else
    {
        result.numerator = (fraction_1.numerator * fraction_2.denominator) + (fraction_2.numerator * fraction_1.denominator);
        result.denominator = fraction_1.denominator * fraction_2.denominator;
    }

    ReductionFraction(result);
    return result;
}

fraction Subtract(fraction& fraction_1, fraction& fraction_2)
{
    fraction result;

    if (fraction_1.denominator == fraction_2.denominator)
    {
        result.numerator = fraction_1.numerator - fraction_2.numerator;
        result.denominator = fraction_1.denominator;
    }
    else
    {
        result.numerator = (fraction_1.numerator * fraction_2.denominator) - (fraction_2.numerator * fraction_1.denominator);
        result.denominator = fraction_1.denominator * fraction_2.denominator;
    }

    ReductionFraction(result);
    return result;
}

fraction Multiply(fraction& fraction_1, fraction& fraction_2)
{
    fraction result;

    result.numerator = fraction_1.numerator * fraction_2.numerator;
    result.denominator = fraction_1.denominator * fraction_2.denominator;

    ReductionFraction(result);
    return result;
}

fraction Divide(fraction& fraction_1, fraction& fraction_2)
{
    fraction result;

    std::swap(fraction_2.numerator, fraction_2.denominator);
    result = Multiply(fraction_1, fraction_2);

    ReductionFraction(result);
    return result;
}

void PrintFraction(fraction& Fraction)
{
    std::cout << "Целое число " << Fraction.total << std::endl;;
    std::cout << Fraction.numerator << std::endl
        << Fraction.denominator << std::endl;
}

int main()
{
    setlocale(LC_ALL, "rus");

    fraction A = { 1,10 };
    fraction B = { 3,10 };

    fraction C = Add(A,B);
    PrintFraction(C);

    return 0;
}
