#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,m,o,p;
    cin>>n>>m;vector<char> s(10001);
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    vector<char> x,y;
    vector< vector<int> > f(n,vector<int>(n,1));
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n;j++){
            if(i+j==n-1){
                f[i][j]=1;
            }else if(i+j>n-1)
            {
                f[i][j]=0;
            }else{
                for(int k=i;k<i+j+1;k++){
                    x.push_back(s[k]);y.push_back(s[k+j+1]);
                }
                if(x==y)
                {
                    f[i][j]=f[i+j+1][j]+1;
                }
                x.clear();y.clear();
            }
        }
    }/*
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<f[i][j]<<" ";
        }
        cout<<endl;
    }*/
    for(int a=0;a<m;a++)
    {
        cin>>o>>p;
        o--;p--;
        cout<<f[o][p-o]<<endl;
    }
    return 0;
}
