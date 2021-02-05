#include<bits/stdc++.h>
using namespace std;
int main()
{
    ifstream input("input_large.txt");
    double n,q,total=0,head,last_index,value;
    input>>n>>q;
    vector<double> a(n);
    for(int i=0;i<q;i++)
    {
        input>>head>>last_index>>value;
        for(int j=head;j<=last_index;j++)
        {
            a[j]+=value;
        }
    }
    sort(a.begin(),a.end());
    cout<<a[n-1];
}
