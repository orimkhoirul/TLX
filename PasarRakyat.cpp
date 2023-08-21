#include<iostream>
using namespace std;
int main(){
int kpk=0,N;
scanf("%d",&N);
int a[N];
for(int i=0;i<N;i++)
{
    cin>>a[i];
}

int hasil=1;
for(int i=0;i<N;i++)
{
    hasil=hasil*a[i];
}


   if(kpk==0)
   {
     for(int j=2;j<100000;j++)
     {
       
       
           if((j%a[0]==0)&&((j%a[1]==0)))
           {
            kpk=j;
            break;
           }
       
     }
   }
   if(kpk!=0)
   {
     for(int i=1;i<N-1;i++)
     {
         for(int k=kpk;k<100000;k++)
         {
            if((k%kpk==0)&&(k%a[i+1]==0))
            {
                kpk=k;
                break;
            }
         }
         
     }
    


   }
  

cout<<kpk;





    return 0;
}
