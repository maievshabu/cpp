//
// Created by redredmaple on 2025/12/11.
//
#include "inc.h"

#ifndef STUDY_SMART_H
#define STUDY_SMART_H
#include "inc.h"

namespace __smart{

    void pr(const vector<shared_ptr<string>>& whoMadeCoffee){
        for(auto pr : whoMadeCoffee){
            std::cout << *pr << " ";
        }

        std::cout << std::endl;
    }

    template<typename T, bool isArray = false>
    struct D{
        void operator()(T *p){
            std::cout << "D:" << p << std::endl;
            if (isArray){
                delete []p;
            }else{
                delete p;
            }
        }
    };

    template<typename T>
    struct D1{
        void operator()(T *p){
            std::cout << "D:" << p << std::endl;
            delete p;
        }
    };

    template<typename T>
    struct D1<T[]>{
        void operator()(T *p){
            std::cout << "D:" << p << std::endl;
            delete[] p;
        }
    };


    class Person : public enable_shared_from_this<Person>{
    public:
        string name;
        shared_ptr<Person> mother;
        shared_ptr<Person> father;
//        vector<shared_ptr<Person>> kids;
        vector<weak_ptr<Person>> kids;

        Person(const string& s, shared_ptr<Person> m = nullptr, shared_ptr<Person> f=nullptr)
        :name(s),mother(m),father(f){}
        ~Person(){
            std::cout << "delete: " << name << std::endl;
        }

        void setParentsAndTheirKids(shared_ptr<Person>m = nullptr,
                                    shared_ptr<Person> f = nullptr){
            mother = m;
            father = f;
            if (m != nullptr){
                m->kids.push_back(shared_ptr<Person>(shared_from_this()));
//                m->kids.push_back(shared_ptr<Person>(this));
            }

            if (f != nullptr){
                f->kids.push_back(shared_ptr<Person>(shared_from_this()));
//                m->kids.push_back(shared_ptr<Person>(this));
            }
        }
    };

//    class Person{
//    public:
//        string name;
//        weak_ptr<Person> mother;
//        weak_ptr<Person> father;
//        vector<shared_ptr<Person>> kids;
//
//        Person(const string& s, shared_ptr<Person> m = nullptr, shared_ptr<Person> f=nullptr)
//                :name(s),mother(m),father(f){}
//        ~Person(){
//            std::cout << "delete: " << name << std::endl;
//        }
//    };
//
    shared_ptr<Person> initFamily(const string& name){
        shared_ptr<Person> mom(new Person(name + "'s mom"));
        shared_ptr<Person> dad(new Person(name + "'s dad"));
        shared_ptr<Person> kid(new Person(name,mom, dad));
        mom->kids.push_back(kid);
        dad->kids.push_back(kid);

        return kid;
    }

    struct X{
        int a;
    };

    class classA{};

    template<typename T>
    using uniquePtr = std::unique_ptr<T, void(*)(T*)>;

    void test_unique(){
        {
            uniquePtr<int> up(new int[10]{1,0,1,0,1,0}, [](int *p){
                delete[] p;
            });

            uniquePtr<int> up2(new int(10), [](int *p){
                delete p;
            });

            std::cout << up.get()[2] << std::endl;
            std::cout << *(up2.get()) << std::endl;
        }

        {
            std::unique_ptr<int> up1(new int(0));
            std::unique_ptr<int> up2;
//            up2 = up; //error?
            up2.reset();
            up2 = std::move(up1);
            std::cout << *up2 << std::endl;
        }

        {
            std::unique_ptr<std::string> up(new std::string("nico"));
            std::unique_ptr<std::string, std::function<void(string*)>> upx(new std::string("nico"), [](string* p){
                std::cout << "~" << std::endl;
                delete p;
            });

            auto l = [](int * p){
                std::cout << "~" << std::endl;
                delete[] p;
            };


            std::unique_ptr<int, decltype(l)> up3(new int[10]{1,100,1,1}, l);
            std::cout << up3.get()[1] << std::endl;

            (*up)[0] = 'N';

            up->append("lai");
            std::cout << *up << std::endl;

            std::string* sp= up.release();
            std::cout << sp << std::endl;
            std::cout << *sp << std::endl;

            if (up != nullptr){
                std::cout << *up << std::endl;
            }else{
                std::cerr << "hello world!" << std::endl;
            }
        }
    }

