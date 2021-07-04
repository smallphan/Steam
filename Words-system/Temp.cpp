#include <bits/stdc++.h>

namespace NAMES {

    // GLOBAL {

        const int maxWordNum = 1e5 + 5; // the max number of words
        const int maxWordClassNum = 15; // the max number of word classes
        const int totalwordClassNum = 12; // the now number of word classes

        struct node {

            std::string name;
            int book, unit;
            std::vector<std::string> translate[maxWordClassNum];

            inline void ouputName() {
                std::cout << "[" << name << "] ";
            }

            inline void ouputFrom() {
                if (unit) printf("from Book %d Unit %d\n", book, unit);
                else printf("from Book %d Welcome Unit\n", book);
            }

            inline void ouputTranslate() {
                for (int i = 1; i <= totalwordClassNum; i++) {
                    if (translate[i].size()) {
                        std::cout << "    " << findName[i];
                        for (int j = 0; j < translate[i].size(); j++) {
                            std::cout << translate[i][j];
                            if (j != translate[i].size() - 1) putchar(',');
                        }
                        puts(";");
                    }
                }
            }

            inline void ouput() {
                ouputName(), ouputFrom(), ouputTranslate();
            }
            
        } words[maxWordNum]; // words 
        int wordCnt; // the now number of words
        
        std::string fir, sec, thi; // temp strings
        std::map<std::string, int> findNum; // find a word classes' number
        std::string findName[maxWordClassNum]; // find a word classes' name

    // }

    // LOADING {

        int head, tail, midd;
        
    // }

    // RUNNING {

    // }

    // CLOSING {

    // }
    
}

namespace FUNCS {

    inline void findString(std::string str, int& head, int& tail, int& midd) { // find a string's head and tail
        head = 0, tail = str.length() - 1, midd = -1;
        while (str[tail] == '\n' || str[tail] == ' ') tail--;
        while (str[head] == '\n' || str[head] == ' ') head++;
        for (int i = head; i <= tail; i++) if (str[i] == '|') { midd = i; break; }
    }

}

using namespace NAMES;
using namespace FUNCS;

namespace LOADING {

    inline void init() {
        findNum["n."] = 1, findNum["pron."] = 2, findNum["adj."] = 3, findNum["adv."] = 4;
        findNum["vi."] = 5, findNum["vt."] = 6, findNum["num."] = 7, findNum["art."] = 8;
        findNum["prep."] = 9, findNum["conj."] = 10, findNum["interj."] = 11, findNum["abbr."] = 12;
        findNum["phrase."] = 13;
        findName[1] = "n.", findName[2] = "pron.", findName[3] = "adj.", findName[4] = "adv.";
        findName[5] = "vi.", findName[6] = "vt.", findName[7] = "num.", findName[8] = "art.";
        findName[9] = "prep.", findName[10] = "conj.", findName[11] = "interj.", findName[12] = "abbr.";
        findName[13] = "phrase.";
    }

    inline void input() {
        // freopen("Config.ini", "r", stdin);
        while (std::getline(std::cin, fir)) {
            FUNCS::findString(fir, head, tail, midd);
            for (int i = head; i <= midd - 1; i++) sec
        }
    }

    inline void master() {
        LOADING::init();
        LOADING::input();
    }

}

namespace RUNNING {
    
    inline void master() {
        
    }

}

namespace CLOSING {

    inline void master() {
        
    }

}

int main() {
    LOADING::master();
    RUNNING::master();
    CLOSING::master();
}