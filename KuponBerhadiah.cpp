#include<iostream>
#include<math.h>
using namespace std;




int main(){
int N;
cin>>N;
int X;
cin>>X;
int arr[N];
for(int i=0;i<N;i++)
{
   cin>>arr[i];
}
int min=abs(X-arr[0]);
int hasil[N]={0};
hasil[0]=1000000;
for(int i=1;i<N;i++)
{   hasil[i]=1000000;
   if(min>abs(X-arr[i]))
   {
      min=abs(X-arr[i]);
     
   }

}
for(int i=0;i<N;i++)
{
   if(abs(X-arr[i])==min){
      hasil[i]=arr[i];
   }
}

min=hasil[0];
for(int i=0;i<N;i++)
{
   if(min>hasil[i]){
      min=hasil[i];
   }
}

cout<<min;


   return 0;
}
