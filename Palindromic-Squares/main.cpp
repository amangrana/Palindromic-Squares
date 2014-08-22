/*
 ID: dearxia1
 PROG: palsquare
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

char map[21] = "0123456789ABCDEFGHIJ";

bool check(char *a)
{
    for (char *b = a + strlen(a) - 1; b > a; a ++, b --) {
        if (*a != *b)
            return false;
    }
    return true;
}

void trans(int a, int b, char *c)
{
    int digit = 0;
    while (a >= b) {
        c[digit] = map[a % b];
        digit ++;
        a = a / b;
    }
    c[digit] = map[a];
    c[digit + 1] = '\0';
}

int main()
{
    //ofstream fout ("palsquare.out");
    //ifstream fin ("palsquare.in");
    int B, N;
    char temp[20], tem[20];
    cin >> B;
    for (N = 1; N <= 300; N ++) {
        trans(N * N, B, temp);
        if (check(temp)) {
            trans(N, B, tem);
            for (int i = strlen(tem) - 1; i >= 0; i --)
                cout <<tem[i];
            cout << ' ' << temp << '\n';
        }
    }
    return 0;
}
