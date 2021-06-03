//
// Created by tomek on 01.06.2021.
//

#include "Rational.h"

Rational::Rational(int numerator, int denominator)
{
    initialize(numerator,denominator);
}

Rational::Rational(const  Rational & copy):numer(copy.numer), denom(copy.denom), gcdND(copy.gcdND)
{
    this->gcdND = copy.gcdND;
}

Rational& Rational::operator=(const Rational& other)
{
    this->denom = other.denom;
    this->numer = other.numer;
    this->gcdND = other.gcdND;
    return *this;
}

Rational& Rational::operator=(int i) {
    this->numer = i;
    this->denom = 1;
    this->gcdND = 1;
    return *this;
}

void Rational::initialize(int numerator, int denominator)
{
    this->numer = numerator;
    this->denom = denominator;
    this->gcdND = gcd(numerator,denominator);
    denominator_check(this->denom);
}

Rational Rational::operator*(const Rational &other) const
{
    Rational r(this->numer*other.numer,this->denom*other.denom);
    return r;
}

Rational Rational::operator/(const Rational &other) const
{
    Rational r(this->numer*other.denom, this->denom*other.numer);
    return r;
}

Rational Rational::operator+(const Rational &other) const
{

    if(this->denom != other.denom)
    {
        int x1, x2;
        int y;
        x1 = this->numer * other.denom;
        y = this->denom * other.denom;
        x2 = other.numer*this->denom;
        Rational r(x1+x2,y);
        return r;
    } else{

        Rational r(this->numer+other.numer,this->denom);
        return r;
    }

}

Rational Rational::operator-(const Rational &other) const
{
    if(this->denom != other.denom)
    {
        int x1, x2;
        int y;
        x1 = this->numer * other.denom;
        y = this->denom * other.denom;
        x2 = other.numer*this->denom;
        Rational r(x1-x2,y);
        return r;
    } else{

        Rational r(this->numer-other.numer,this->denom);
        return r;
    }

}

bool Rational::operator==(const Rational &other) const
{
    Rational r1 = normalize(*this);
    Rational r2 = normalize(other);

    return r1.numer == r2.numer && r1.denom == r2.denom;
}

bool Rational::operator>(const Rational &other) const
{

    int x1 = this->numer * other.denom;
    int x2 = other.numer * this->denom;

    return x1 > x2;
}

bool Rational::operator<(const Rational &other) const
{

    int x1 = this->numer * other.denom;
    int x2 = other.numer * this->denom;

    return x1 < x2;
}

bool Rational::operator>=(const Rational &other) const
{

    int x1 = this->numer * other.denom;
    int x2 = other.numer * this->denom;

    return x1 >= x2;
}

bool Rational::operator<=(const Rational &other) const
{
    int x1 = this->numer * other.denom;
    int x2 = other.numer * this->denom;


    return x1 <= x2;
}

std::ostream &operator<<(std::ostream & s, const Rational& r)
{
    s<<r.numer<<"/"<<r.denom;
    return s;
}

std::istream &operator>>(std::istream & s, Rational& r)
{
    int x, y;
    s >> x>> y;
    r.initialize(x,y);
    return s;
}

Rational operator+(const Rational &r, int i)
{
    Rational rr(i);
    return rr+r;
}

Rational operator+(int i, const Rational &r)
{
Rational rr(i);
return rr+r;
}

Rational operator-(const Rational &r, int i)
{
    Rational rr(i);
    return r-rr;
}

Rational operator-(int i, const Rational &r)
{
Rational rr(i);
return rr-r;
}

Rational operator*(int i, const Rational &r)
{
Rational rr(i);
return rr*r;
}

Rational operator*(const Rational &r, int i)
{
Rational rr(i);
return rr*r;
}

Rational operator/(const Rational &r, int i)
{
Rational rr(i);
return r/rr;
}

Rational operator/(int i, const Rational &r)
{
Rational rr(i);
return rr*r;
}