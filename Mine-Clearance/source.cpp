#include <windows.h>
#include <bits/stdc++.h>

inline long long read() {
    char str = getchar();
    long long ans = 0, tag = 1;
    while (str < '0' || str > '9') {
        tag = str == '-' ? -1 : 1;
        str = getchar();
    }
    while (str >= '0' && str <= '9') {
        ans = ans * 10 + str - '0';
        str = getchar();
    }
    return ans * tag;
}

namespace CodeRun {
    inline void Init();
    inline void Run();    
}

namespace Functions {
    inline void Draw();
    void DFS(int, int);
}

namespace End {
    inline void Success();
    inline void Fail();
}

const int maxn = 105, maxm = 105;
int n, m, num, now;
int map[maxn][maxm];
bool cover[maxn][maxm];
double s, e;

int main() {
    CodeRun::Run();
    return 0;
}

namespace CodeRun { // The Code in Charge of Running
    inline void Init() {
        srand(time(NULL) + 114514);
        puts("Please Define Your Game.");
        printf("\nInput [Length]\n>>> "), n = read();
        while (n <= 0 || n >= 100) {
            puts("\nWrong Number!");
            printf("\nInput [Length]\n>>> "), n = read();
        }
        printf("\nInput [Width]\n>>> "), m = read();
        while (m <= 0 || m >= 100) {
            puts("\nWrong Number!");
            printf("\nInput [Width]\n>>> "), m = read();
        }
        printf("\nInput [The Number Of Mines]\n>>> "), num = read();
        while (num >= n * m) {
            puts("\nWrong Number!");
            printf("\nInput [The Number Of Mines]\n>>> "), num = read();
        }
        puts("\nData Received.......\n");
        Sleep(1000);
        system("cls");
    }

    inline void Run() {
        CodeRun::Init();
        for (int i = 1; i <= num; i++) {
            int x = 1 + rand() % n, y = 1 + rand() % m;
            if (map[x][y] == -1) { i--; continue; }
            else map[x][y] = -1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (map[i][j] == -1) continue;
                else {
                    int sum = 0;
                    for (int k = -1; k <= 1; k++) {
                        for (int l = -1; l <= 1; l++) {
                            if (map[i + k][j + l] == -1) sum++;
                        }
                    }
                    map[i][j] = sum;
                }
            }
        }
        s = clock();
        while (now < n * m - num) {
            Functions::Draw();
            int x, y;
            printf("\n            Input [x]\n            >>> "), x = read();
            printf("\n            Input [y]\n            >>> "), y = read();
            if (x < 1 || x > n || y < 1 || y > m) {
                puts("\nWrong Number! Please Input Again.");
                Sleep(1000);
            }
            if (cover[x][y]) {
                printf("\n            (%d, %d) Has Been Coverd.", x, y);
                Sleep(1000);
                continue;
            } else if (map[x][y] == -1) {
                End::Fail();
                return;
            } else {
                if (map[x][y] == 0) {
                    Functions::DFS(x, y);
                } else {
                    cover[x][y] = true;
                    now++;
                }
            }
        }
        End::Success();
    }
}

namespace Functions { // Functions
    inline void Draw() { // Draw Map 
        system("cls");
        puts("\n"), printf("            "); // 12 Spaces
        printf("[Covered] %d    [Left] %d\n", now, n * m - now);
        printf("            ");
        for (int i = 1; i <= 3 * m + 11; i++) printf("_");
        puts("\n");
        printf("                 y  ");
        for (int i = 1; i <= m; i++) printf("%02d ", i);
        puts("");
        printf("                    ");
        for (int i = 1; i <= m * 3 - 1; i++) printf("_");
        puts("\n             x");
        for (int i = 1; i <= n; i++) {
            printf("            %02d  |   ", i);
            for (int j = 1; j <= m; j++) {
                if (cover[i][j]) printf(map[i][j] == -1 ? "*  " : "%d  ", map[i][j]);
                else printf("-  ");
            }
            puts("  |");
        }
        puts("");
        printf("                    ");
        for (int i = 1; i <= m * 3 - 1; i++) printf("_");
        puts("\n");
    }

    void DFS(int x, int y) {
        if (map[x][y] >= 1) {
            cover[x][y] = true;
            now++;
            return;
        } else if (map[x][y] == 0) {
            cover[x][y] = true;
            now++;
            if (x + 1 <= n && map[x + 1][y] >= 0 && !cover[x + 1][y]) {
                Functions::DFS(x + 1, y);
            }
            if (x - 1 >= 1 && map[x - 1][y] >= 0 && !cover[x - 1][y]) {
                Functions::DFS(x - 1, y);
            }
            if (y + 1 <= m && map[x][y + 1] >= 0 && !cover[x][y + 1]) {
                Functions::DFS(x, y + 1);
            }
            if (y - 1 >= 1 && map[x][y - 1] >= 0 && !cover[x][y - 1]) {
                Functions::DFS(x, y - 1);
            }
        }
    }
}

namespace End {
    inline void Success() { // Success! QWQ
        now = n * m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cover[i][j] = true;
            }
        }
        Functions::Draw();
        e = clock();
        printf("\n            Congratulations! You Have Succeeded in %.5lf seconds......\n\n", (e - s) / 1000);
    }

    inline void Fail() { // Fail! TAT
        now = n * m;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cover[i][j] = true;
            }
        }
        Functions::Draw();
        e = clock();
        printf("\n            You Have Lost in %.5lf seconds......\n\n", (e - s) / 1000);
    }
}