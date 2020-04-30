# Fraction
C++ Fraction library

## Instalation

## Example

```
#include <iostream>

#include <Fraction.h>

int main(void)
{
    Fraction a(2, 10);
    Fraction b(3, 7);

    std::cout << "Simplify: " << a << " => " << a.simplify() << std::endl;
    std::cout << "Multiply: " << a << " * " << b << " = " << a * b << std::endl;
    std::cout << "Division: " << a << " / " << b << " = " << a / b << std::endl;
    std::cout << "Addition: " << a << " + " << b << " = " << a + b << std::endl;
    std::cout << "Subtraction: " << a << " - " << b << " = " << a - b << std::endl;

    return 0;
}

```
