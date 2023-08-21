#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>

using namespace std;

string gunung(int N)
{
 string hasil;
 string s; 
if(N==1)   
{
   hasil= "*";
}  

else
{ int a=0;
   while(a<N)
   {
     s.insert(a,"*");
   a++;
   }
  hasil=gunung(N-1)+" "+s+" "+gunung(N-1);
}   
 return hasil;
  
}  







int main()
{
int N;
cin>>N;
string g=gunung(N);
for(int i=0;i<999999;i++)
{
  if(g[i]==' ')
  { 
    cout<<endl;
  }
   
   else if(g[i]!=42)
   {
     break;
   }
   else
   {
     cout<<g[i];
   }
}
    return 0;
}   


