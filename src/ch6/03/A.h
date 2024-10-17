//
// Created by xiaowei003 on 2024/9/12.
//

#ifndef UNTITLED_A_H
#define UNTITLED_A_H
#include <functional>
#include <exception>

namespace ch603{
    class A {
    private:
        std::function<void()> _callback;
    public:
        A(const std::function<void()> &f):_callback(f){}
        void notify(void){_callback();}
    };

    int test();

    class MyException : public exception
    {
        virtual const char * what() const throw()
        {
            return "My exception happened";
        }
    }myex;

    class Polygon{
    protected:
        int width, height;
    public:
        void set_values(int a, int b){
            width = a;
            height = b;
        }

//        virtual int area(){
//            return 0;
//        }
        virtual int area() = 0;

        void printArea(){
            cout << typeid(*this).name() << ":::area::" << this->area() << endl;
        }

        void xx();
    };

    class Rectangle : public Polygon {
    public:
        int area() { return width * height;}
    };

    class Triangle : public Polygon{
    public:
        int area() { return width * height / 2;}
    };
}


#endif //UNTITLED_A_H
