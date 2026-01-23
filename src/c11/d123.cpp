//
// Created by redredmaple on 2026/1/23.
//

#include "d123.h"

void testDuration(void);
void testTimePoint(void);
void testClock(void);

void func(){
    cout << "hello word" << endl;
}

//堆内存的内存对齐
inline void* aligned_malloc(size_t size, size_t alignment){

    assert(!(alignment& (alignment -1)));
    size_t offset = sizeof(void*) + (--alignment);

    char* p = static_cast<char*>(malloc(offset+size));
    if (!p) return nullptr;

    void* r = reinterpret_cast<void*>(reinterpret_cast<size_t>(p+offset) & (~alignment));
    static_cast<void**>(r)[-1] = p;

    return r;
}

inline void aligned_free(void*p){
    free(static_cast<void**>(p)[-1]);
}


template<size_t YY = 1>
struct alignas(YY) MyStruct_2{};

#define xx 1

void d123::test() {

    /**
     * 6 is_sorted和is_sorted_until算法
     */
#if 1
    {
        vector<int> v{1,2,5,7,9,4};
        auto pos = is_sorted_until(v.begin(), v.end());
        for(auto it = v.begin(); it != pos; it++){
            cout << *it << " ";
        }
        cout << endl;

        bool is_sort = is_sorted(v.begin(), v.end());
        cout << is_sort << endl;
    }
#endif

    /**
     * 5. minmax_element算法
     */
#if 0
    {
        vector<int> v{1,2,3,4,5,8};
        auto result = minmax_element(v.begin(), v.end());
        std::cout << *result.first <<" :" << *result.second << endl;

        auto p1 = make_pair<int,int>(1,2);
        std::cout << p1.first <<": "<< p1.second << std::endl;
        auto tp = make_tuple(1,2,3,3,4);
        std::cout << get<3>(tp) << std::endl;
    }
#endif
    /**
     * 4 iota 生成有序序列
     */
#if 0
    {
        vector<int> v(4);
//        for(int i = 1; i <= 4; i++){
//            v.push_back(i);
//        }

        std::iota(v.begin(), v.end(), 1);
        for(auto n : v){
            cout << n << ' '; //1 2 3 4
        }
        cout << endl;

        std::array<int, 4> array;
        std::iota(array.begin(), array.end(), 1);
        for(auto n: array){
            cout << n << ' ';  //1 2 3 4
        }
        cout << endl;
    }
#endif

    /**
     * 3 copy_if 算法
     */
#if 0
    {
        vector<int> v{1,3,5,7,9,4};
        std::vector<int>v1(v.size());

        auto it = std::copy_if(v.begin(), v.end(), v1.begin(),[](int i) {return i %2 != 0;});

        v1.resize(std::distance(v1.begin(), it));
        for( int i: v1){
            cout << i << " ";
        }
        cout << endl;
    }
#endif

    /**
     * 7.5 新增的便利算法
     * 1.all_of,any_of和none_of
     *
     */
#if 0
    {
        vector<int> v = {1,3,5,7,9};
        auto isEven = [](int i) {return i %2 != 0;};
        bool isAllOdd = std::all_of(v.begin(), v.end(), isEven);
        cout << "all is odd :" << isAllOdd << endl;

        bool isNoneEven = std::none_of(v.begin(),v.end(), isEven);
        cout << "none is even:" << isNoneEven << endl;

        bool anyof = std::any_of(v.begin(), v.end(), isEven);
        cout << "at least one is even:" << anyof << std::endl;
    }
#endif

    /**
     * 2.find_if_not /find_if是相反的,即查找不符合某个条件的元素
     */
#if 0
    {
        vector<int> v = {1,3,5,7,9,4};
        auto isEven = [](int i) {return i %2 == 0;};
        auto isNotEven = [](int i) {return i %2 != 0;};
        auto firstEven = std::find_if(v.begin(), v.end(), isEven);
        cout << "the first even is: " << *firstEven << std::endl;

        auto firstOdd = std::find_if(v.begin(), v.end(), isNotEven);
        cout<< "the first odd is: " << *firstOdd << std::endl;

        auto odd = std::find_if_not(v.begin(), v.end(), isEven);
        cout << "the first odd is: " << *odd << std::endl;
    }
#endif




    /**
     * P 204 7.4内存对齐
     */
#if 0
    {
        alignas(32) long long axxx = 0;
        struct alignas(xx) MyStruct_1 {};
        static const unsigned ZZ = 1;
        struct alignas(ZZ) MyStruct_3{};
    }

    {
        struct My{
            char a; //1 ->padding 3
            int b; //4 -> padding 0
            short c; //2 -> padding 2  + 4 ?
            long long d; //8 -> padding 0
            char e; //1 -> padding 7
        };

        //1 + 4 + 2+ 8 + 1 + 5 + 8 + 4?

        struct My1{
            long long d; //8
            int b; //4 ->
            short c; //2 ->
            char e; //1 ->
            char a; //1 ->
        };

        class A1{
            long long d;
            int b;
            short c;
            char e; //1 ->
            char a; //1 ->
        };

        class A2{
            char a; //1 ->padding 3
            int b; //4 -> padding 0
            short c; //2 -> padding 2  + 4 ?
            long long d; //8 -> padding 0
            char e; //1 -> padding 7
            void func(){}
        };

        std::cout << sizeof(A1) << std::endl; // 16
        std::cout << sizeof(A2) << std::endl; // 32
        std::cout << alignment_of<A1>::value << std::endl; //8
        std::cout << alignof(A2) << std::endl; //8

//        std::cout << alignof(std::max_align_t) << std::endl;

        std::cout << "char: " << sizeof(char) << std::endl;
        std::cout << "int: " << sizeof(int) << std::endl;
        std::cout << "short: " << sizeof(short) << std::endl;
        std::cout << "long long: " << sizeof(long long) << std::endl;
        std::cout << "My: " << sizeof(My) << std::endl;
        std::cout << "My1: " << sizeof(My1) << std::endl;
    }
#endif


    /**
     * 7.3 final ,override关键字
     * final 关键字来限制某个类不能被继承，或者某个虚函数不能被重写
     * 如果修饰函数，final只能修饰虚函数，并且要放到类或者函数的后面.
     * struct A{
     *      virtual void foo()  final; // ok
     *      void bar() final ;//error
     * }
     *
     * override 关键字确保再派生类种申明的重写函数与基类有相同的签名,同时也明确表示将会重写基类的虚函数,
     * 还可以防止因疏忽把本来系那个要重写的基类的虚函数生命为重载
     * struct A{
     *      virtual void foo(){}
     * }
     * struct D : A{
     *      void fuc() override{}
     * }
     */

    /**
     * 7.2 原始字面量
     * string str = R"xxx()xxx";
     *
     */
#if 0
    {
        string str = R"<<<(int main(void){return 1})<<<";
        std::cout << str << std::endl;
    }
#endif

    /**
     * P197 7.1 委托构造函数和继承构造函数
     *
     * 委托构造: 用其他构造函数 处理新的构造函数
     * 继承构造: 继承基类的构造函数
     *
     */
#if 0
    {
        int i = 1;
        double j = 1.2;
        Derived d(i);
        Derived d1(i, j);
        Derived d2(i, j, "");
    }
#endif

    /**
     * P195 6.3 宽窄字符转换
     * c11 增加了unicode字面量的支持
     * std::wstring str = L"中国认";
     * 将宽字符转换为窄字符需要用到codecvt库种的std::wstring_convert.需要借助以下几个unicode转换器
     * std::codecvt_utf8 封装了utf-8与ucs2及utf-8与ucs4的编码转换
     * std::codecvt_utf16 封装了utf-16与ucs2及utf-8与ucs4的编码转换
     * std::codecvt_utf8_utf16 封装了utf-8与utf-16的编码转换
     */
#if 0
    {
        std::wstring str = L"中国人";
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

        std::string narrowStr = converter.to_bytes(str);
        std::wstring wstr = converter.from_bytes(narrowStr);
        wcout.imbue(std::locale(""));
        wcout << wstr << endl;

        std::wstring str = L"中国认";

        // 使用 UTF-8 和 UTF-16 转换器
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

        std::string narrowStr = converter.to_bytes(str);   // 宽字串 -> UTF-8
        std::wstring wstr = converter.from_bytes(narrowStr); // UTF-8 -> 宽字串

        std::wcout.imbue(std::locale("")); // 设置中文 locale
        std::wcout << wstr << std::endl;
    }
#endif


    /**
     * P193
     * 6.2 数值类型和字符串的相互转换
     *
     * std::string to_string(int value);
     * std::string to_string(long value);
     * std::string to_string(long long value);
     * std::string to_string(unsigned value);
     * std::string to_string(unsigned long value);
     * std::string to_string(unsigned long long value);
     * std::string to_string(float value);
     * std::string to_string(double value);
     * std::string to_string(long double value);
     *
     * std::string to_wstring(int value);
     * std::string to_wstring(long value);
     * std::string to_wstring(long long value);
     * std::string to_wstring(unsigned value);
     * std::string to_wstring(unsigned long value);
     * std::string to_wstring(unsigned long long value);
     * std::string to_wstring(float value);
     * std::string to_wstring(double value);
     * std::string to_wstring(long double value);
     *
     * 字符串转换为整型和浮点型的方法
     * atoi -> int
     * atol -> long
     * atoll -> long long
     * atof -> float
     *
     */
#if 0
    {
        double f = 1.53;
        std::string f_str = std::to_string(f);
        std::cout << f_str << std::endl;

        double f1 = 4.125;
        std::wstring f_str1 = std::to_wstring(f1);
        std::wcout << f_str1 << std::endl;

        const char* str1 = "10";
        const char* str2 = "3.14159";
        const char* str3 = "31337 with words";
        const char* str4 = "words and 2";

        int num1 = std::atoi(str1);
        int num2 = std::atoi(str2);
        int num3 = std::atoi(str3);
        int num4 = std::atoi(str4);

        std::cout << "std::atoi(\""<<str1 << "\") is " << num1 << '\n';
        std::cout << "std::atoi(\""<<str2 << "\") is " << num2 << '\n';
        std::cout << "std::atoi(\""<<str3 << "\") is " << num3 << '\n';
        std::cout << "std::atoi(\""<<str4 << "\") is " << num4 << '\n';
    }

    std::cout << "chrono" << std::endl;
    {
        Timer t;
        func();
        cout << t.elapsed() << endl;
        cout << t.elapsed_micro() << endl;
        cout << t.elapsed_nano() << endl;
        cout << t.elapsed_seconds() << endl;
        cout << t.elapsed_minutes() << endl;
        cout << t.elapsed_hours() << endl;
    }
#endif

//    testDuration();
//    testTimePoint();
//    testClock();
    /**
     * P186 6.1 处理日期和时间的chrono库
     * chrono库主要包含3个类型：
     * 1) 时间间隔duration
     * 2) 时针clocks
     * 3) 时间点time point
     *
     * 记录时长的duration
     *
     * template<class Rep, class Period = std::ratio<1,1>> class duration;
     * template<std::intmax_t Num, std::intmax_t Demon = 1> class Ratio;
     * ratio 它表示一个时针周期的秒数, 代表Num/Demo(分子除分母)
     * ratio<2>代表一个是真周期是两秒
     * ratio<60>代表一分钟
     * ratio<1,1000>代表1/1000秒，即是1毫秒
     * ratio<1,1000 000>代表一微秒
     * ratio<1,1000 000 000>代表一纳秒
     *
     * typedef duration <Rep, ratio<3600,1>> hours;
     * typedef duration <Rep, ratio<60,1>> minutes;
     * typedef duration <Rep, ratio<1,1>> seconds;
     * typedef duration <Rep, ratio<1,1000>> milliseconds;
     * typedef duration <Rep, ratio<1,1000000>> microseconds;
     * typedef duration <Rep, ratio<1,1000000000>> nanoseconds;
     *
     * duration加减运算有一定的规则.当两个duration时针周期不相同的时候，会先统一一种时钟，然后再做加减运算
     * 规则如下：
     * 对于ratio<x1,y1> count1, ratio<x2,y2>count2; 如果x1,x2的最大公约数为x,y1,y2最小公倍数y,统一后的ratio为ratio<x,y>
     *
     * 表示时间点的time_point
     * time_point表示一个时间点，用来获取从它的clock的纪元开始所经过的duration和当前时间.可以做一些时间的比较和算术运算
     * 可以和ctime库结合起来显示时间，time_point必须用clock来计时.time_point有一个函数time_from_epoch()用来获得
     * 1970/1/1到time_point时间经过的duration.
     *
     * 获取系统时钟的clocks
     * clocks表示当前系统的时钟，内部有time_point,duration,Rep,Period等信息。主要用来获取当前时间。以及实现time_t,time_point的相互转换
     * clocks包含3种时钟
     * 1) system_clock 代表真实世界的挂钟时间.具体时间依赖系统.system_clock保证体哦那个的时间值时一个可读时间
     * 2) steady_clock 不能被"调整"的时钟, 并不一定代码真实世界的挂钟时间。保证先后调用now()得到的时间值时不会递减的
     * 3) high_resolution_clock 高经度时钟,实际上是system_clock或者steady_clock的别名。
     * 可通过now()来获取当前时间点
     *
     * 计时器timer
     */
}

