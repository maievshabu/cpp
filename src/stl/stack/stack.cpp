//
// Created by xiaowei003 on 2024/10/25.
//
#include <iostream>
using namespace std;
#include "stack.h"
#include <regex>
#include <queue>
#include <iterator>

void t71()
{
    std::string path = "/.../a/../b/c/../d/./";
//    std::regex multiple_slash("/+");
//    std::string result = std::regex_replace(path, multiple_slash, "/");

    std::deque<string> q2;
    std::stringstream ss(path);
    std::string token;
    while (std::getline(ss, token, '/')) {
        if (!token.empty()) {  // 忽略空的token
            q2.push_back(token);
            if (token == "."){
                q2.pop_back();
                continue;
            }

            if (token == ".."){
                q2.pop_back();
                if (!q2.empty()){
                    q2.pop_back();
                }

                continue;
            }
        }
    }

    std::string res;

    for(auto it = q2.begin(); it  != q2.end(); ++it){
        if (!res.empty()){
            res += "/";
        }

        if (*it == ".."){
            *it = "";
        }

        res += *it;
    }

    res = "/" + res;
    cout << "source is ::: " << path << endl;
    cout << "result is ::: " << res;
}

int main(void)
{
//    std::vector<int>::iterator it;
//    std::vector<int>::iterator it2(it);
//
    std::vector<int> col{11,2,31,3};
//    auto aa = col.begin();
//    it = col.begin();
//
//    if (aa == it){
//        cout << "equal it " << endl;
//    }
//
//    advance(aa, 2);
//    std::sort(col.begin() ,col.end());

//    ostream_iterator<int> os(cout, "\n");
//    os = 1;
//    os++;
//    os = 2;
//    os++;
//    os = 3;
//
//    copy(col.begin(), col.end(), os);
//    copy(col.begin(), col.end(), ostream_iterator<int>(cout, "-"));

//    istream_iterator<int> intReader(cin), eof;
//
//    while(intReader != eof){
//        cout << "once   " << *intReader << endl;
//        cout << "once  again " << *intReader << endl;
//        ++intReader;
//    }

//    t71();
//    std::vector<int> vec = {1,2,3};
//    permute(vec,0, vec.size() - 1 );
}