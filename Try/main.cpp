#include<bits/stdc++.h>
using namespace std;
void tim_vi_tri(string* a,int n,string s,int& x,int& y){
    string string_tam="ads";int b;
    for(int i=0;i<n;i++){
        b=1;string_tam.erase(0,string_tam.length());
        do{
        string_tam+=a[i][b];b++;

        }while(a[i][b]!='>'&&a[i][b]!=' ');

        if(s==string_tam){
            x=i;
        }
        s='/'+s;
        if(s==string_tam){
            y=i;
        }
        s.erase(0,1);
    }
}
int main() {
    int n,q,k=0,m,a_x,a_y,b_x,b_y;bool check;
    cin>>n>>q;
    bool check1[q];
    string a[n],b[q],value[q],string_tam,string_tam_2,rac,so[q];
    getline(cin,rac);
    for(int i=0;i<n;i++){
        getline(cin,a[i]);
    }
    for(int i=0;i<q;i++){
        getline(cin,b[i]);
    }
    //lay du lieu truy van
    for(int i=0;i<q;i++){
        for(int j=0;j<b[i].length();j++){
            if(b[i][j+1]=='~'){
                m=j;
                do{
                    string_tam_2=b[i][m]+string_tam_2;m--;
                }while(b[i][m]!='.'||m==-1);
                tim_vi_tri(a,n,string_tam_2,a_x,a_y);
                so[k]=string_tam_2;string_tam_2.erase(0,string_tam_2.length());
                check1[i]=1;
                while(m!=-1){
                    m--;
                    do{
                        string_tam_2=b[i][m]+string_tam_2;m--;
                    }while(b[i][m]!='.'||m==-1);
                    tim_vi_tri(a,n,string_tam_2,b_x,b_y);
                    if(!(a_x<b_x&&a_y>b_y)){
                        check1[i]=0;

                    }
                }
                for(int l=j+2;l<b[i].length();l++){
                    string_tam+=b[i][l];
                }

                value[k]=string_tam;
                //cout<<value[k]<<endl;
                string_tam.erase(0,string_tam.length());k++;
            }
        }
    }
    // ket thuc lay du lieu truy van
    k=0;

    for(int i=0;i<q;i++){
        if(!check1[i]){cout<<"Not Found!";continue;}
        check=0;
        tim_vi_tri(a,n,string_tam_2,a_x,a_y);
        for(int j=0;j<a[a_x].length();j++){
            if(a[a_x][j]=='='){
                k=j-2;
                do{
                    string_tam=a[a_x][k]+string_tam;k--;
                }while(a[a_x][k]!=' ');
                //cout<<string_tam<<endl;
                //cout<<value[i]<<endl;
                if(string_tam==value[i]){check=1;
                    k=j+3;
                    do{
                        cout<<a[a_x][k];k++;
                    }while(a[a_x][k]!='"');
                }
            }
        }
        if(!check){cout<<"Not Found!";}
        cout<<endl;
        string_tam.erase(0,string_tam.length());
    }
    return 0;

}
/*
1 1
<tag1 value = "HelloWorld">
tag1~value
*/