void testClock(){
    using namespace chrono;
    system_clock::time_point t1 = system_clock::now();
    std::cout << "Hello world!\n";
    system_clock::time_point t2 = system_clock::now();
    std::cout << (t2 - t1).count() << " tick count" << std::endl;
    std::cout << duration_cast<chrono::microseconds>(t2 -t1).count()<< std::endl;

    std::time_t now_c = system_clock::to_time_t(t1);
    system_clock::time_point tx = system_clock::from_time_t(now_c);

    //steady_clock可以获取稳定的可到的时间间隔，后一次调用now()和前一次调用now()不会因为修改系统时间而改变，从而保证稳定的时间间隔
    //steady_clock用法和system一样

    steady_clock::time_point t3 = steady_clock::now();
    std::cout << "Hello world2!\n";
    steady_clock::time_point t4 = steady_clock::now();
    std::cout << (t4 - t3).count() << " tick count" << std::endl;
    std::cout << duration_cast<chrono::microseconds> (t4 - t3).count() << " tick count" << std::endl;
}

void testTimePoint(){
    using namespace chrono;
    typedef duration<int, std::ratio<60*60*24>> days_type;
    time_point<system_clock, days_type> today = time_point_cast<days_type>(system_clock::now());
    std::cout << today.time_since_epoch().count() << " days since epoch" << std::endl;


    system_clock::time_point now = system_clock::now();
    std::time_t last = system_clock::to_time_t(now - hours(24));
    std::time_t next = system_clock::to_time_t(now + hours(24));

    //#GCC 没有支出std::put_time();
    std::cout << "One  day ago, the time was: " << std::put_time(std::localtime(&last), "%F %T") << std::endl;
    std::cout << "Next day ago, the time was: " << std::put_time(std::localtime(&next), "%F %T") << std::endl;
}

