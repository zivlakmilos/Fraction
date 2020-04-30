/*
 * This file is part of Fraction C++ library (https://github.com/zivlakmilos/Fraction).
 * Copyright (c) 2020 Miloš Zivlak (milos@zivlak.rs).
 * 
 * This program is free software: you can redistribute it and/or modify  
 * it under the terms of the GNU General Public License as published by  
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but 
 * WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU 
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include <iostream>

#include <fraction.h>

int main(void)
{
    Fraction a(2, 10);
    Fraction b(3, 7);

    std::cout << "Simplify: " << a << " => " << a.simplify() << std::endl
              << "Multiply: " << a << " * " << b << " = " << a * b << std::endl
              << "Division: " << a << " / " << b << " = " << a / b << std::endl
              << "Addition: " << a << " + " << b << " = " << a + b << std::endl
              << "Subtraction: " << a << " - " << b << " = " << a - b << std::endl
              << std::endl;

    std::cout << a << " == " << b << " => " << (a == b ? "true" : "false") << std::endl
              << a << " != " << b << " => " << (a != b ? "true" : "false") << std::endl
              << a << " > " << b << " => " << (a > b ? "true" : "false") << std::endl
              << a << " < " << b << " => " << (a < b ? "true" : "false") << std::endl
              << a << " >= " << b << " => " << (a >= b ? "true" : "false") << std::endl
              << a << " <= " << b << " => " << (a <= b ? "true" : "false") << std::endl
              << std::endl;

    return 0;
}
