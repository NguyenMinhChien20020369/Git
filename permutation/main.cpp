#include <iostream>

using namespace std;

void permutation(string s,int n,int Bool[],char arr[],int k)
{
    for(int i=0;i<n;i++)
    {
        if(!Bool[i]){
            arr[k]=s[i];
            Bool[i]=1;
            if(k==n-1){cout<<arr<<endl;}else
                {
                    permutation(s,n,Bool,arr,k+1);
                }
            Bool[i]=0;
        }
    }
}

int main()
{
    string s;
    cin>>s;
    int Bool[s.length()]={0};char arr[s.length()];
    permutation(s,s.length(),Bool,arr,0);
    return 0;
}
