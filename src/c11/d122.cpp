//
// Created by redredmaple on 2026/1/22.
//

#include "d122.h"
std::vector<std::thread>g_list;
std::vector<std::shared_ptr<std::thread>>g_list2;

extern std::once_flag flag;

#if 0
std::mutex mutex;
void func(int i){
    std::this_thread::sleep_for(std::chrono::seconds(3));
    cout << i << endl;
}

void func(){
    cout << "func()" << endl;
}

void createThead(){

    std::thread t(func, 1);
    g_list.emplace_back(std::move(t)); //

    auto sp = std::make_shared<std::thread>(func, 1);
    g_list2.push_back(sp);

    g_list.push_back(t); // thread对象不能复制
    std::shared_ptr<std::thread> sp = std::make_shared<std::thread> (std::move(t));
    g_list2.push_back(std::make_shared<std::thread>(t, 1));
}
#endif

void d122::do_once(){
    std::call_once(flag, [](){std::cout << "Called once" << std::endl;});
}

std::timed_mutex tmutex;
void work(){
    std::chrono::microseconds  timeout(100);
    while(true){
        if (tmutex.try_lock_for(timeout)){
            std::cout << std::this_thread::get_id() << ": do work with the mutex" << std::endl;
            std::chrono::microseconds sleepDurations(250);
            std::this_thread::sleep_for(sleepDurations);
            tmutex.unlock();
            std::this_thread::sleep_for(sleepDurations);
        }else{
            std::cout << std::this_thread::get_id() << ": do work without the mutex" << std::endl;
            std::chrono::microseconds sleepDurations(100);
            std::this_thread::sleep_for(sleepDurations);
        }
    }
}

template<typename Queue, typename T>
void QueuePut(Queue& queue,const T & x){
    std::this_thread::sleep_for(std::chrono::microseconds(1));
    queue.Put(x);
}

template<typename Queue, typename T>
void QueueTake(Queue& queue,T & x) {
    std::this_thread::sleep_for(std::chrono::microseconds(2));
    queue.Take(x);
}

template<typename T>
void showT(const T& t){
    cout << t << endl;
}

int d122::func(int x) {
    return x + 2;
}

