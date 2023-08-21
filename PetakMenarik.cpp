#include<iostream>
using namespace std;



int main(){
int N;
cin>>N;
int M;
cin>>M;
int K;
cin>>K;
bool cek=false;
int petak[N+2][M+2];

for(int i=0;i<N+2;i++)
{
  for(int j=0;j<M+2;j++)
  {
    petak[i][j]=1;
  }
}

for(int i=1;i<=N;i++)
{
  for(int j=1;j<=M;j++)
  {
    cin>>petak[i][j];
  }
}


int hasil;
for(int i=1;i<=M;i++)
{
  for(int j=1;j<=N;j++)
  {
     hasil=petak[j+1][i]*petak[j-1][i]*petak[j][i+1]*petak[j][i-1];
     if(hasil==K)
     {
       cout<<j<<" "<<i;
       cek=true;
       break;
     }
  
  }
if(cek==true)
{
  break;
}
}
if(cek==false)
{
  cout<<"0 0";
}


return 0;
}
