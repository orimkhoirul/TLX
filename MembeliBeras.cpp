#include<iostream>
using namespace std;
int main()
{
int N,X;
cin>>N;
cin>>X;
double berat[N];
double harga[N];
double kilo[N];
for(int i=0;i<N;i++)
{
  cin>>berat[i];
}
for(int i=0;i<N;i++)
{
  cin>>harga[i];
  kilo[i]=harga[i]/berat[i];
}

double max=kilo[0];
int indeks=0;
double temp;
for(int i=N-1;i>=0;i--)
{
  for(int j=i;j>=0;j--)
  {
    if(max<kilo[j])
    {
      max=kilo[j];
      indeks=j;
    }

  }
temp=kilo[i];
kilo[i]=max;
kilo[indeks]=temp;

temp=berat[i];
berat[i]=berat[indeks];
berat[indeks]=temp;

max=kilo[0];
indeks=0;

}

double hasil=0;
for(int i=N-1;i>=0;i--)
{
  if(berat[i]<=X){
    hasil=hasil+kilo[i]*berat[i];
    X=X-berat[i];
  }else
  {
    hasil=hasil+kilo[i]*X;
    break;
  }
  
  
}
printf("%.5f",hasil);
 
    return 0;
}
