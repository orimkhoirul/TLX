#include <bits/stdc++.h>

using namespace std;

bool cekKoor[30][30];

struct arr
{
    int arrK[30][30];
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

void flood(arr A, int x, int y, int angka, int M, int N)
{
    if (cekKoor[x][y] == false && A.arrK[x][y] == angka)
    {
        byk++;
        cekKoor[x][y] = true;

        if (x == 0)
        {
            if (y == 0)
            {
                flood(A, x + 1, y, angka, M, N);
                flood(A, x, y + 1, angka, M, N);
            }
            else if (y == N - 1)
            {
                flood(A, x + 1, y, angka, M, N);
                flood(A, x, y - 1, angka, M, N);
            }
            else
            {   
                flood(A, x + 1, y, angka, M, N);
                flood(A, x, y - 1, angka, M, N);
                flood(A, x, y + 1, angka, M, N);
                
            }
        }
        else if (x == N - 1)
        {
            if (y == 0)
            { 
                flood(A, x - 1, y, angka, M, N);
                flood(A, x , y+1, angka, M, N);
            }
            else if (y == N - 1)
            {
                flood(A, x - 1, y, angka, M, N);
                flood(A, x , y-1, angka, M, N);
            }
            else
            {
                flood(A, x - 1, y, angka, M, N);
                flood(A, x , y+1, angka, M, N);
                flood(A, x , y-1, angka, M, N);

            }
        }else{
             if (y == 0)
            { 
                flood(A, x - 1, y, angka, M, N);
                flood(A, x + 1, y, angka, M, N);
                flood(A, x , y+1, angka, M, N);
            }
            else if (y == N - 1)
            {
                flood(A, x - 1, y, angka, M, N);
                flood(A, x + 1, y, angka, M, N);
                flood(A, x , y-1, angka, M, N);
            }
            else
            {
                flood(A, x - 1, y, angka, M, N);
                flood(A, x , y+1, angka, M, N);
                flood(A, x , y-1, angka, M, N);
                flood(A, x +1, y, angka, M, N);

            } 
        }
       
    }

    
}

void cetakArray(arr A, int M, int N)
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cout << A.arrK[i][j] << " ";
        }
        cout << endl;
    }
}


void IsiSkor(arr A, int M, int N, int *max, int *xMax, int *yMax)
{

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            
            byk = 0;
            flood(A, i, j, A.arrK[i][j], M, N);
            
            if ((*max) < byk)
            {
                (*max) = byk;
                (*xMax) = i;
                (*yMax) = j;
            }
        }
    }
}

int main()
{
    arr A;
    int M, N;
    cin >> M >> N;

    int max, xMax, yMax;

    isiArray(&A, M, N);
    max = 0;
    xMax = 0;
    yMax = 0;
    IsiSkor(A, M, N, &max, &xMax, &yMax);

    cout << max*(max-1) ;

    return 0;
}
