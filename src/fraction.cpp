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

#include "fraction.h"

Fraction::Fraction(int numerator, int denominator)
    : m_numerator(numerator),
      m_denominator(denominator)
{
}

Fraction::Fraction(const Fraction &fraction)
    : m_numerator(fraction.numerator()),
      m_denominator(fraction.denominator())
{
}

Fraction::~Fraction(void)
{
}

Fraction &Fraction::simplify(void)
{
    int gcd = calcGCD(m_numerator, m_denominator);

    m_numerator /= gcd;
    m_denominator /= gcd;

    return *this;
}

Fraction &Fraction::reciprocal(void)
{
    int tmp = m_numerator;
    m_numerator = m_denominator;
    m_denominator = tmp;

    return *this;
}

Fraction &Fraction::operator=(const Fraction &rhs)
{
    m_numerator = rhs.m_numerator;
    m_denominator = rhs.m_denominator;

    return *this;
}

Fraction &Fraction::operator*=(const Fraction& rhs)
{
    m_numerator *= rhs.m_numerator;
    m_denominator *= rhs.m_denominator;

    simplify();

    return *this;
}

Fraction Fraction::operator*(const Fraction& rhs) const
{
    Fraction result(*this);
    return result *= rhs;
}

Fraction &Fraction::operator/=(const Fraction& rhs)
{
    m_numerator *= rhs.m_denominator;
    m_denominator *= rhs.m_numerator;

    simplify();

    return *this;
}

Fraction Fraction::operator/(const Fraction& rhs) const
{
    Fraction result(*this);
    return result /= rhs;
}

Fraction &Fraction::operator+=(const Fraction& rhs)
{
    m_numerator = m_numerator * rhs.m_denominator + rhs.m_numerator * m_denominator;
    m_denominator = m_denominator * rhs.m_denominator;

    simplify();

    return *this;
}

Fraction Fraction::operator+(const Fraction& rhs) const
{
    Fraction result(*this);
    return result += rhs;
}

Fraction &Fraction::operator-=(const Fraction& rhs)
{
    m_numerator = m_numerator * rhs.m_denominator - rhs.m_numerator * m_denominator;
    m_denominator = m_denominator * rhs.m_denominator;

    simplify();

    return *this;
}

Fraction Fraction::operator-(const Fraction& rhs) const
{
    Fraction result(*this);
    return result -= rhs;
}

Fraction &Fraction::operator=(int rhs)
{
    Fraction fraction(rhs);
    return *this = fraction;
}

Fraction &Fraction::operator*=(int rhs)
{
    Fraction fraction(rhs);
    return *this *= fraction;
}

Fraction Fraction::operator*(int rhs) const
{
    Fraction fraction(rhs);
    return *this * fraction;
}

Fraction &Fraction::operator/=(int rhs)
{
    Fraction fraction(rhs);
    return *this /= fraction;
}

Fraction Fraction::operator/(int rhs) const
{
    Fraction fraction(rhs);
    return *this / fraction;
}

Fraction &Fraction::operator+=(int rhs)
{
    Fraction fraction(rhs);
    return *this += fraction;
}

Fraction Fraction::operator+(int rhs) const
{
    Fraction fraction(rhs);
    return *this + fraction;
}

Fraction &Fraction::operator-=(int rhs)
{
    Fraction fraction(rhs);
    return *this += fraction;
}

Fraction Fraction::operator-(int rhs) const
{
    Fraction fraction(rhs);
    return *this - fraction;
}

bool Fraction::operator==(const Fraction &rhs) const
{
    return compare(rhs) == 0;
}

bool Fraction::operator!=(const Fraction &rhs) const
{
    return !(*this == rhs);
}

bool Fraction::operator>(const Fraction &rhs) const
{
    return compare(rhs) > 0;
}

bool Fraction::operator<(const Fraction &rhs) const
{
    return compare(rhs) < 0;
}

bool Fraction::operator>=(const Fraction &rhs) const
{
    return !(*this < rhs);
}

bool Fraction::operator<=(const Fraction &rhs) const
{
    return !(*this > rhs);
}

bool Fraction::operator==(int rhs) const
{
    Fraction fraction(rhs);
    return *this == fraction;
}

bool Fraction::operator!=(int rhs) const
{
    Fraction fraction(rhs);
    return *this != fraction;
}

bool Fraction::operator>(int rhs) const
{
    Fraction fraction(rhs);
    return *this > fraction;
}
    
bool Fraction::operator<(int rhs) const
{
    Fraction fraction(rhs);
    return *this < fraction;
}
    
bool Fraction::operator>=(int rhs) const
{
    Fraction fraction(rhs);
    return *this >= fraction;
}
    
bool Fraction::operator<=(int rhs) const
{
    Fraction fraction(rhs);
    return *this <= fraction;
}

int Fraction::calcGCD(int n1, int n2) const
{
    while (n2 != 0)
    {
        int tmp1 = n1;
        int tmp2 = n2;

        n1 = tmp2;
        n2 = tmp1 % tmp2;
    }

    return n1;
}

int Fraction::compare(const Fraction &fraction) const
{
    int lhs = m_numerator * fraction.m_denominator;
    int rhs = fraction.m_numerator * m_denominator;

    return lhs - rhs;
}

std::ostream &operator<<(std::ostream &out, const Fraction &fraction)
{
    if (fraction.numerator() == 0)
    {
        out << "0";
    }
    else if (fraction.denominator() == 1)
    {
        out << fraction.numerator();
    }
    else
    {
        out << fraction.numerator() << "/" << fraction.denominator();
    }
    return out;
}
