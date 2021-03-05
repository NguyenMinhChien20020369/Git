#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;

const unsigned long long MAGIC= 11259375;
const long long MAGIC2 = 97;
const long long MOD = 1000000007;

char s[MAXN + 1];
unsigned long long h[MAXN + 1], pw[MAXN + 1];
long long h2[MAXN + 1], pw2[MAXN + 1];

pair<unsigned long long, long long> getHash(int i, int j)
{
    return make_pair(h[j + 1] - h[i] * pw[j - i + 1], (h2[j + 1] - h2[i] * pw2[j - i + 1] % MOD + MOD) % MOD);
}

int main()
{
    int n, m;
    assert(scanf("%d%d", &n, &m) == 2);
    assert(1 <= n && n <= MAXN);
    assert(1 <= m && m <= MAXN);
    assert(scanf("%s", s) == 1);
    cout<<strlen(s)<< " "<<n;
    assert(strlen(s) == n);
    int o,p;
    //vector<char> s(10001);
    /*for(int i=0;i<n;i++){
        cin>>s[i];
    }*/
    vector<char> x,y;
    vector< vector<int> > arr(n,vector<int>(n,1));
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<n;j++){
            if(i+j==n-1){
                arr[i][j]=1;
            }else if(i+j>n-1)
            {
                arr[i][j]=0;
            }else{
                for(int k=i;k<i+j+1;k++){
                    x.push_back(s[k]);y.push_back(s[k+j+1]);
                }
                if(x==y)
                {
                    arr[i][j]=arr[i+j+1][j]+1;
                }
                x.clear();y.clear();
            }
        }
    }/*
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }*/
    for(int a=0;a<m;a++)
    {
        cin>>o>>p;
        o--;p--;
        cout<<arr[o][p-o]<<endl;
    }
    return 0;
}
