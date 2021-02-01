#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the arrayManipulation function below.
long long arrayManipulation(long n, vector<vector<long>> queries) {
    long long array_number[n]={0},size_v;
    size_v=queries.size();
    for(long i=0;i<size_v;i++){
        for(long j=queries[i][0]-1;j<queries[i][1];j++){
            array_number[j]+=queries[i][2];
        }
    }
    sort(array_number, array_number+n);
    for(int i=0;i<n;i++){
        cout<<array_number[i]<<" ";
    }
    cout<<endl;
    return array_number[n-1];
}

int main()
{
    long n,q;
    cin>>n>>q;
    vector<vector<long>> queries(q);
    long long size_v;
    size_v=queries.size();
    for(long i=0;i<size_v;i++){
        queries[i].resize(3);
        for(long j=0;j<queries[i].size();j++){
            cin>>queries[i][j];
        }
    }
    cout<<arrayManipulation(n,queries);
}
