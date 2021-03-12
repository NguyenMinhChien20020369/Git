#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a=10,b=20,c=30,sum=0;
    int *pA=&a, *pB=&b,*pInt;
    int **ppInt=&pInt;
    (*ppInt)=pA;
    sum+=(**ppInt);
    (*ppInt)=pB;
    sum+=(*pInt);
    *ppInt=&c;
    sum+=(**ppInt);
    //cout<<&a<<" "<<&b<<" "<<&c<<" "<<&sum<<" "<<&pA<<" "<<&pB<<" "<<&pInt<<" "<<&ppInt;
    cout<<pA;
    return 0;
}
