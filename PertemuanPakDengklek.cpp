#include <iostream>

using namespace std;





int main(){
int N;
cin>>N;
string nama[N];
for(int i=0;i<N;i++)
{
  cin>>nama[i];
}
string temp;
string max=nama[0];
int indeks=0;
for(int i=N-1;i>=0;i--)
{
   for(int j=i;j>=0;j--)
   {
      if(max.length()==nama[j].length())
      {
        if(max<nama[j])
        {
          max=nama[j]; 
          indeks=j; 
        }
      }else if(max.length()<nama[j].length())
      {
         max=nama[j];
         indeks=j;
      }
   }

temp=nama[i];
nama[i]=max;
nama[indeks]=temp;

max="a";
indeks=0;

}


for(int i=0;i<N;i++)
{
  cout<<nama[i]<<endl;
}


    return 0;
}