    void test_person(){
        {
            shared_ptr<X> px(new X);
            shared_ptr<int> pi(px, &px->a); //alias constructor???
        }

        {
            shared_ptr<X> sp1(new X);
            shared_ptr<X> sp2(sp1, new X);
            std::cout << sp1.use_count() << std::endl; // 2
            std::cout << sp2.use_count() << std::endl; //2

            sp1.reset();
            shared_ptr<X> sp3(sp1, new X);
            std::cout << sp1.use_count() << std::endl; // 0
            std::cout << sp3.use_count() << std::endl; //0 ?

        }
        {
            shared_ptr<int> sp(new int(10));
//            static_pointer_cast<int*>(sp);
            weak_ptr<int> wp(sp);

            auto xp = atomic_load(&sp);
            std::cout << *xp << std::endl; //10???
        }

        {
            shared_ptr<Person> p = initFamily("nico");
            std::cout << "nico's family exists: " << std::endl;
            std::cout << "-nico is shared: " << p.use_count() << std::endl;

//        if (auto mom = p->mother.lock()) {
//            std::cout << "Mom: " << mom->name << "\n";
//            if (!mom->kids.empty()) {
//                std::cout << "Mom's first kid: " << mom->kids[0]->name << "\n";
//            }
//        }
//
//        if (auto dad = p->father.lock()) {
//            std::cout << "Dad: " << dad->name << "\n";
//        }

//        std::cout << "-name of 1st kids of nico's mom:  " << p->mother->kids[0]->name << std::endl; //vector<shared_ptr<Person>> kids;
//        std::cout << "-name of 1st kids of nico's mom:  " << p->mother.lock()->kids[0]->name << std::endl; //shared_ptr<Person> mother;
            std::cout << "-name of 1st kids of nico's mom:  " << p->mother->kids[0].lock()->name << std::endl; //vector<weak_ptr<Person>> kids;
            p = initFamily("jim");
            std::cout << "jim family exists: " << std::endl;
        }

        try{
            shared_ptr<string> sp(new string("hi"));
            weak_ptr<string> wp(sp);
            sp.reset();
            std::cout << wp.use_count() << std::endl;
            std::cout << boolalpha << wp.expired() << std::endl;
            shared_ptr<string> p(wp);
        }catch(const std::exception& e) {
            std::cerr << "exception:" << e.what() << std::endl;
        }
        {
            int *p = new int;
            shared_ptr<int> sp1(p);
            shared_ptr<int> sp2(sp1);
            weak_ptr<int> wp(sp2);

            std::cout << boolalpha << sp1.owner_before(sp2) << std::endl;
            std::cout << boolalpha << sp1.owner_before(wp) << std::endl;
            std::cout << boolalpha << sp2.owner_before(wp) << std::endl;
        }
    }

    void test_xx(){
        //        shared_ptr<string> pNico(new string("nico")); //OK
//        shared_ptr<string> pNico{new string("nico")}; //OK
//        shared_ptr<string> pNico = new string("nico"); //ERROR
        shared_ptr<string> pNico = make_shared<string>("nico"); //ok
        shared_ptr<string> pJutta(new string("jutta"));

        (*pNico)[0] = 'N';
        pJutta->replace(0, 1, "J");

        vector<shared_ptr<string>> whoMadeCoffee;
        whoMadeCoffee.push_back(pJutta);
        whoMadeCoffee.push_back(pJutta);
        whoMadeCoffee.push_back(pNico);
        whoMadeCoffee.push_back(pJutta);
        whoMadeCoffee.push_back(pNico);

        pr(whoMadeCoffee);

        *pNico = "Nicolai";

        cout << "use_count:" << whoMadeCoffee[0].use_count() << std::endl;

        shared_ptr<string> pNico4;
//        pNico4 = new string("nico"); //error
        pNico.reset(new string("nico"), [](string* p){
            std::cout << "delete:" << p << std::endl;
            delete p;
        }); //ok

        pNico = nullptr;

        whoMadeCoffee.resize(2);
        pr(whoMadeCoffee);

        cout << "use_count:" << whoMadeCoffee[0].use_count() << std::endl;
        cout << "use_count:" << pJutta.use_count() << std::endl;

        std::shared_ptr<int> p(new int[10], D<int, true>());

        std::unique_ptr<int[]> up(new int[10]); //ok
//        std::shared_ptr<int[]> sp(new int[10]); //error

        std::shared_ptr<int[]> sp2{new int[10]{1,2,3,4}, D<int,true>()};

        (&*sp2)[5] = 5;
        (&*sp2)[6] = 6;
        (&*sp2)[7] = 7;

        for(int i = 0 ; i < 10;i ++){
//            std::cout << " " << sp2[i] << std::endl;
            std::cout << sp2.get()[i] << std::endl;
        }

        std::shared_ptr<int[]> sp(new int[10],[](int* p){
            delete[] p;
        }); //error
    }

    class Home{
    public:
        Home() = default;
        Home(const string&  name){
            std::cout << "Home(string * name)" << std::endl;
           address = new string(name);
        }
        //拷贝构造
        Home(const Home& oth){
            std::cout << "Home(const Home& oth)" << std::endl;
            if (oth.address != nullptr){
                address = new string(*oth.address);
            }
        }
        Home(Home&& oth) noexcept{
            std::cout << "Home(Home&& oth) noexcept" << std::endl;
            address = oth.address;
            oth.address = nullptr;
        }
        //拷贝赋值
        Home& operator=(const Home& oth){
            std::cout << "Home& operator=(const Home& oth)" << std::endl;
            if (this != &oth){
                delete address;
                if (oth.address != nullptr){
                    address = new string(*oth.address);
                }else{
                    address = nullptr;
                }
            }
            return *this;
        }
        //移动赋值
        Home& operator=(Home&& oth) noexcept{
            std::cout << "Home& operator=(Home&& oth) noexcept" << std::endl;

            if (this != &oth){
                std::swap(address, oth.address);
//                delete address;
//                address = oth.address;
//                oth.address = nullptr;
            }
            return *this;
        }

