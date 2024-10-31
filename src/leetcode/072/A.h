//
// Created by xiaowei003 on 2024/10/30.
//

/**
 * 72. Edit Distance
Medium
Topics
Companies
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character


Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')


Constraints:

0 <= word1.length, word2.length <= 500
word1 and word2 consist of lowercase English letters.
 *
 */

#ifndef UNTITLED_A_H
#define UNTITLED_A_H
#include <iostream>
#include <string>
#include <iterator>

using namespace std;

class A {
public:
    int minDistance(const std::string & word1, const std::string & word2){
        int d{0};
        auto it1 = word1.begin();
        auto it2 = word2.begin();
        while(it1 != word1.end() || it2 != word2.end()){
            if (it1 == word1.end()){ //word1结束
                ++d;
                break;
            }

            if (it2 == word2.end()){ //word2结束
                ++d;break;
            }

            if (*it1 != *it2){ //都
                break;
            }

            ++d;
            ++it1;
            ++it2;
        }
        return d;
    }
};

void test()
{
    A a;
    string word1("sea"), word2("eat");
    int d = a.minDistance(word1, word2);

    cout << "the distance between " << word1;
    cout << " and " << word2;
    cout << " is " << d;
}

#endif //UNTITLED_A_H
