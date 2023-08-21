#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool cekKoor[26][26];

struct arr
{
    int arrK[26][26];
};

void isiArray(arr *A, int M, int N)
{

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> A->arrK[i][j];
        }
    }
}
int byk = 0;

void flood(arr *A, int x, int y, int angka)
{

    if (A->arrK[x][y] == angka && cekKoor[x][y] == false)
    {
        byk++;
        cekKoor[x][y] = true;
        flood(A, x + 1, y, angka);
        flood(A, x, y + 1, angka);
        flood(A, x - 1, y, angka);
        flood(A, x, y - 1, angka);
    }
}

int main()
{
    arr A;
    int M, N;
    cin >> M >> N;

    isiArray(&A, M, N);

   cin>>M>>N; 

   flood(&A,M,N,A.arrK[M][N]); 

   cout<<byk*(byk-1); 

    return 0;
}