        const string& getAddress() const{
            static const std::string empty{};
            return address ? *address : empty;
        }
        ~Home(){
            std::cout << "~Home()" << std::endl;
            delete address;
        }
    private:
        string * address{};
    };

    class Home2{
    public:
        Home2() = default;
        Home2(string address){
            std::cout << "Home2(string address)" << std::endl;
            hAddress = make_shared<string>(address);
        }
        //拷贝构造
        Home2(const Home2& oth){
            std::cout << "Home2(const Home2& oth)" << std::endl;
            hAddress = oth.hAddress;
        }
        //拷贝移动
        Home2(Home2&& oth) noexcept{
            std::cout << "Home2(Home2&& oth)" << std::endl;
            hAddress = move(oth.hAddress);
        }
        Home2& operator=(const Home2& oth){
            std::cout << "Home2& operator=(const Home2& oth)" << std::endl;
            hAddress = oth.hAddress;
        }

        Home2& operator=(Home2&& oth){
            std::cout << "Home2& operator=(const Home2& oth)" << std::endl;
            hAddress = move(oth.hAddress);
        }

        ~Home2(){
            std::cout << "~Home2()" << std::endl;
        }
        const string getAddress()const{
            return hAddress != nullptr ? *hAddress : " ";
        }
    private:
        shared_ptr<string> hAddress;
    };

    class Home3{
    public:
        Home3() = default;
        Home3(string address): hAddress(new string(address)){
            std::cout << "Home3(string address)" << std::endl;
        }
        //拷贝构造
        Home3(const Home3& oth):hAddress(new string(*oth.hAddress)){
            std::cout << "Home3(const Home2& oth)" << std::endl;
        }

        Home3(Home3&& oth) noexcept{
            std::cout << "Home3(Home3&& oth)" << std::endl;
            hAddress = move(oth.hAddress);
        }

        Home3& operator=(const Home3& oth){
            if (this != &oth){
                hAddress = std::unique_ptr<string>(new string(*oth.hAddress));
            }

            return *this;
        }

        Home3& operator=(Home3&& oth) noexcept{
            if (this != &oth){
                hAddress = move(oth.hAddress);
            }
            return *this;
        }

        ~Home3(){
            std::cout << "~Home3()" << std::endl;
        }
        const string getAddress()const{
            return hAddress != nullptr ? *hAddress : " ";
        }
    private:
        unique_ptr<string> hAddress;
    };

    void test(){
        unique_ptr<int> u1(new int(10));
        std::cout << *u1 << std::endl;
        std::cout << u1.get() << std::endl; //裸指针
        unique_ptr<int> u2(move(u1));
        std::cout << *u2 << std::endl;
        auto p = u2.release();
        std::cout << p << ": " << *p << std::endl;
        unique_ptr<int> u3;
        u3 = unique_ptr<int>(new int(10));
        std::cout << u3.get() << std::endl;
    }

    void test108x(){
        {
            Home3 h("Px- 01 Big Location");
            Home3 h1(h);
            Home3 h2(move(h));
            h1 = Home3("can you dodo");
            h2 = h1;
        }

        cout << "构造函数" << endl;
        Home2 h1("Shang Hai");

        cout << "拷贝构造" << endl;
        Home2 h2(h1);

        cout << "移动构造" << endl;
        Home2 h3(move(h1));

        cout << "拷贝赋值" << endl;
        h2 = h3;

        cout << "移动赋值" << endl;
        h3 = Home2("Bei Jing");
    }

    void test108(){
        string* s1 = new string("Px-01 abc");
        string* && s2 = move(s1);
        string* && s3 = move(s2);

        int a = 10;
        int &a1 = a;
        int &&a2 = move(a);
        int* pa = &a;
        int*& pa1 = pa;
        int*&& pa2 = move(pa);

        std::cout << pa << std::endl;
        std::cout << pa1 << std::endl;
        std::cout << pa2 << std::endl;

        std::cout << "--------" << std::endl;

        std::cout << s1 << std::endl;
        std::cout << s2 << std::endl;

        std::cout << "--------" << std::endl;

        Home h1("Px-01-x ShanghaiRoad!");
        std::cout << h1.getAddress() << std::endl;
        Home h2(move(h1));
        std::cout << h2.getAddress() << std::endl;
        Home h3;
        h3 = move(h2);
        std::cout << h3.getAddress() << std::endl;
    }
}


#endif //STUDY_SMART_H
