//
// Created by redredmaple on 2025/12/10.
//
#include "ptr.h"

//void* operator new(std::size_t sz){
//    std::printf("1) new(size_t), size=%zu\n", sz);
//    if (sz == 0)
//        ++sz;
//    if (void *ptr =std::malloc(sz))
//        return ptr;
//    throw std::bad_alloc{};
//}
//
//void operator delete(void* ptr) noexcept{
//    std::puts("3) delete(void*)");
//    std::free(ptr);
//}

namespace ptr{

    void del(void(*)()){}

    void fun(){}

    void xy(shared_ptr<MyObj>const& sp){
        std::cout << "in xy(shared_ptr<>): " << sp.get() << "use_count:" << sp.use_count() << std::endl;
    }
    void xy(shared_ptr<MyObj> sp){
        std::cout << "in xy(shared_ptr<>): " << sp.get() << "use_count:" << sp.use_count() << std::endl;
    }
    shared_ptr<MyObj> xy(){
        shared_ptr<MyObj> sp = make_shared<MyObj>();
        std::cout << "in xy(): " << sp << std::endl;

        return sp;
    }

    void print(const char* rem, std::shared_ptr<Base> const& sp){
        std::cout << rem << "\n\tget()= " << sp.get()
                  << ",use_count()= " << sp.use_count() << '\n';
    }

    void thr(std::shared_ptr<Base> p){
        std::this_thread::sleep_for(std::chrono::microseconds(1000));
        std::shared_ptr<Base> lp = p;
        {
            static std::mutex io_mutex;
            std::lock_guard<std::mutex> lk(io_mutex);
            print("Local pointer in a thread:", lp);
        }
    }

    void testx1(){
        std::shared_ptr<void()> ee(fun, del);
        (*ee)();

        auto sp = make_shared<Myxx>();
        std::shared_ptr<int> p8(sp, &sp->a);
        std::cout << sp.get() << " " << sp.use_count() << std::endl;
        std::cout << sp.get() << " " << sp.use_count() << std::endl;

        std::shared_ptr<Myxx> sh4(new Myxx, [](Myxx* p){
            std::cout << "~" << std::endl;
            delete p;
        });

        std::shared_ptr<Myxx> sh3(new Myxx, D());
    }

    void test(int){
        std::shared_ptr<Base> p = std::make_shared<Derived>();
        print("Created a shared derived (as a pointer to a Base)", p);
        std::thread t1{thr, p}, t2{thr, p}, t3{thr, p};
        p.reset();

        print("shared ownership between 3 threads and released ownership from main : ", p);
        t1.join();
        t2.join();
        t3.join();

        std::cout << "All threads completed, the last one deleted Derived.\n";
    }

    void test(){
        COUT("Creating shared container");
        std::shared_ptr<Container> cont = std::make_shared<Container>();
        DEMO(cont.use_count());
        DEMO(cont->memberObj.use_count());

        COUT("Creating member");
        cont->createMember();
        DEMO(cont.use_count());
        DEMO(cont->memberObj.use_count());

        COUT("Creating another shared container");
        std:shared_ptr<Container> cont2 = cont;
        DEMO(cont.use_count());
        DEMO(cont->memberObj.use_count());
        DEMO(cont2.use_count());
        DEMO(cont2->memberObj.use_count());

        COUT("GetAsMyObj");
        std::shared_ptr<MyObj> myObj1 = cont->getAsMyObj();
        DEMO(myObj1.use_count());
        DEMO(cont.use_count());
        DEMO(cont->memberObj.use_count());
        DEMO(cont2.use_count());
        DEMO(cont2->memberObj.use_count());

        COUT("Copying alias obj");
        std::shared_ptr<MyObj> myObj2 = myObj1;
        DEMO(myObj1.use_count());
        DEMO(myObj2.use_count());
        DEMO(cont.use_count());
        DEMO(cont->memberObj.use_count());
        DEMO(cont2.use_count());
        DEMO(cont2->memberObj.use_count());

        COUT("Resetting cont2");
        cont2.reset();
        DEMO(myObj1.use_count());
        DEMO(cont.use_count());
        DEMO(cont->memberObj.use_count());

        COUT("Resetting myObj2");
        myObj2.reset();
        DEMO(myObj1.use_count());
        DEMO(cont.use_count());
        DEMO(cont->memberObj.use_count());

        COUT("Resetting cont");
        cont.reset();
        DEMO(myObj1.use_count());
        DEMO(cont.use_count());
    }
}
