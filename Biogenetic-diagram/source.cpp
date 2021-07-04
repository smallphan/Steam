#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>

using namespace std;

const int maxn = 1005;
int size;
char one[maxn], two[maxn];
char gameteone[maxn][3], gametetwo[maxn][3];
char genotypeone[maxn * 10][maxn], genotypetwo[maxn * 10][maxn];
char dl[maxn];
int cntone, cnttwo;

void dfs(int depth, char gamete[maxn][3], char genotype[maxn * 10][maxn], int &cnt) {
    if (depth == size / 2 + 1) {
        cnt++;
        for (int i = 1; i <= depth - 1; i++) {
            genotype[cnt][i] = dl[i];
        }
        return;
    }
    if (gamete[depth][1] == gamete[depth][2]) {
        dl[depth] = gamete[depth][1];
        dfs(depth + 1, gamete, genotype, cnt);
    } else {
        dl[depth] = gamete[depth][1];
        dfs(depth + 1, gamete, genotype, cnt);
        dl[depth] = gamete[depth][2];
        dfs(depth + 1, gamete, genotype, cnt);
    }
}
int main() {
    freopen("output.txt", "w", stdout);
    cin >> one >> two;
    size = strlen(one);
    if (size != strlen(two)) {
        cout << "wrong data was put in." << endl << "procedure ends." << endl;
        return 0;
    }
    for (int i = 0; i < size; i += 2) {
        gameteone[i / 2 + 1][1] = one[i];
        gameteone[i / 2 + 1][2] = one[i + 1];
        gametetwo[i / 2 + 1][1] = two[i];
        gametetwo[i / 2 + 1][2] = two[i + 1];
    }
    dfs(1, gameteone, genotypeone, cntone);
    dfs(1, gametetwo, genotypetwo, cnttwo);
    for (int i = 1; i <= cntone; i++) {
        for (int j = 1; j <= cnttwo; j++) {
            for (int k = 1; k <= size / 2; k++) {
                if (genotypeone[i][k] < genotypetwo[j][k]) {
                    cout << genotypeone[i][k] << genotypetwo[j][k];
                } else {
                    cout << genotypetwo[j][k] << genotypeone[i][k];
                }
            }
            cout << ' ';
        }
        cout << endl;
    }
    return 0;
}