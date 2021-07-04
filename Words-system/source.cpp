// Copyright (c) smallphan

/**
 *    __      __   ___    ___   ___    ___     ___  __   __  ___   _____   ___   __  __ 
 *    \ \    / /  / _ \  | _ \ |   \  / __|   / __| \ \ / / / __| |_   _| | __| |  \/  |
 *     \ \/\/ /  | (_) | |   / | |) | \__ \   \__ \  \ V /  \__ \   | |   | _|  | |\/| |
 *      \_/\_/    \___/  |_|_\ |___/  |___/   |___/   |_|   |___/   |_|   |___| |_|  |_|
 **/ 

#include <windows.h>
#include <bits/stdc++.h>

const int eChouSeed = 114514;
const int totalWordClass = 12;

int findPos[105][1005];
int sumOfBook, sumOfUnit[105];

std::string tmp1, tmp2, tmp3;
std::string opFindWordClass[15];

struct aode {
    std::string name;
    int book, unit;
    std::vector<std::string> translate[15];
    
    /*
     * 01) n. noun 名词
     * 02) pron. pronoun 代词 
     * 03) adj. adjective 形容词	
     * 04) adv. adverb 副词 
     * 05) vi. intransitive verb 不及物动词
     * 06) vt. transitive verb 及物动词	
     * 07) num. numeral 数词
     * 08) art. article 冠词 	
     * 09) prep. preposition 介词 
     * 10) conj. conjunction 连词 
     * 11) interj. interjection 感叹词
     * 12) abbr. abbreviation 缩写
     */

    inline void ouputName() {
        std::cout << "[" << name << "] ";
    }

    inline void ouputFrom() {
        if (unit) printf("from Book %d Unit %d\n", book, unit);
        else printf("from Book %d Welcome Unit\n", book);
    }

    inline void ouputTranslate() {
        for (int i = 1; i <= totalWordClass; i++) {
            if (translate[i].size()) {
                std::cout << "    " << opFindWordClass[i];
                for (int j = 0; j < translate[i].size(); j++) {
                    std::cout << translate[i][j];
                    if (j != translate[i].size() - 1) putchar(',');
                }
                puts(";");
            }
        }
    }

    inline void ouput() {
        ouputName();
        ouputFrom();
        ouputTranslate();
    }
} word[100005];
int wordCnt;

namespace USE {

    inline void logo() {
        puts("");
        puts(" __      __   ___    ___   ___    ___     ___  __   __  ___   _____   ___   __  __ ");
        puts(" \\ \\    / /  / _ \\  | _ \\ |   \\  / __|   / __| \\ \\ / / / __| |_   _| | __| |  \\/  |");
        puts("  \\ \\/\\/ /  | (_) | |   / | |) | \\__ \\   \\__ \\  \\ V /  \\__ \\   | |   | _|  | |\\/| |");
        puts("   \\_/\\_/    \\___/  |_|_\\ |___/  |___/   |___/   |_|   |___/   |_|   |___| |_|  |_|");
        puts("");
    }

    inline void ouputNumberStd(int num) {
        printf("--- %02d ---\n", num);
    }

    inline int random(int mod) {
        return 1ll * rand() * rand() % mod;
    }
    
    inline void commandLineHead() {
        printf(">>> ");
    }

    inline void ouputWords() {
        for (int i = 1; i <= wordCnt; i++) word[i].ouput();
    }

    inline void ouputPos() {
        for (int i = 1; findPos[i][1]; i++) {
            for (int j = 1; findPos[i][j]; j++) {
                printf("Book %d Unit %d : %d\n", i, j, findPos[i][j]);
            }
        }
    }

    inline void ouputSumOfBookAndUnit() {
        printf("The sum of Book : %d\n", sumOfBook);
        for (int i = 1; i <= sumOfBook; i++) {
            printf("The sum of Book %d Unit : %d\n", i, sumOfUnit[i]);
        }
    }
    
}

namespace LOADING {
    
    int nowClass, numOfBook, numOfUnit, sumOfWord;
    std::map<std::string, int> findWordClass;
    
