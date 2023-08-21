#include<iostream>
#include<math.h>




using namespace std;
int main(){
int N;
int M;
cin>>N;
cin>>M;
long long check[M];
string nama[N];
string nomor[N];

for(int i=0;i<N;i++)
{
    cin>>nama[i];
    cin>>nomor[i];
}
int cek[M]={0};
string cari[M];
for(int i=0;i<M;i++)
{
    cin>>cari[i];
}


int awal;
int akhir;
int indeks;

for(int i=0;i<M;i++)
{   awal=0;
    akhir=N-1; 
   
    while(akhir>=awal){
     indeks=(awal+akhir)/2;

     if(cari[i]==nama[indeks])
     {
       check[i]=indeks;
        break;
     }
     else if(cari[i]<nama[indeks])
     {
       akhir=indeks-1;
         
     }else if(cari[i]>nama[indeks])
     {
        awal=indeks+1;
        
     }
     
    
    

  }
  
  if(akhir<awal)
  {
    check[i]=-1;
   
  }
}  

for(int i=0;i<M;i++)
{
    if(check[i]>-1)
    {
       cout<<nomor[check[i]]<<endl;
    }
    else
    {
      cout<<"NIHIL"<<endl;
    }
    
}





return 0; 

}
