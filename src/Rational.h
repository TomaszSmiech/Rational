//
// by Roman Dębski
//

#ifndef RATIONAL_RATIONAL_H
#define RATIONAL_RATIONAL_H
#include <iostream>
#include <cmath>

class Rational {

public:
    Rational(int numerator, int denominator =1);
    ~Rational(){}
    Rational(const  Rational & copy);


    Rational& operator=(const Rational& other);
    Rational& operator=(int i);

    int numerator () const {return numer;}
    int denominator () const {return denom;}

    static Rational normalize(const Rational& other)
    {

        int x = other.numer;
        int y = other.denom;
        int g = gcd(other.numer,other.denom);

        if(other.denom<0)
        {
            y = -other.denom;
            x = -other.numer;
        }

        if(g>1){y/=g; x/=g; }

        Rational r(x,y);
        return r;
    } //
    static Rational normalizd(int numerator, int denominator)
    {
        int x = numerator,y = denominator;
        int g = gcd(x,y);
        if(y<0)
        {
            y = -y;
            x = -x;
        }

        if(g>1){y/=g; x/=g; }

        Rational r(x,y);
        return r;
    } //

    Rational operator+(const Rational &other) const;
    Rational operator-(const Rational &other) const;
    Rational operator*(const Rational &other) const;
    Rational operator/(const Rational& other) const;

    Rational operator+() const;
    Rational operator-() const;
    bool operator==(const Rational& other) const;
    bool operator>=(const Rational& other) const;
    bool operator<=(const Rational& other) const;
    bool operator>(const Rational & other) const;
    bool operator<(const Rational & other) const;

private:
    int numer;
    int denom;
    int gcdND;

    void initialize(int numerator, int denominator);
    friend std::ostream &operator<<(std::ostream &, const Rational&);
    friend std::istream &operator>>(std::istream &, Rational &);

    static int gcd(int x, int y)
    {
        x = abs(x);
        y = abs(y);

        while (y)
        {
            int t = y;
            y = x%y;
            x=t;
        }

        return x;
    }
    static bool denominator_check(int &d) {
        if (d == 0) {
            std::cout << "Deonominaotr cannot be equal to 0! It's set to 1 now";
            d=1;
        }
    }
};

Rational operator+(const Rational &r, int i);
Rational operator+(int i, const Rational &r);

Rational operator-(const Rational &r, int i);
Rational operator-(int i, const Rational &r);

Rational operator*(const Rational &r, int i);
Rational operator*(int i, const Rational &r);

Rational operator/(const Rational &r, int i);
Rational operator/(int i, const Rational &r);

#endif //RATIONAL_RATIONAL_H
