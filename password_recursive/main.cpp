#include <bits/stdc++.h>

using namespace std;

void print(int& temp,int& n,string& s,string& p)
{
    for(int i=0; i<s.length(); i++)
    {
        p+=s[i];
        if(p.length()<temp)
        {
            print(temp, n, s,p);
        }
        if(p.length()==temp)
        {
            cout<<p<<endl;
        }
        p.erase(p.length()-1,1);
    }
    if(p.length()>0)
    {
        return;
    }
    temp++;
    if(temp<=n)
    {
        print(temp, n, s,p);
    }
}

int main()
{
    int n,temp=1;
    string s,p;
    cin>>n>>s;
    print(temp, n, s,p);
    return 0;
}

