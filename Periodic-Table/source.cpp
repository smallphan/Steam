#include <bits/stdc++.h>

const int lim = 36;

std::map<int, std::string> find;

inline void init();

int main() {
    srand(time(NULL) + 114514);
    init();
    while (true) {
        double s, e;
        bool tag = false;
        int tmp = rand() % lim + 1;
        s = clock();
        if (rand() % 2) {
            printf("%d : ", tmp);
            std::string now;
            std::cin >> now;
            tag = now == find[tmp] ? true : false;
            if (!tag) printf("False | the answer is \""), std::cout << find[tmp] << "\" | ";
        } else {
            std::cout << find[tmp] << " : ";
            int now;
            scanf("%d", &now);
            tag = now == tmp ? true : false;
            if (!tag) printf("False | the answer is %d | ", tmp);
        }
        if (tag) printf("True | ");
        e = clock();
        printf("answered in %lfs...\n", (e - s) / 1000.0);
    }
    return 0;
}

inline void init() {
    find[1] = "H", find[2] = "He", find[3] = "Li", find[4] = "Be";
    find[5] = "B", find[6] = "C", find[7] = "N", find[8] = "O";
    find[9] = "F", find[10] = "Ne", find[11] = "Na", find[12] = "Mg";
    find[13] = "Al", find[14] = "Si", find[15] = "P", find[16] = "S";
    find[17] = "Cl", find[18] = "Ar", find[19] = "K", find[20] = "Ca";
    find[21] = "Sc", find[22] = "Ti", find[23] = "V", find[24] = "Cr";
    find[25] = "Mn", find[26] = "Fe", find[27] = "Co", find[28] = "Ni";
    find[29] = "Cu", find[30] = "Zn", find[31] = "Ga", find[32] = "Ge";
    find[33] = "As", find[34] = "Se", find[35] = "Br", find[36] = "Kr";
}