void testDuration(){
    std::this_thread::sleep_for(std::chrono::microseconds(1000));
    std::chrono::milliseconds ms{3};

    std::chrono::microseconds us = 2*ms;

    std::chrono::duration<double, std::ratio<1,30>> hz30{3.5};

    std::cout << "3 ms duration has " << ms.count() << " ticks\n";
    std::cout << " 6000 us duration has " << us.count() << " ticks\n";

    std::chrono::minutes t1{10}; //10分钟
    std::chrono::seconds t2{60}; //60秒
    std::chrono::seconds t3 = t1 - t2; //540 9分钟
    std::cout << t3.count() << " seconds" << std::endl;
    std::cout << std::chrono::duration_cast<std::chrono::minutes>(t3).count() << " minutes" << endl;

    auto t4 = std::chrono::seconds(125);
    std::cout << std::chrono::duration_cast<std::chrono::minutes>(t4).count() << " minutes" << endl;


    std::chrono::duration<double, std::ratio<9,7>> d1(3);
    std::chrono::duration<double, std::ratio<6,5>> d2(1);

    /**
     * 统一后的duration.std::chrono::duration<double,std::ratio<3,35>>;
     * 然后再将原来的duration转换为统一的duration.最后的时钟周期数为:(9/7)/((3/35)*3) - ((6/5)/(3,35)*1) = 31
     */
    auto d3 = d1 - d2;
    cout << typeid(d3).name() << endl;
    cout << d3.count()<< endl;

    /**
     * 还可以通过duration_cast<>()将当前的时钟周期转化为其他的时钟周期，比如可以把秒的时钟周期转换为分钟的时钟周期。
     * 然后再通过count来获取转换后的分钟时钟周期
     *
     */
}

