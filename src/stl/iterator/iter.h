//
// Created by xiaowei003 on 2024/10/29.
//

#ifndef UNTITLED_ITER_H
#define UNTITLED_ITER_H

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

class Iter {
public:
    void test();
private:
    void reverse();
    void insert();
    void stream();
    void move();
};

void Iter::reverse()
{
    cout << "reverse" << endl;
}

void Iter::insert() {
    cout << "insert" << endl;
}

void Iter::stream() {
    cout << "stream" << endl;
    istream_iterator<string> is(cin);
    ostream_iterator<string> os(cout, " ");

    while(is != istream_iterator<string>()){
        advance(is, 2);

        if (is != istream_iterator<string>()){
            *os++ = *is++;
        }
    }

    cout << endl;
}

void Iter::move(){
    cout << "move" << endl;
    std::list<string> ls;
    ls.push_back("aa");
    ls.push_back("bb");
    ls.push_back("cc");

    std::vector<string> v1(ls.begin(), ls.end());
    ostream_iterator<string> os(cout, " ");
    copy(v1.begin(),v1.end(), os);
}

void Iter::test()
{
//    reverse();
//    insert();
//    stream();
    move();
}


#endif //UNTITLED_ITER_H
