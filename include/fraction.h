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

#ifndef _FRACTION_H_
#define _FRACTION_H_

#include <iostream>

class Fraction
{
public:
    Fraction(int numerator = 0, int denominator = 1);
    Fraction(const Fraction &fraction);
    virtual ~Fraction(void);

    inline int numerator(void) const { return m_numerator; };
    inline int denominator(void) const { return m_denominator; };
    inline int sign(void) const { return ((m_numerator >= 0 && m_denominator >= 0) || (m_numerator <= 0 && m_denominator <= 0)) ? 1 : -1 ; };

    inline void setNumerator(int numerator) { m_numerator = numerator; };
    inline void setDenominator(int denominator) { m_denominator = denominator; };

    Fraction &simplify(void);
    Fraction &reciprocal(void);

    Fraction &operator=(const Fraction &rhs);
    Fraction &operator*=(const Fraction &rhs);
    Fraction operator*(const Fraction &rhs) const;
    Fraction &operator/=(const Fraction &rhs);
    Fraction operator/(const Fraction &rhs) const;
    Fraction &operator+=(const Fraction &rhs);
    Fraction operator+(const Fraction &rhs) const;
    Fraction &operator-=(const Fraction &rhs);
    Fraction operator-(const Fraction &rhs) const;

    Fraction &operator=(int rhs);
    Fraction &operator*=(int rhs);
    Fraction operator*(int rhs) const;
    Fraction &operator/=(int rhs);
    Fraction operator/(int rhs) const;
    Fraction &operator+=(int rhs);
    Fraction operator+(int rhs) const;
    Fraction &operator-=(int rhs);
    Fraction operator-(int rhs) const;

private:
    int calcGCD(int n1, int n2);

    int m_numerator;
    int m_denominator;
};

std::ostream &operator<<(std::ostream &out, const Fraction &fraction);

#endif // _FRACTION_H_
