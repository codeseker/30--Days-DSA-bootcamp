#include <iostream>
#include <vector>
using namespace std;

int main()
{
   
   int n,m;
   cin>>n>>m;

   int a[n][m];

   for(int i=0; i<n; i++)
   {
       for(int j=0; j<m; j++)
       {
           cin>>a[i][j];
       }
   }

   for(int i=0; i<n; i++)
   {
       if(i%2 != 0)
       {
           int s = 0;
           int e = m-1;

           while(s <= e)
           {
               swap(a[i][s], a[i][e]);
               s++;
               e--;
           }
       }
   }

   vector<int> res;
   for(int i=0; i<n; i++)
   {
       for(int j=0; j<m; j++)
       {
           res.push_back(a[i][j]);
       }
   }

   for(auto i:res)
   {
       cout<<i<<" ";
   }
   cout<<endl;

  
  return 0;
}
