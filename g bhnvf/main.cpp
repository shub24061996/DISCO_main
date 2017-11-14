#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
int main()
{
    int a,b,c,i,j,n;
    cin>>a;
    cin>>b;
    vector <int> v1,v2;


    for(i=0;i<a;i++)
    {
        cin>>c;
  v1.push_back(c);
    }
    for(i=0;i<b;i++)
    {
        cin>>c;
        v2.push_back(c);
    }
    sort(v1.begin(),v1.end());
  // vector<int> ::iterator it ;
/*vector<pair <int,int> > v3;
for(i=0;i<a;i++)
{
    v3.push_back(make_pair(v1[i],i));
}*/
//cout<<"!"<<endl;
/*int low,high,mid;
for(i=0;i<b;i++)
 {
     //cout<<"12"<<endl;
     //cout<<v2[i]<<endl;
     int p=v2[i];
     low=0;
    high=a;
    mid=(low+high)/2;
    while(low<high)
    {mid=(low+high)/2;
        if(v1[mid]>p)
        {
         high=mid;
        }
        else
        {
            low=mid+1;
        }

    }
    cout<<low<<" ";
}

}
*/
int main()
{
   long long int a,b,c,i,j,n;
    cin>>a>>b>>c;
    vector<long long int>v;
    int g= 0;
    int  p;
    if(c==1)
    {
        cout<<"1";
        return 0;
    }
    if(c==a*b)
    {
        cout<<c;
        return 0;
    }
    for(i=1;i<=a;i++)
    {
        for(j=1;j<=b;j++)
        {
           p=i*j;
           v.push_back(p);


        }
    }
    sort(v.begin(),v.end());
    cout<<v[c-1];

}