    inline void init() {
        findWordClass["n."] = 1, findWordClass["pron."] = 2, findWordClass["adj."] = 3;
        findWordClass["adv."] = 4, findWordClass["vi."] = 5, findWordClass["vt."] = 6;
        findWordClass["num."] = 7, findWordClass["art."] = 8, findWordClass["prep."] = 9;
        findWordClass["conj."] = 10, findWordClass["interj."] = 11, findWordClass["abbr."] = 12;

        opFindWordClass[1] = "n.", opFindWordClass[2] = "pron.", opFindWordClass[3] = "adj.";
        opFindWordClass[4] = "adv.", opFindWordClass[5] = "vi.", opFindWordClass[6] = "vt.";
        opFindWordClass[7] = "num.", opFindWordClass[8] = "art.", opFindWordClass[9] = "prep.";
        opFindWordClass[10] = "conj.", opFindWordClass[11] = "interj.", opFindWordClass[12] = "abbr.";
    }

    inline void dealTranslate() {
        tmp3 = "", nowClass = 0;
        for (int i = 0; i < tmp2.length(); i++) {
            if (tmp2[i] == ',' || tmp2[i] == ';') {
                word[wordCnt].translate[nowClass].push_back(tmp3);
                tmp3 = "";
            } else {
                tmp3 += tmp2[i];
                if (findWordClass[tmp3]) {
                    nowClass = findWordClass[tmp3];
                    tmp3 = "";
                }
            }
        }
        word[wordCnt].translate[nowClass].push_back(tmp3);
    }

    inline void animationBefore() {
        system("cls"), USE::logo();
        printf("\nLoading [");
        for (int i = 1; i <= 73; i++) printf(" ");
        printf("]");
    }

    inline void animationAfter() {
        for (int i = 1; i <= 74; i++) printf("\b");
        for (int i = 1; i <= 73; i++) printf("#"), Sleep(10);
        printf("\n\n");
        Sleep(500);
        for (int i = 1; i <= 30; i++) printf(" ");
        for (int i = 1; i <= 2; i++) {
            if (i == 2) for (int j = 1; j <= 23; j++) printf("\b");
            printf(" Loading successfully. "), Sleep(300);
            if (i != 2) {
                for (int j = 1; j <= 23; j++) printf("\b \b");
                for (int j = 1; j <= 23; j++) printf(" ");
                Sleep(300);
            }
        }
        Sleep(1000), system("cls");
    }

    inline void master() {
        srand(time(NULL) + eChouSeed);
        freopen("Config.ini", "r", stdin);
        LOADING::init(), LOADING::animationBefore();
        while (std::cin >> tmp1) {
            if (tmp1 == "Book") {
                scanf("%d", &numOfBook);
                sumOfBook++;
            } else if (tmp1 == "Unit") {
                scanf("%d %d", &numOfUnit, &sumOfWord);
                sumOfUnit[numOfBook] = std::max(sumOfUnit[numOfBook], numOfUnit);
                findPos[numOfBook][numOfUnit] = wordCnt + 1;
                for (int i = 1; i <= sumOfWord; i++) {
                    std::cin >> tmp1 >> tmp2;
                    word[++wordCnt].name = tmp1;
                    word[wordCnt].book = numOfBook;
                    word[wordCnt].unit = numOfUnit;
                    LOADING::dealTranslate();
                }
            }
        }
        LOADING::animationAfter();
        std::cin.clear();
        freopen("CON", "r", stdin);
    }

}

namespace RUNNING {

    struct bode {
        int fir, sec; bool thi;
        inline bool operator < (const bode& tmp) const {
            return fir < tmp.fir;
        }
    } seq[100005];

    // *********************************** // Search mode // *********************************** // 

    inline void Search() { 
        puts("\n--- Search mode ---\n");
        bool notFind = true;
        while (true) {
            USE::commandLineHead(), std::cin >> tmp2, notFind = true;
            if (tmp2 == "Search" || tmp2 == "Lis-Wri" || tmp2 == "Exit") {
                tmp1 = tmp2;
                return;
            }
            printf("\n");
            if (std::isalnum(tmp2[0])) {
                for (int i = 1; i <= wordCnt; i++) {
                    if (word[i].name == tmp2) {
                        word[i].ouput(), notFind = false;
                        break;
                    }
                }
            } else {
                for (int i = 1; i <= wordCnt; i++) {
                    bool isThisWordFind = false;
                    for (int j = 1; j <= totalWordClass; j++) {
                        for (int k = 0; k < word[i].translate[j].size(); k++) {
                            if (word[i].translate[j][k] == tmp2) {
                                word[i].ouput(), notFind = false;
                                isThisWordFind = true;
                                break;
                            }
                        }
                        if (isThisWordFind) break;
                    }
                }
            }
            if (notFind) printf("Nothing was found.\n");
            printf("\n");
        }
    }

