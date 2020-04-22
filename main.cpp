#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

//Необходимо реализовать метод
//о алгоритме можно прочитать в источниках указанных в программе курса, или на странице курса в ЛМС или в презентациях к семинару.
int Wagner_Fischer(string& s, string& t)
{
    int **arr = new int* [s.size() + 1];

    for (int i = 0; i <= s.size(); i++)
    {
        arr[i] = new int[t.size() + 1];
        arr[i][0] = i;
    }

    for (int j = 0; j <= t.size(); j++)
        arr[0][j] = j;

    for (int i = 1; i <= s.size(); i++)
    {
        for (int j = 1; j <= t.size(); j++)
        {
            arr[i][j] = min(min((arr[i - 1][j] + 1), (arr[i][j - 1] + 1)), (arr[i - 1][j - 1] + (s[i - 1] == t[j - 1] ? 0 : 1)));
        }
    }

    int result =  arr[s.size()][t.size()];

    for (int i = 0; i <= s.size(); i++)
    {
        delete[] arr[i];
    }
    delete[] arr;

    return result;
}

//Не изменять метод main без крайней необходимости
//ОБЯЗАТЕЛЬНО добавить в комментариях подробные пояснения и причины побудившие вас изменить код этого метода.
int main(int argc, const char * argv[])
{
    int n;
    fstream fin;
    fstream fout;
    fin.open("input.txt",ios::in);
    fout.open("output.txt",ios::out);
    if(fin.is_open()) {
        string N;
        getline(fin,N);
        n = atoi( N.c_str());
        for (int i = 0; i < n; i++) {
            string s;
            string t;
            getline(fin,s);
            getline(fin,t);
            fout << Wagner_Fischer(s, t) << (i == n-1 ? "" : " ");
        }
        fout.close();
        fin.close();
    }
    return 0;
}