#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,i,j,count_s=0;string s,x,y;
    cin>>n>>m>>s;
    for(int a=0;a<m;a++)
    {
        cin>>i>>j;
        i--;j--;
        x=s;x.erase(j+1,n-j-1);x.erase(0,i);int b=j;
        while(true)
        {
            if(s.compare(b+1,j-i+1,x)==0)
            {
                count_s++;b+=j-i+1;
            }else
            {
                break;
            }
        }
        cout<<count_s+1<<endl;count_s=0;
    }
    return 0;
}
