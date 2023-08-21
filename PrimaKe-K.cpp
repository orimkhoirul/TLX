#include<iostream>
#include<math.h>
#include<string>
using namespace std;


bool arrP[1000000];
int arrF[1000000];

bool cekPrima(int N){
int faktor=0;    
   for(int i=1;i<sqrt(N);i++){
      if(N%i==0 && (N/i)!=i){
         faktor=faktor+2;
      }else if(N/i==0 && (N/i)==i){
        faktor++;
      }
   }

   if(faktor==2){
      return true;
   }else{
      return false;
   } 
}

int main(){
int T,K;
cin>>T;
int bil[T];

for(int i=0;i<T;i++){
    cin>>bil[i];
}
arrP[0]=true;
arrP[1]=true;
for(int i=2;i<=2000;i++){
     if(cekPrima(i)==true){
        for(int j=2;j<=(1000000/i);j++){
             arrP[i*j]=true;
        }
     }
}
int indeks=0;
for(int i=0;i<=1000000;i++){
   if(arrP[i]==false){
     arrF[indeks]=i;
     indeks++;
   } 
}

for(int i=0;i<T;i++){
    cout<<arrF[bil[i]-1]<<endl;
}



return 0;
}
