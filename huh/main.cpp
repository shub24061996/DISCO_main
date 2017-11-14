#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a,b,c,i,j,n,h;
    cin>>a;
    vector<pair <int,int > >v;
    for(i=0;i<a;i++)
    {
        cin>>b>>c;
     v.push_back(make_pair(c,b));
    }
    sort(v.begin(),v.end());
    int count =0;
    int x=v.size();
    vector <int > ::iterator it;
    for(i=0;i<x;i++)
    {
        if(v[i].first!=0)
        {
            break;
        }

    }
 j =i;

 int o ,temp;;
 for(x=0; x<j; x++)
    {

        for(o=x+1; o<j; o++)
        {

            if(v[x].second > v[o].second)
            {
                temp     = v[x].second;
                v[x].second = v[o].second;
                v[o].second = temp;
            }
        }
    }
     x =v.size();
   // cout<<v[x-1].second;
   int cou=0 ,maxsum=0;
    cou=v[x-1].first;
   int flag=0;
   if(cou==0)
   {
       cout<<v[x-1].second;
       return 0;
   }
   for(i=x-1;i>=0;i--)
   {
       if(cou==0||cou<0||flag>a)
       {
           break;
       }
       else
       {
           maxsum=maxsum+v[i].second;
           flag++;
           if(v[i].first!=0&&i!=x-1)
           {
               cou=cou+v[i].first-1;
           }
           else
               {if(i!=x-1)cou--;}
       }
   }
   cout<<maxsum;
   return 0;

}
