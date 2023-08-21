#include <iostream>
#include <math.h>
#include <string>
using namespace std;

struct arr
{
    int arrM[75][75];
};

void isiMatriks(arr *t, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> t->arrM[i][j];
        }
    }
}

bool identik(arr t1, arr t2, int N)
{

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (t1.arrM[i][j] != t2.arrM[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

bool vertikal(arr t1, arr t2, int N)
{
    int k;
    k = N - 1;

    for (int i = 0; i < N; i++)
    {
        k = N - 1;
        for (int j = 0; j < N; j++)
        {
            if (t1.arrM[i][j] != t2.arrM[i][k])
            {
                return false;
            }
            k--;
        }
    }
    return true;
}

bool horizontal(arr t1, arr t2, int N)
{
    int k;
    k = N - 1;

    for (int i = 0; i < N; i++)
    {
        k = N - 1;
        for (int j = 0; j < N; j++)
        {
            if (t1.arrM[j][i] != t2.arrM[k][i])
            {
                return false;
            }
            k--;
        }
    }
    return true;
}

bool diagonalkiri(arr t1, arr t2, int N)
{
    int k=N-1;
    int l=N-1;
    for (int i = 0; i < N; i++)
    {   l=N-1;
        for (int j = 0; j < N; j++)
        {
            if (t1.arrM[i][j] != t2.arrM[l][k])
            {
                return false;
            }
            l--;
        }
        k--;
    }
    return true;
}

bool diagonalkanan(arr t1, arr t2, int N)
{
    int k=0;
    int l=0;
    for (int i = 0; i < N; i++)
    {   l=0;
        for (int j = 0; j < N; j++)
        {
            if (t1.arrM[i][j] != t2.arrM[l][k])
            {
                return false;
            }
            l++;
        }
        k++;
    }
    return true;
}

int main()
{
    int N;
    cin >> N>>N;
    arr t1, t2;
    isiMatriks(&t1, N);
     cin >> N>>N;
    isiMatriks(&t2, N);
   
   if(identik(t1,t2,N)==true){
     cout<<"identik";
   }else if(vertikal(t1,t2,N)==true){
     cout<<"vertikal";
   }else if(horizontal(t1,t2,N)==true){
      cout<<"horisontal";
   }else if(diagonalkanan(t1,t2,N)==true){
      cout<<"diagonal kanan bawah";
   }else if(diagonalkiri(t1,t2,N)==true){
      cout<<"diagonal kiri bawah";
   }else{
      cout<<"tidak identik";
   }

    return 0;
}
