#include"ZeroCoupnBond.h"
int main()
{
    ZeroCouponStruct Zero{};
    Input(Zero);
    ZeroCouponBond(Zero);
    std::cout<<std::setprecision(120)<<Zero;
    return 0;
};
/*
We want to price a zero coupon bond

Ae-rt

where

A = the face value of the bond,

r is the interest rate, and

t is the time to maturity as a year fraction.

*/



