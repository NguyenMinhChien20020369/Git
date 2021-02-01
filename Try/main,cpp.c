#include <bits/stdc++.h>

using namespace std;
int main()
{

    string s;
    getline(cin, s);
    string a;vector<string>b;int c,d;bool check;
    c=s.length();
    for(int i=0;i<c-1;i++){
        for(int j=i+1;j<c;j++){

            a=s;
            a.erase(i,1);cout<<a<<" ";a.erase(j,1);cout<<a<<endl;
            d=b.size();check=true;
            for(int k=0;k<d;k++){
                if(b[k]==a){check=false;}
            }
            if(check){
            b.push_back(a);
            }
        }
    }


}
