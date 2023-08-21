#include <iostream>
#include <math.h>

using namespace std;

char result[3] = {'M', 'K', 'S'};

struct Arr
{
    char isi;
    char tim[2];
};

struct Data
{
    Arr arrD[100];
};

struct tim
{
    char nama[2];
};

struct dataTim
{
    tim arrT[100];
};

struct tempData
{
    char name[100];
};

struct dataSkor
{
    int skor[5];
};

struct hasil
{
    int arrH[5];
};

int jml = 0;
int indeks = 0;
void IsiTemp(tempData *t, int N, int dalam, dataTim *A)
{
    if (dalam == 2)
    {
        for (int i = 0; i < 2; i++)
        {

            A->arrT[indeks].nama[i] = t->name[i];
        }
        indeks++;
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            t->name[dalam] = i + 97;
            if ((dalam == 1 && t->name[0] < t->name[1]) || dalam == 0)
            {
                IsiTemp(t, N, dalam + 1, A);
            }
        }
    }
}

int cariIndeks(char tim, dataSkor t)
{
    if (tim == 'a')
    {
        return 0;
    }
    else if (tim == 'b')
    {
        return 1;
    }
    else if (tim == 'c')
    {
        return 2;
    }
    else if (tim == 'd')
    {
        return 3;
    }
    else
    {
        return 4;
    }
}

void isiSkor(char tim1, char tim2, char status, dataSkor *t, int N)
{
    if (status == 'M')
    {
        t->skor[cariIndeks(tim1, *t)] = t->skor[cariIndeks(tim1, *t)] + 3;
    }
    else if (status == 'S')
    {
        t->skor[cariIndeks(tim1, *t)] = t->skor[cariIndeks(tim1, *t)] + 1;
        t->skor[cariIndeks(tim2, *t)] = t->skor[cariIndeks(tim2, *t)] + 1;
    }
    else
    {
        t->skor[cariIndeks(tim2, *t)] = t->skor[cariIndeks(tim2, *t)] + 3;
    }
}
int cek = 0;
void permutasi(int dalam, int N, Data *t, dataTim A, dataSkor *s, int jmlTim, hasil h)
{

    if (dalam == N)
    {
        
        for (int i = 0; i < N; i++)
        {   
            //cout<<t->arrD[i].isi;
            if (t->arrD[i].isi == 'M')
            {
                isiSkor(A.arrT[i].nama[0], A.arrT[i].nama[1], 'M', s, N);
            }
            else if (t->arrD[i].isi == 'S')
            {

                isiSkor(A.arrT[i].nama[0], A.arrT[i].nama[1], 'S', s, N);
            }
            else
            {
                isiSkor(A.arrT[i].nama[0], A.arrT[i].nama[1], 'K', s, N);
            }
        }
       // cout<<" ";
        for (int i = 0; i < jmlTim; i++)
        {
           if (s->skor[i] == h.arrH[i])
            {
                cek++;
            }
           // cout<<s->skor[i]<<" ";
            s->skor[i] = 0;
        }
       // cout<<endl;
        if (cek == jmlTim)
        {
           
            jml = -1;
           
        }
        cek=0;
        jml++;
    }
    else
    {
        for (int i = 1; i <= 3; i++)
        {
            t->arrD[dalam].isi = result[(i - 1) % 3];

            permutasi(dalam + 1, N, t, A, s, jmlTim, h);
        }
    }
}

int main()
{
    int N, T;
    cin >> T;
    hasil h;

    int dalam = 0;

    Data t;
    tempData p;
    dataTim A;
    dataSkor s;

    for (int i = 0; i < 5; i++)
    {
        s.skor[i] = 0;
    }
   
    dalam = 0;
     for (int i = 0; i < T; i++)
    {
        cin >> N;
        for (int j = 0; j < N; j++)
        {
            cin >> h.arrH[j];
        }
         IsiTemp(&p, N, dalam, &A);
        permutasi(dalam, (N * (N - 1)) / 2, &t, A, &s, N, h);
       
        dalam = 0;
      
        if (jml == (pow(3, (N * (N - 1)) / 2)))
        {
            cout << "NO" << endl;
        }else{
            cout<<"YES"<<endl;
             cek=0;
        }
        jml = 0;
    }
    
   
    

    return 0;
}
