#include<iostream>
#include<array>
int GetMax(int&a,int&b,int&c)
{
    int MAX{a};
    if(MAX<b)MAX=b;
    if(MAX<c)MAX=c;
    return MAX;
};

int main()
{
    std::array<int,3>Input{};
    std::cin>>Input.at(0)>>Input.at(1)>>Input.at(2);
    std::cout<<GetMax(Input.at(0),Input.at(1),Input.at(2))<<"\n";
    return 0;
};
