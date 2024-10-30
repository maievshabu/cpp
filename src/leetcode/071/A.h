//
// Created by xiaowei003 on 2024/10/28.
//


/**
71. Simplify Path
Solved
        Medium
Topics
        Companies
You are given an absolute path for a Unix-style file system, which always begins with a slash '/'. Your task is to transform this absolute path into its simplified canonical path.

The rules of a Unix-style file system are as follows:

A single period '.' represents the current directory.
A double period '..' represents the previous/parent directory.
Multiple consecutive slashes such as '//' and '///' are treated as a single slash '/'.
Any sequence of periods that does not match the rules above should be treated as a valid directory or file name. For example, '...' and '....' are valid directory or file names.
The simplified canonical path should follow these rules:

The path must start with a single slash '/'.
Directories within the path must be separated by exactly one slash '/'.
The path must not end with a slash '/', unless it is the root directory.
The path must not have any single or double periods ('.' and '..') used to denote current or parent directories.
Return the simplified canonical path.



Example 1:

Input: path = "/home/"

Output: "/home"

Explanation:

The trailing slash should be removed.

Example 2:

Input: path = "/home//foo/"

Output: "/home/foo"

Explanation:

Multiple consecutive slashes are replaced by a single one.

Example 3:

Input: path = "/home/user/Documents/../Pictures"

Output: "/home/user/Pictures"

Explanation:

A double period ".." refers to the directory up a level (the parent directory).

Example 4:

Input: path = "/../"

Output: "/"

Explanation:

Going one level up from the root directory is not possible.

Example 5:

Input: path = "/.../a/../b/c/../d/./"

Output: "/.../b/d"

Explanation:

"..." is a valid name for a directory in this problem.



Constraints:

1 <= path.length <= 3000
path consists of English letters, digits, period '.', slash '/' or '_'.
path is a valid absolute Unix path.
 **/

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
