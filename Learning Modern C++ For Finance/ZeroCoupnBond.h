#ifndef ZeroCoupnBond
#define ZeroCoupnBond
#include<iostream>
#include<cmath>
#include<iomanip>

struct ZeroCouponStruct
{
    double FaceValue;
    double InterestRate;
    double YearFraction;
    double Price;
    friend std::ostream& operator<<(std::ostream&out,const ZeroCouponStruct&);
    friend std::istream& operator>>(std::istream&in,ZeroCouponStruct&);
};
std::istream& operator>>(std::istream&in,ZeroCouponStruct&Zero)
{
    std::cout<<"Face Value : ";
    in>>Zero.FaceValue;
    std::cout<<"Interest Rate  :";
    in>>Zero.InterestRate;
    std::cout<<"Year Fraction :";
    in>>Zero.YearFraction;
    return in;
};
void Input(ZeroCouponStruct&Zero)
{
    std::cout<<Zero;
    std::cin>>Zero;
};
std::ostream& operator<<(std::ostream&out,const ZeroCouponStruct&Zero)
{
    out<<"Face Value : "<<Zero.FaceValue<<"\n";
    out<<"Interest Rate : "<<Zero.InterestRate<<"\n";
    out<<"Year Fraction : "<<Zero.YearFraction<<"\n";
    out<<"=============\nPrice : "<<Zero.Price<<"\n";
    return out;
};
void ZeroCouponBond(ZeroCouponStruct&Zero)
{

     Zero.Price=Zero.FaceValue*std::exp(-Zero.InterestRate*Zero.YearFraction);
};

#endif