void d122::test() {
    /**
     * P 184 5.7 线程异步操作函数async
     *
     * std::launch::async: 调用async时就创建线程
     * std::launch::defered: 延迟架子方式创建线程,调用async时不创建线程，直到调用了future的get或者wait时才创建线程
     */
    {
        std::future<int> f1 = std::async(std::launch::async, [](){
            return 8;
        });

        cout << "f1: " << f1.get() << endl;

        std::future<void> f2 = std::async(std::launch::deferred, [](){
            cout << "f2: " << 8 << endl;
        });
        f2.wait();

        std::future<int> f3 = std::async(std::launch::async, [](){
            std::this_thread::sleep_for(std::chrono::seconds(3));
            return 8;
        });

        cout << "Waiting...\n";
        std::future_status status;
        do{
            status = f3.wait_for(std::chrono::seconds(1));
            if (status == std::future_status::deferred){
                cout << "defered\n";
            }else if (status == std::future_status::timeout){
                cout << "timeout\n";
            }else if (status == std::future_status::ready){
                cout << "ready\n";
            }
        } while (status != std::future_status::ready);

        std::cout << "The result is : " << f3.get() << std::endl;
    }


    /**
     * P181 5.6 异步操作
     * std::future, std::promise, std::package_task.
     *
     * std::function 作为异步结果的传输通道，可以方便的获取线程函数的返回值.
     * std::promise 用于包装一个值，将数据和futer绑定起来。方便线程赋值
     * std::package_task用于包装一个可调用对象,将函数和futer半丁起来。以便异步调用
     *
     * future_status有如下3种状态:
     * Defered 异步还没开始
     * Ready 异步操作以及完成
     * Timeout 异步操作超时
     *
     * std::future_status status;
     * do{
     *      status = future.wait_for(std::chrono::seconds(1);
     *      if (status == std::future_status::defered){
     *          std:cout << "defered\n";
     *      }else if  (status == std::future_status::timeout){
     *          std:cout << "timeout\n";
     *      }else if  (status == std::future_status::ready){
     *          std:cout << "ready\n";
     *      }
     * }while(status != std::future_status::ready)
     * 获取future的结果有3种方式get,wait,wait_for
     * get: 等待异步操作结果并返回结果。超时等待结果
     * wait: 只是等待异步操作完成，没有返回值
     * wait_for:是超时等待结果
     *
     * std::promise<int> pr;
     * std::thread t([](std::promise<int>& p){
     *      p.set_value_at_thread_exit(9);
     * }, std::ref(pr);
     *
     * std::future<int> f = pr.get_future();
     * auto r = f.get();
     *
     * std:packaged_task 包装了一个可调用对象的包装类(function ,lambda , bind, another function object),
     * 将函数和future绑定起来。以便异步调用
     * promise保存的是一个值。packaged_task保存的是一个函数
     *
     * std::packaged_task<int()> task([](){return 7;});
     * std::thread t1(std::ref(task);
     * std::future<int> f1 = task.get_future();
     * auto r1 = f1.get();
     */
#if 0
    {

        std::promise<int> pr;
        std::thread t([](std::promise<int>& p){
            p.set_value_at_thread_exit(9);
        }, std::ref(pr));

        t.join();

        std::future<int> f = pr.get_future();
        auto r = f.get();
        cout << "The result is : " << r << endl;

        std::packaged_task<int(int)> task(func);
        std::future<int> fut = task.get_future();

        std::thread(std::move(task), 2).detach();

        int value = fut.get();
        std::cout << "The result is " << value << ".\n";

        vector<std::shared_future<int>> v;
        shared_future<int> vf = std::async(std::launch::async, [](int a, int b) { return a + b; }, 2, 3);
        v.push_back(vf);
        std::cout << "The shared_future result is " << v[0].get() << endl;
    }
#endif
    /**
     * 5.5 call_once/once_flag
     * 为保证再多线程环境中某个函数仅调用一次
     */
#if 0
    {
        std::thread t1(d122::do_once);
        std::thread t2(d122::do_once);
        std::thread t3(d122::do_once);

        t1.join();
        t2.join();
        t3.join();
    }
#endif

    /**
     * P179 5.4 原子变量
     *
     * std::atomic<T>
     *
     */
#if 0
    {

        AtomicCounter ct;
        std::thread th1([&]{ct.crement();});
        std::thread th2([&]{ct.crement();});
        std::thread th3([&]{ct.deCrement();});
//        std::thread th4([&]{ct.get();});
//        std::thread th1(std::bind(&AtomicCounter::crement, &ct)); //1
//        std::thread th2(std::bind(&AtomicCounter::crement, &ct)); //2
//        std::thread th3(std::bind(&AtomicCounter::deCrement, &ct)); //1
//        std::thread th4(std::bind(&AtomicCounter::get, &ct)); //1

        if (th1.joinable()){
            th1.join();
        }
        if (th2.joinable()){
            th2.join();
        }
        if (th3.joinable()){
            th3.join();
        }
//        if (th4.joinable()){
//            th4.join();
//        }
//
//
//        Counter ct;
//        std::thread th1(std::bind(&Counter::crement, &ct));
//        std::thread th2(std::bind(&Counter::crement, &ct));
//        std::thread th3(std::bind(&Counter::decrement, &ct));
//
//        th1.join();
//        th2.join();
//        th3.join();

        cout << ct.get() << std::endl;
    }
#endif
    /**
     * 5.3条件变量
     * 条件变量是c11提供的另外一种用于等待的同步机制.它能阻塞一个或者多个线程，知道收到另外一个线程发出的通知或者超时,才能唤醒当前阻塞的线程
     * condition_variable 配合 std::unique_lock<std::mutex>进行wait的操作
     * condition_variable_any和任意的lock ,unlock语义的mutex搭配使用,比较灵活，效率差一些
     *
     * 条件变量的使用过程如下:
     * 1) 拥有条件变量的线程获取互斥量
     * 2) 循环检查某个条件，如果条件不满足，则阻塞直到条件满足；如果 条件满足，则向下执行
     * 3) 某个线程满足条件执行之后就调用notify_one,notify_all唤醒一个或者所有等待的线程
     *
     */
#if 0
    {
        SimpleSyncQueue<int> s1;
        std::thread t1(QueuePut<decltype(s1),int>, std::ref(s1), 1);
        std::thread t2(QueuePut<decltype(s1),int>, std::ref(s1), 2);
        std::thread t3(QueuePut<decltype(s1),int>, std::ref(s1), 3);
        std::thread t4(QueuePut<decltype(s1),int>, std::ref(s1), 4);

        int x = 0;
        std::thread t5(QueueTake<decltype(s1),int>, std::ref(s1), std::ref(x));
        std::thread t6(QueueTake<decltype(s1),int>, std::ref(s1), std::ref(x));
        std::thread t7(QueueTake<decltype(s1),int>, std::ref(s1), std::ref(x));
        std::thread t8(QueueTake<decltype(s1),int>, std::ref(s1), std::ref(x));

        t8.join();
        t7.join();
        t6.join();
        t5.join();
        t4.join();
        t3.join();
        t2.join();
        t1.join();
    }
    {
        showT(1);
        showT<int>(1);
        std::function<void(const int)> f = std::bind(showT<int>, 1);
    }
    {
        ccomplex c1;
        std::thread t1(std::bind(&ccomplex::add, &c1, std::placeholders::_1), 1);
        std::thread t2(std::bind(&ccomplex::mul, &c1, std::placeholders::_1), 1);
        std::thread t3(std::bind(&ccomplex::getI,&c1));

        t1.join();
        t2.join();
        t3.join();
    }
    {
        A a;

        std::thread th1(std::bind(&A::func,&a, std::placeholders::_1), 1);
        th1.join();

        int x;

        SyncQueue<int> s1(2);
        std::thread t1(QueuePut<SyncQueue<int>,int>, std::ref(s1), 1);
        std::thread t2(QueuePut<SyncQueue<int>,int>, std::ref(s1), 2);
        std::thread t3(QueuePut<SyncQueue<int>,int>, std::ref(s1), 3);
        std::thread t4(QueuePut<SyncQueue<int>,int>, std::ref(s1), 4);
        std::thread t5(QueuePut<SyncQueue<int>,int>, std::ref(s1), 5);
        std::thread t6(QueuePut<SyncQueue<int>,int>, std::ref(s1), 6);
        std::thread t7(QueuePut<SyncQueue<int>,int>, std::ref(s1), 7);
        std::thread t88(QueuePut<decltype(s1),int>, std::ref(s1), 8);

        std::thread t8(QueueTake<SyncQueue<int>,int>, std::ref(s1), std::ref(x));
        std::thread t9(QueueTake<SyncQueue<int>,int>, std::ref(s1), std::ref(x));
        std::thread t10(QueueTake<SyncQueue<int>,int>, std::ref(s1), std::ref(x));
        std::thread t11(QueueTake<SyncQueue<int>,int>, std::ref(s1), std::ref(x));
        std::thread t12(QueueTake<SyncQueue<int>,int>, std::ref(s1), std::ref(x));
        std::thread t13(QueueTake<SyncQueue<int>,int>, std::ref(s1), std::ref(x));
        std::thread t14(QueueTake<SyncQueue<int>,int>, std::ref(s1), std::ref(x));
        std::thread t15(QueueTake<SyncQueue<int>,int>, std::ref(s1), std::ref(x));

        t1.join();
        t2.join();
        t3.join();
        t4.join();
        t5.join();
        t6.join();
        t7.join();
        t8.join();
        t9.join();
        t10.join();
        t11.join();
        t12.join();
        t13.join();
        t14.join();
        t15.join();

        s1.Take(x);
        cout << x << endl;
        s1.Take(x);
        cout << x << endl;
    }
#endif

    /**
     *
     * 5.2 互斥量
     * std::mutex //独占的互斥量,不能递归调用
     * std::timed_mutex; //带超时的独占互斥量,不能递归使用
     * std::recursive_mutex; //递归互斥量,不带超时功能
     * std::recursive_timed_mutex; //带超市的递归互斥量
     *
     * std::mutex
     * 可使用lock_guard简化lock/unlock的写法。同时也更安全
     * 尽量用lock_guard
     *
     * std::mutex g_lock;
     * void func(){
     *      std::lock_guard<std::mutex> lg(g_lock); //    g_lock.lock();
     *      std::cout << "enter thread: " << std::this_thread::get_id() << std::endl;
     *      std::this_thread::sleep_for(std::chrono::seconds(1));
     *      std::cout << "leave thread: " << std::this_thread::get_id() <<std::endl;
     *      //g_lock.unlock();
     * }
     *
     *
     * std::recursive_mutex
     * 递归锁允许同一线程多次获得改互斥锁,可以用来解决统一线程需要多次获取互斥量时死锁的问题。
     * 需要注意的是尽量不要使用递归锁好
     * 1)需要用到递归锁定的多线程互斥处理往往本身是可以简化的。允许递归互斥很容易放纵复杂逻辑的产生，
     *  从而导致一些多线程同步引起的晦涩问题
     * 2) 递归锁比非递归锁，效率会低一些
     * 3)递归锁虽然允许同时同一个线程多次获得同一个互斥量,可重复获得的最大次数并未具体说明，一旦超过次数。
     * 再对lock进行调用就会爆出std::system错误
     *
     * 带超时的互斥量std::timed_mutex和std::recursive_timed_mutex;
     *
     * std::timed_mutex是超时的独占锁,std::recursive_timed_mutex是超时的递归锁.
     * 主要用在获取锁时增加超时的等待功能，因为有时不知道获取锁需要多久，为了不至于一直再等待获取互斥量。
     * 就设置一个等待超时，再超时后还可以做其他的事情
     *
     * std::timed_mutex比std::mutex多两个获取锁的接口:try_lock_for和try_lock_until.用来获取设置互斥量的
     * 超时时间。使用时用一个while循环不断的获取互斥量
     */
#if 0
    {
        std::thread t1(work);
        std::thread t2(work);

        t1.join();
        t2.join();
    }
    {
        Complex complex;
        complex.both(32,32);
        complex.getI();

        std::thread t1(func);
        std::thread t2(func);
        std::thread t3(func);

        t1.join();
        t2.join();
        t3.join();
    }
#endif

    /**
     * P168
     * 5.1 线程
     * <thread>
     * std::thread th(func, Args...) //线程可以接收任意个数的参数
     * th.join() //阻塞线程,直到执行结束，如果有返回值将忽略
     * th.detach() //不阻塞线程执行 线程和线程对象分离，线程作为后台线程去执行,当前线程也不阻塞
     * 之后无法再和线程发生联系了，比如detach之后就不能再通过join来等待线程执行完，线程合适只希望我们无法控制
     *
     * 需要保证线程函数的生命周期在线程变量std::thread的生命周期之内
     * 线程不能复制，但可以移动
     * void func(){
     *      // do something
     * }
     *
     * std::thread t1(func);
     * std::thread t2(t1) //error
     * std::thread t2(std::move(t1));
     * t1.join();
     * t2.join()
     * 线程被移动之后，线程对象t将不再代表任何线程了。另外还可以通过std::bind和lambda表达式来创建线程
     *
     * void func(int a, double b){}
     * std::thread t1(std::bind(func, 1, 2));
     * std::thread t2([](int a,double b){}, 1,2);
     *
     * 需要注意的事线程对象的生命周期
     * void func(){}
     * int main(){
     *      std::thread t(func);
     *      return 0;
     * }
     *
     * //上面代码可能会抛异常，因为线程对象可能先于线程函数结束了，应保证线程对象的生命周期在
     * 线程函数执行完时任然存在。可以通过jon方式来阻塞等待线程函数执行完，或者通过detach方式
     * 让线程在后台执行，还可以将线程对象保存在一个容器中，以保证线程对象的生命周期
     *
     * std::vector<std::thread> g_list;
     * std::vector<std::shared_ptr<std::thread>> g_list2;
     *
     * void createThread(){
     *      std::thread th(func);
     *      g_list.emplace_back(th); //no push_back 因为效率
     *      g_list2.push_back(std::make_shared<std::thread>(func));
     * }
     *
     * 线程可以获取当前线程的id，还可以获得cpu核心数量
     * std::thread th(func);
     * th.get_id(); // 获得线程id
     * th.hardware_concurrency(); //获得cpu核数
     *
     */

#ifdef MAIEV
    {
        g_list.reserve(16);
        g_list2.reserve(16);

        createThead();

        for (auto & th: g_list){
            cout <<  th.get_id() << ": ";
            if (th.joinable()){
                th.join();
            }
        }

        cout << "------" << endl;

        for(auto& th2: g_list2){
            cout <<  th2->get_id() << ": ";
            if (th2->joinable()){
                th2->join();
            }
        }

        cout << endl;
        cout << "hard::" << std::thread::hardware_concurrency() << endl; //cpu核数

        cout << "thread study!!!" << endl;
        thread t1(func, 1);
//    thread th1(std::move(th));
        thread t2([](int a, int b){},1, 2);
        t1.join();
        t2.join();
//    th.detach();

        cout << "hello world!!" << endl;
    };
#endif
}

