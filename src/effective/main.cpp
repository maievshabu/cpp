//
// Created by redredmaple on 2026/1/9.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "01/empty.h";
#include <mutex>

using namespace std;

int main(){

    /**
     *
     * #6 若不想使用编译器自动生成的函数，就该明确拒绝(这里是只构造函数)
     * #7 为多态基类添加virtual析构函数
     * #8 别让异常逃离析构函数
     * #9 不要在构造和析构中调用virtual函数
     * #10 令operator= 返回一个reference to *this
     * #11 在operator=中处理自我赋值
     * #12 复制对象时勿忘每一个成分
     * #13 以对象管理资源
     * #14 在资源管理类中小心coping行为
     * #15 在资源管理类中提供对原始资源的访问
     * #16 成对使用new和delete时要采取相同形式
     * #17 以独立语句将newed对象置入智能指针
     * #18 让接口容易被正确使用，不易被误用
     * #19 设计class犹如设计type
     * #20 宁以pass-by-reference-to-const替换pass-by-value
     * #21 必须返回对象时，别妄想返回其reference
     * #22 将成员变量声明为private
     * #23 宁以non-member,non-friend替换member函数
     * #24 若所有参数皆需类型转行，请为此采用non-member函数
     * #25 考虑写出一个不抛异常的swap函数
     * #26 尽可能延后变量定义式的出现时间
     * #27 尽可能稍作转型动作（P155）
     * #28
     * #29
     * #30
     * #31
     * #32
     *
     */



    std::cout << "Effective C++" << std::endl;
    d109::test();

    return 0;
}