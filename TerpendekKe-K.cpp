#include <iostream>

using namespace std;

int main(){
int N,K;
cin>>N>>K;
int tinggi[N];
for(int i=0;i<N;i++)
{
  cin>>tinggi[i];
}
int max=tinggi[0];
int temp;
int indeks=0;

for(int i=N-1;i>=0;i--){
  for(int j=i;j>=0;j--){
    if(max<tinggi[j])
    {
      max=tinggi[j];
      indeks=j;
    }
  }

  temp=tinggi[i];
  tinggi[i]=max;
  tinggi[indeks]=temp;
  max=tinggi[0];
  indeks=0;
}



cout<<tinggi[K-1];
    return 0;
}
