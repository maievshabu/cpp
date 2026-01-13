//
// Created by redredmaple on 2026/1/9.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "01/empty.h"
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
     * #28 避免返回handles指向对象内部成分
     * #29 为"异常安"全而努力是值得的
     * #30 透彻了解inline的里里外外
     * #31 将文件间的编译依存关系降至最低
     * #32 确定你的public继承塑模出is-a关系
     * #33 避免遮掩继承而来的名称
     * #34 区分接口继承和实现继承
     * #35 考虑virtual函数以外的其他选择
     * #36 绝不重新定义继承而来的non-virtual函数
     * #37 绝不重新定义继承而来的缺省参数值
     * #38 通过复合塑模出has-a或者根据某物实现出
     * #39 明智而审慎地使用private继承
     * #40 明智而审慎地使用多重继承
     * #41 了解隐式接口和编译期多态
     * #42 了解typename的双重意义
     * #43 学习处理模板化基类内的名称
     * #44 将与参数无关的代码抽离template
     * #45 运用成员函数模板接收所有兼容类型
     * #46 需要类型转行时请用模板定义非成员函数
     * #47 请使用traits classes表现类型信息
     * #48 认识template元编程
     * #49 了解new-handler的行为
     * #50 了解new和delete的合理替换时机
     * #51 编写new和delete时需固守常规
     * #52 写了placement new 也要写placement delete
     * #53 不要轻忽编译器的警告
     * #54 让自己熟悉包括tr1在内的标准程序库
     * #55 让自己熟悉Boost
     */


    typedef int UUIT;
    using uuid = int;

    std::cout << "Effective C++" << std::endl;
    d109::test();

    return 0;
}