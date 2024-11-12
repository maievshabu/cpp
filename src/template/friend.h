//
// Created by xiaowei003 on 2024/11/12.
//

#ifndef UNTITLED_FRIEND_H
#define UNTITLED_FRIEND_H

# 这里是友元的代码

#include <iostream>

class MyClass {
private:
    int privateValue;

public:
    MyClass(int value) : privateValue(value) {}

    // 声明友元函数
    friend void showPrivateValue(const MyClass& obj);
};

// 定义友元函数
void showPrivateValue(const MyClass& obj) {
    std::cout << "Private value: " << obj.privateValue << std::endl;
}

//int main() {
//    MyClass obj(42);
//    showPrivateValue(obj);  // 可以访问 MyClass 的私有成员
//    return 0;
//}


class ClassA {
private:
    int privateValueA;

public:
    ClassA(int value) : privateValueA(value) {}

    // 声明友元类
    friend class ClassB;
};

class ClassB {
public:
    void showPrivateValueA(const ClassA& obj) {
        std::cout << "ClassA's private value: " << obj.privateValueA << std::endl;
    }
};

//int main() {
//    ClassA objA(42);
//    ClassB objB;
//    objB.showPrivateValueA(objA);  // 可以访问 ClassA 的私有成员
//    return 0;
//}

template<typename T>
class MyClass {
private:
    T value;

public:
    MyClass(T val) : value(val) {}

    // 声明非模板友元函数
    friend void showValue(const MyClass& obj) {
        std::cout << "Value: " << obj.value << std::endl;
    }
};

//int main() {
//    MyClass<int> obj(42);
//    showValue(obj);  // 输出 Value: 42
//    return 0;
//}

template<typename T>
class MyClass {
private:
    T value;
public:
    MyClass(T val) : value(val) {}

    // 声明模板友元函数
    template<typename U>
    friend void showValue(const MyClass<U>& obj);
};

// 定义模板友元函数
template<typename U>
void showValue(const MyClass<U>& obj) {
    std::cout << "Value: " << obj.value << std::endl;
}

//int main() {
//    MyClass<int> obj(42);
//    showValue(obj);  // 输出 Value: 42
//    return 0;
//}

class FriendClass;

template<typename T>
class MyClass {
private:
    T value;

public:
    MyClass(T val) : value(val) {}

    // 声明非模板友元类
    friend class FriendClass;
};

class FriendClass {
public:
    template<typename T>
    void showValue(const MyClass<T>& obj) {
        std::cout << "Value: " << obj.value << std::endl;
    }
};

//int main() {
//    MyClass<int> obj(42);
//    FriendClass f;
//    f.showValue(obj);  // 输出 Value: 42
//    return 0;
//}

template<typename T>
class FriendClass;

template<typename T>
class MyClass {
private:
    T value;

public:
    MyClass(T val) : value(val) {}

    // 声明模板友元类
    template<typename U>
    friend class FriendClass;
};

template<typename T>
class FriendClass {
public:
    void showValue(const MyClass<T>& obj) {
        std::cout << "Value: " << obj.value << std::endl;
    }
};

//int main() {
//    MyClass<int> obj(42);
//    FriendClass<int> f;
//    f.showValue(obj);  // 输出 Value: 42
//    return 0;
//}

/**
 * 非模板友元函数：适用于所有模板实例化，但没有灵活的参数特化。

模板友元函数：可以根据不同的模板参数特化，更灵活。

非模板友元类：允许一个类的所有模板实例化访问私有成员，但自身不特化。

模板友元类：允许访问并根据不同模板参数特化，提供更大的灵活性
 *
 */


#endif //UNTITLED_FRIEND_H
