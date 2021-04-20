#include "NumberWithUnits.hpp"

using namespace std;
using namespace ariel;

NumberWithUnits::NumberWithUnits(double n, string u) : number(n), units(u)
{
    return;
}
void NumberWithUnits::read_units(ifstream& unit_file)
{
    return;
}
NumberWithUnits NumberWithUnits::operator+(const NumberWithUnits &n)
{    
    return NumberWithUnits(1, "m");
}
NumberWithUnits NumberWithUnits::operator+=(const NumberWithUnits &n)
{
    return NumberWithUnits(1, "m");
}
NumberWithUnits NumberWithUnits::operator+()
{
    return NumberWithUnits(1, "m");
}
NumberWithUnits NumberWithUnits::operator-(const NumberWithUnits &n)
{
    return NumberWithUnits(1, "m");
}
NumberWithUnits NumberWithUnits::operator-=(const NumberWithUnits &n)
{
    return NumberWithUnits(1, "m");
}
NumberWithUnits NumberWithUnits::operator-()
{
    return NumberWithUnits(1, "m");
}
bool NumberWithUnits::operator>(const NumberWithUnits &n) const
{
    return true;
}
bool NumberWithUnits::operator>=(const NumberWithUnits &n) const
{
    return true;
}
bool NumberWithUnits::operator<(const NumberWithUnits &n) const
{
    return true;
}
bool NumberWithUnits::operator<=(const NumberWithUnits &n) const
{
    return true;
}
bool NumberWithUnits::operator==(const NumberWithUnits &n) const
{
    return true;
}
bool NumberWithUnits::operator!=(const NumberWithUnits &n) const
{
    return true;
}
NumberWithUnits NumberWithUnits::operator++()
{
    return NumberWithUnits(1, "m");
}
NumberWithUnits NumberWithUnits::operator++(int)
{
    return NumberWithUnits(1, "m");
}
NumberWithUnits NumberWithUnits::operator--()
{
    return NumberWithUnits(1, "m");
}
NumberWithUnits NumberWithUnits::operator--(int)
{
    return NumberWithUnits(1, "m");
}

NumberWithUnits ariel::operator*(double d, const NumberWithUnits n)
{
    return NumberWithUnits(1, "m");
}
NumberWithUnits ariel::operator*(const NumberWithUnits n, double d)
{
    return (d * n);
}
ostream & ariel::operator<<(ostream &os, const NumberWithUnits n)
{
    os << n.number << "[" << n.units << "]";
    return os;
}
istream & ariel::operator>>(istream &is, NumberWithUnits n)
{
    is >> n.number;
    char tmp;
    while (is.peek() == ' ')
    {
        is >> tmp;
    }
    is >> n.units;
    while (is.peek() == ' ')
    {
        is >> tmp;
    }
    return is;
}