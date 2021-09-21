#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int i,n,a[100],kt,j,t;
    scanf ("%d",&n);
    for (i=0; i<n; i++)
    {
        scanf("%d",&a[i]);
    }
    for (i=0; i<n-1; i++)
    {
        for (j=i+1; j<n; j++)
            if(a[i]>a[j])
            {
                t=a[i];
                a[i]=a[j];
                a[j]=t;
            }
    }
    for (i=0; i<n; i++)
    {
        printf("%d ",a[i]);
    }
    for (i=0; i<n-2; i++)
    {
        kt=0;
        if(a[i]-a[i+1]!=a[i+1]-a[i+2])
        {
            kt=1;
            break;
        }
    }
    if (kt==0)
    {
        printf ("%d",a[1]-a[0]);
    }
    else
    {
        printf("\n%d",a[n-1]);
    }
    return 0;
}
