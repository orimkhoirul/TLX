#include<iostream> 
#include<cmath>
using namespace std;

struct arr
{
  int Arr[100];
};

bool CekSama(arr A,int N){
  bool cek=true;
  for(int i=0;i<=N;i++){

    for(int j=i+1;j<=N;j++){
      if(A.Arr[i]==A.Arr[j] &&i!=j){
        cek=false;
      }
    }
  }
 return cek;
}

bool CekNaik(arr A,int N){
  bool cek=true;
  for(int i=0;i<=N;i++){

    for(int j=i+1;j<=N;j++){
      if(A.Arr[i]>A.Arr[j] &&i!=j){
        cek=false;
      }
    }
  }
 return cek;
}

void permutasi(int batas,int N,arr *A,int M){
  if(batas==M){
     for(int i=0;i<batas;i++){
       cout<<A->Arr[i]<<" ";
     }
     cout<<endl;
  }else{
    bool cek1,cek2;
    for(int i=1;i<=N;i++){
      A->Arr[batas]=i;
      cek1=CekSama(*A,batas);
      cek2=CekNaik(*A,batas);
      if(cek1==true && cek2==true){
        permutasi(batas+1,N,A,M);
      }
       
    }
  }
}

int main(){
int N,M;
cin>>N>>M;
arr A;
permutasi(0,N,&A,M);





  



}
