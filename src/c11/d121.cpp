//
// Created by redredmaple on 2026/1/21.
//

#include "d121.h"


/**
 * 解决内存泄漏问题
 *
 */

void deleteIntPtr(int *p){
    cout << "delete: " << *p << endl;
    delete p;
}

template<typename T>
shared_ptr<T> make_shared_arr(size_t size){
    return shared_ptr<T>(new T[size], default_delete<T>());
}

template<class T, class... Args>
typename std::enable_if<!is_array<T>::value, unique_ptr<T>>::type
        make_unique(Args&&... args){
    return unique_ptr<T>(new T(std::forward<Args>(args)...));
}

template<class T>
typename std::enable_if<is_array<T>::value && extent<T>::value ==0, unique_ptr<T>>::type
make_unique(size_t size){
    typedef typename remove_extent<T>::type U;
    return unique_ptr<T>(new U[size]());
}

template<class T, class...Args>
typename enable_if<extent<T>::value != 0, void>::type make_unique(Args&&...) = delete;

#define Guard(P) P##P

void d121::test(){
    {
//        auto x = Guard(h);   // 展开成 hh

        /**
         * P161 4.3 weak_ptr弱引用的智能指针
         * shared_ptr<int> sp(new int(1));
         * weak_ptr<int> wp(sp);
         *
         * cout << wp.use_count()  << endl;//1
         *
         * if (wp.expired){
         *      cout << "wp exipred" << endl;
         * }else{
         *      auto spt = wp.lock();
         *      cout << *spt << "\n";
         * }
         *
         * void * p = GetHandle()->create();
         *
         * //do something...
         * GetHandle()->Release(p);
         *
         * //可能存在内存泄漏问题
         *
         * std::shared_ptr<void> sp(p, [this](void*p){GetHandle()->release(p);});
         *
         * std::shared_ptr<void> Guard(void*p){
         *      return std::shared_ptr<void> sp(p, [this](void*p){GetHandle()->release(p)});
         * }
         *
         * void* p = GetHandle()->create();
         * auto sp = Guard(p);
         * //do something...
         *
         * Guard(p); //右值，如果不将右值赋值给一个指针，Guard(p)后，就会释放，导致p提前释放了。
         * 后方就会访问野指针的内容《
         *
         * #define GUARD(P) std::shared_ptr<void> p##p(p,[](void*p){GetHandle()->release(p);});
         * #define GUARD(P) std::unique_ptr<void> p##p(p,[](void*p){GetHandle()->release(p);});
         *
         */
    }

    {
        /**
         * P159
         * 4.2 unique_ptr独占的智能指针
         * unique_ptr<T> myPtr(new T);
         * unique_ptr<T> myOtherPtr = myPtr; //error no copy
         * unique_ptr<T> myotherPtr = std::move(myPtr);
         * std::unique_ptr<int[]> ptr(new int[10]);
         * ptr[9] = 9;
         * std::shared_ptr<int> ptr(new int(1), [](int* p) {delete p;}); //ok
         * std::unique_ptr<int> ptr(new int(1), [](int* p) {delete p;}); //error
         * std::unique_ptr<int, void(*)(int*)> ptr(new int(1), [](int* p) {delete p;}); //ok
         * std::unique_ptr<int, void(*)(int*)> ptr(new int(1), [&](int* p) {delete p;}); //error
         * std::unique_ptr<int, std::function<void(int*)>> ptr(new int(1), [&](int* p) {delete p;}); //ok
         * lambda在没有捕获变量的情况下是可以直接转换为函数指针的,一旦捕获了就无法转换了.
         *
         */
#ifdef MAIEV
        {
            std::unique_ptr<int[]> ptr(new int[10]);
            ptr[9] = 9;

            unique_ptr<int> up(new int(1));
            cout << up.get() << endl;
//            up.release();
            cout << *up << endl;

            std::unique_ptr<int, MyDeleter> p(new int(1));
        }
#endif


        /**
         * P156
         * 4.1 shared_ptr共享的智能指针
         * 注意问题:
         * 1)不要用一个原始指针初始化多个shared_ptr
         * int *ptr = new int;
         * shared_ptr<int> sp1(ptr);
         * shared_ptr<int> sp2(ptr); //ptr会呗释放2次
         *
         * 2)不要在函数实参中创建shared_ptr。
         * function (shared_ptr<int>(new int), g());
         *
         * shared_ptr<int> p(new int());
         * f(p,g());
         *
         * 3) 通过shared_from_this返回this指针。不要将this指针作为shared_ptr返回出来
         * 因为this指针本质是一个裸指针。会导致重复析构
         *
         * 4);避免重复引用
         * 智能指针的一个最大陷阱就是循环引用，循环引用会导致内存泄漏, 不会调用析构函数
         *
         */
#ifdef MAIEV
        {
            std::shared_ptr<A> ap(new A);
            std::shared_ptr<B> bp(new B);
            ap->bptr = bp;
            bp->aptr = ap;
        }

        {
            std::shared_ptr<int> p = make_shared_arr<int>(10);
            shared_ptr<A> sp1(new A);
            shared_ptr<A> sp2 = sp1->GetSelf();
        }

        std::shared_ptr<int> p(new int(1));
        std::shared_ptr<int> p2 = p;
        std::shared_ptr<int> ptr;
        ptr.reset(new int(1), deleteIntPtr);

        std::cout << ptr << std::endl;
        std::cout << ptr.get() << std::endl;

        if (ptr){
            cout << "ptr is not null" << endl;
        }

        std::shared_ptr<int> parr(new int[10]{1,2,3}, [](int*p){
            std::cout << *p << std::endl;
            delete[] p;
        });
#endif
    }
}
