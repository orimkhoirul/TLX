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

void flood(arr *A, int x, int y, int angka, int M, int N)
{
    if (cekKoor[x][y] == false && A->arrK[x][y] == angka && A->arrK[x][y]!=8)
    {
        byk++;
        cekKoor[x][y] = true;
        A->arrK[x][y]=8;

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

void FalseKoor()
{
    for (int i = 0; i <= 26; i++)
    {
        for (int j = 0; j <= 26; j++)
        {
            cekKoor[i][j] = false;
        }
    }
}

void CariMax(arr A, int M, int N, int *max, int *xMax, int *yMax)
{

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // FalseKoor();
            byk = 0;
            flood(&A, i, j, A.arrK[i][j], M, N);
            // cout << byk * (byk - 1) << endl;
            
            // cout<<endl;
            if ((*max) < byk)
            {
                (*max) = byk;
                (*xMax) = i;
                (*yMax) = j;
            }
        }
    }
}
void CetakRuntuhan(arr A, int M, int N);



bool cekJatuh(arr A, int M, int N, int i)
{

    for (int j = 0; j < M; j++)
    {
        if (A.arrK[j + 1][i] == 8 && A.arrK[j][i] != 8)
        {
            return false;
        }
    }

    return true;
}

void Runtuhkan(arr *A, int M, int N)
{
    int temp;
    int j = 0;

    for (int i = 0; i < N; i++)
    {
        j = 0;
        while (cekJatuh(*A, M, N, i) == false)
        {

            if (A->arrK[j + 1][i] == 8 && A->arrK[j][i] != 8)
            {
                temp = A->arrK[j + 1][i];
                A->arrK[j + 1][i] = A->arrK[j][i];
                A->arrK[j][i] = temp;
            }
            j++;
            if (j == M)
            {
                j = 0;
            }
        }
    }
}


void CetakRuntuhan(arr A, int M, int N)
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (A.arrK[i][j] == 8)
            {
                cout << ". ";
            }
            else
            {
                cout << A.arrK[i][j] << " ";
            }
        }
        cout << endl;
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
    
    CariMax(A,M,N,&max,&xMax,&yMax); 
    FalseKoor();
    flood(&A,xMax,yMax,A.arrK[xMax][yMax],M,N);
     
   
    Runtuhkan(&A,M,N);
    
    CetakRuntuhan(A,M,N);

    

    return 0;
}
