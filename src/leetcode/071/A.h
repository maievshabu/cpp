//
// Created by xiaowei003 on 2024/10/28.
//

#ifndef UNTITLED_A_H
#define UNTITLED_A_H


class A {

};


void t71(string ss)
{
    std::string path = "/.../a/../b/c/../d/./";
    std::regex multiple_slash("/+");
    std::string result = std::regex_replace(path, multiple_slash, "/");

    std::queue<string> q1;
    std::deque<string> q2;
    std::stringstream ss(result);
    std::string token;
    while (std::getline(ss, token, '/')) {
        if (token.empty() || token == ".") {
            continue; // 忽略空的token和当前目录
        }
        if (token == "..") {
            if (!q2.empty()) {
                q2.pop_back(); // 移除上一级目录
            }
        } else {
            q2.push_back(token); // 推入有效目录
        }
    }

    std::string res("");

    while (!q2.empty()) {
        if (!res.empty()) {
            res += "/";
        }

        if (q2.front() == ".."){
            q2.front() = "";
        }

        res += q2.front();
        q2.pop_front();
    }

    res = "/" + res;
    cout << "source is ::: " << path << endl;
    cout << "result is ::: " << res;
}

void t71()
{
    std::string path = "/.../a/../b/c/../d/./";
    std::regex multiple_slash("/+");
    std::string result = std::regex_replace(path, multiple_slash, "/");

    std::queue<string> q1;
    std::deque<string> q2;
    std::stringstream ss(result);
    std::string token;
    while (std::getline(ss, token, '/')) {
        if (!token.empty()) {  // 忽略空的token
            q1.push(token);
        }
    }

    std::string res("");
    while (!q1.empty()){
        auto ci = q1.front();
        q1.pop();

        if (ci == "."){
            continue;
        }

        if (ci == ".."){
            if (!q2.empty()){
                q2.pop_back();
            }

            continue;
        }

        q2.push_back(ci);
    }

    while (!q2.empty()) {
        if (!res.empty()) {
            res += "/";
        }

        if (q2.front() == ".."){
            q2.front() = "";
        }

        res += q2.front();
        q2.pop_front();
    }

    res = "/" + res;
    cout << "source is ::: " << path << endl;
    cout << "result is ::: " << res;
}

#endif //UNTITLED_A_H
