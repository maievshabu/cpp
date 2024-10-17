//
// Created by xiaowei003 on 2024/9/8.
//

#ifndef UNTITLED_A_H
#define UNTITLED_A_H
#include <memory>>

namespace chA01{
    class A {

    };

    enum Gender{
        MALE,
        FEMAILE,
    };

    class Type{
    public:
        enum type { GENERAL ,LIGHT ,MEDIUM, HEAVY };
        type val;
    public:
        Type (type t): val(t){}
        bool operator >= (const Type &t) { return val >= t.val;}
        static const Type General ,Light ,Medium, Heavy;
    };

    const Type Type::General(Type::GENERAL);
    const Type Type::Light(Type::LIGHT);
    const Type Type::Medium(Type::MEDIUM);
    const Type Type::Heavy(Type::HEAVY);

    class Category{
    public:
        enum category { PISTOL ,MACHINEGUN, CANNON };
        category val;
    public:
        Category(category c):val(c){}
        bool operator >= (const Category & c) { return val > c.val; }
        static const Category Pistol, Machinegun, Cannon;
    };

    const Category Category::Pistol(Category::PISTOL);
    const Category Category::Machinegun(Category::MACHINEGUN);
    const Category Category::Cannon(Category::CANNON);

    struct Killer{
        Killer (Type t, Category c) : type(t),category(c){}
        Type type;
        Category category;
    };

    enum class C : char { C1 = 1, C2 = 2};
    enum struct D : unsigned  int{ D1 = 1, D2 = 2, Dbig = 0xFFFFFFF0U};

    struct{
        int age;
    }PP;

    void Check(weak_ptr<int> & wp){
        shared_ptr<int> sp = wp.lock();
        if ( sp != nullptr){
            cout << "still::" << *sp <<endl;
        }else{
            cout << "Pointer is invalid" <<endl;
        }
    }

    void test();
}
#endif //UNTITLED_A_H
