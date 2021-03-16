#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a;
   char *x;
   x = (char *) &a;
   //a = 512;
   x[0] = 1;
   x[1] = 2;
   cout<<a;
    return 0;
}
