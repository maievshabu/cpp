//
// Created by redredmaple on 2025/12/12.
//

#include "inc.h"

#ifndef STUDY_THREAD_H
#define STUDY_THREAD_H
namespace __thread1{

    int g_i = 0;
    std::mutex g_i_mutex;

    void safe_increment(){
        std::lock_guard<std::mutex> lock(g_i_mutex);
        std::cout << this_thread::get_id() << ": " << g_i << std::endl;
        ++g_i;
    }

    void work1(int & sum){
        for(int i = 0; i< 5000; i++){
            sum += i;
        }
    }

    void work2(int & sum){
        for(int i =5000; i<10000; i++){
            sum += i;
        }
    }

    int fun(){
        int sum = 0;
        for(int i = 0; i < 10000; i++){
            sum += i;
        }

        return sum;
    }

    class Cars{
    public:
        virtual void run() = 0;
    };

    class Truck : public Cars{
    public:
        virtual void run() override final{
            std::cout << "trunk run()" << std::endl;
        }
    };

    class Motor : public Cars{
    public:
        virtual void run() override final{
            std::cout << "Motor run()" << std::endl;
        }
    };

    enum CarsType{
        TruckType,
        MotorType
    };

#define A_B (a) > (b);

    template<CarsType T>
    struct enum_type_mapper;

//template<>
//struct enum_type_mapper<TruckType> {using type =Truck;};
//
//template<>
//struct enum_type_mapper<MotorType> {using type =Motor;};

#define CY(T,U)  \
    template<> \
    struct enum_type_mapper<T> \
    {using type=U;};              \

    CY(TruckType, Truck);
    CY(MotorType, Motor);

    class CarsFactory{
    public:
        template<CarsType T>
        Cars* create(){
            return new typename enum_type_mapper<T>::type();
        }
    };


    void xx(){
        std::thread t1(work1, std::ref(ans));
        std::thread t2(work2, std::ref(ans));

        t1.join();
        t2.join();

        std::cout << "sum1:" << ans << std::endl;
        std::cout << "sum2:" << fun()<< std::endl;

        std::cout << numeric_limits<int>::max() << std::endl;
    }
}


#endif //STUDY_THREAD_H
