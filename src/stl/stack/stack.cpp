//
// Created by xiaowei003 on 2024/10/25.
//
#include <iostream>
using namespace std;
#include "stack.h"
#include <regex>
#include <queue>

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
    t71();
//    std::vector<int> vec = {1,2,3};
//    permute(vec,0, vec.size() - 1 );
}