    // ***************************** // Listen and Write mode // ******************************* // 

    inline void lisWriGrammar() {
        puts("\n--- Listen and Write mode ---");
        puts("\nInput \"a b\" to Listen and Write the Words from Book a Unit b.");
        puts("Especially input \"0\" as b if it is \"Welcome Unit\".\n");
    }

    inline void getRandSequence(int lim) {
        for (int i = 1; i <= lim; i++) {
            seq[i] = (bode) { USE::random(500000), i, false };
        }
        std::sort(seq + 1, seq + 1 + lim);
    }

    inline void lisWri() { 
        RUNNING::lisWriGrammar();
        int findBook, findUnit, toStart, toEnd, sumOfTrue = 0;
        USE::commandLineHead(), scanf("%d %d", &findBook, &findUnit);
        if (findBook > sumOfBook || findUnit > sumOfUnit[findBook]) {
            printf("\nBook %d Unit %d was not found.\n", findBook, findUnit);
            tmp1 = "default";
            return;
        }
        toStart = findPos[findBook][findUnit];
        toEnd = (findUnit == sumOfUnit[findBook]) ? 
        (findBook == sumOfBook ? wordCnt : (findPos[findBook + 1][1] - 1)) :
        (findPos[findBook][findUnit + 1] - 1);
        RUNNING::getRandSequence(toEnd - toStart + 1);
        printf("\nThere are %d Words in total. Are you ready?\n\n", toEnd - toStart + 1);
        Sleep(1000);
        double s = clock();
        int nowPos;
        for (nowPos = 1; nowPos <= toEnd - toStart + 1; nowPos++) {
            USE::ouputNumberStd(nowPos), word[toStart - 1 + seq[nowPos].sec].ouputTranslate();
            USE::commandLineHead(), std::cin >> tmp2;
            if (tmp2 == word[toStart - 1 + seq[nowPos].sec].name) {
                sumOfTrue++, seq[nowPos].thi = true;
            }
            if (tmp2 == "Exit" || tmp2 == "Lis-Wri" || tmp2 == "Search") {
                tmp1 = tmp2;
                break;
            }
            puts("");
        }
        double e = clock();
        printf("\nAnswered in %lfs....\n", (e - s) / 1000.0);
        if (sumOfTrue == nowPos - 1) puts("\nCongratulations! All Correct.");
        else {
            printf("\n%d mistake%s in total.\n", nowPos - 1 - sumOfTrue, (nowPos - 1 - sumOfTrue) > 1 ? "s" : "");
            for (int i = 1; i <= nowPos - 1; i++) {
                if (!seq[i].thi) {
                    USE::ouputNumberStd(i);
                    word[toStart - 1 + seq[i].sec].ouput();
                }
            } 
        }
        if (tmp1 != tmp2) tmp1 = "default";
    }

    // *************************************** // master // ************************************ //

    inline void masterGrammar() {
        puts("\nInput \"Search\" to choose \"Search mode\".");
        puts("Or input \"Lis-Wri\" to choose \"Listen and Write mode\".");
        puts("Or input \"Exit\" to exit.\n");
    }

    inline void master() {
        USE::logo(), RUNNING::masterGrammar();
        USE::commandLineHead(), std::cin >> tmp1;
        while (true) {
            if (tmp1 == "Search") RUNNING::Search();
            else if (tmp1 == "Lis-Wri") RUNNING::lisWri();
            else if (tmp1 == "Exit") return;
            else {
                RUNNING::masterGrammar();
                USE::commandLineHead(), std::cin >> tmp1;
            }
        }
    }
}

namespace CLOSING {

    inline void master() {
        puts("\nThanks for using, the program is over. :)\n");
        Sleep(1000);
        USE::logo();
        puts("\n");
        system("pause");
    }

}

int main() {
    LOADING::master();
    RUNNING::master();
    CLOSING::master();
}
