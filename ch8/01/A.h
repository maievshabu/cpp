//
// Created by xiaowei003 on 2024/9/28.
//

#ifndef UNTITLED_A_H
#define UNTITLED_A_H

namespace ch801{
    class A {
    };

    template<typename T>
    void printV(T arg){
        cout  << "---------------" << endl;
        cout << "arg is const:" << std::is_const<T>::value <<endl;
        cout << "arg is ref:" << std::is_reference<T>::value <<endl;
        cout << "arg:" << arg << endl;
        cout  << "---------------" << endl;
    }

    template <typename T>
    void outR(T& arg){
        if (std::is_array<T>::value){
            cout << "got array of :" << std::extent<T>::value << endl;
        }
    }

    template <typename T>
    void passR(T&& arg)
    {
        cout << "arg is const:" << std::is_const<T>::alue <<endl;
        cout << "arg is ref:" << std::is_reference<T>::value <<endl;
        cout << "------------------" << endl;
    }

    void printStr(std::string const & s)
    {
        cout << s << endl;
    }

    template <typename T>
    void printStr(T arg)
    {
        cout << "arg is ref:" << std::is_reference<T>::value <<endl;
        printStr(arg);
    }

    template <typename T>
    void printT(T arg)
    {
        cout << "arg is ref:" << std::is_reference<T>::value <<endl;
        cout << "------------------" << endl;
    }

    std::string returnString()
    {
        return "Hi";
    }

    std::string const returnConstantString()
    {
        std::string const hi = "HI";

        return hi;
    }
}



#endif //UNTITLED_A_H
