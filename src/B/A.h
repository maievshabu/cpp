//
// Created by xiaowei003 on 2024/8/18.
//

#ifndef UNTITLED_A_H
#define UNTITLED_A_H

//class Info{
//public:
//    Info(){InitReset();}
//    Info(int i): Info() { type = i;}
//    Info(char e): Info() { name = e;}
//
//private:
//    void InitReset() {}
//    int type {1};
//    char name {'a'};
//};

//#委派构造函数
class Point{
public:
    Point(int x, int y): _x(x), _y(y){std::cout<<"Two paramter constructor called"<<std::endl;}
    Point(int x): Point(x, 0){std::cout<<"One paramter constructor called"<< std::endl;}
    Point(): Point(0,0) {std::cout<<"Default construct called" << std::endl;}
//    Point():Point(0), _y(0){} ,不能同时委派哦

    void printX() {std::cout<<"(" << _x <<","<<_y <<")" <<std::endl;}
private:
//    Point(int x, int y) : _x(x), _y(y) {}
    int _x,_y;
};

class DCException{
public:
    DCException(double d) try:DCException(1,d){
        cout<< "Run the body~" <<endl;
    }catch (...){
        cout << "caught exception." <<endl;
    }

private:
    DCException(int i, double b){
        cout << "going  to throw" <<endl;
        throw 0;
    }
    int type;
    int data;
};

#endif //UNTITLED_A_H
