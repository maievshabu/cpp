//
// Created by redredmaple on 2025/12/16.
//

#include "inc.h"

#ifndef STUDY_BYTE_H
#define STUDY_BYTE_H

namespace __byte{
    //编码
    template<typename T>
    std::vector<uint8_t>encode(const T&);

    //解码
    template<typename T>
    T decode(const std::vector<uint8_t>& buff);

    template<typename T>
    std::vector<uint8_t> encode(const T& data){
        std::vector<uint8_t> buff(sizeof(T));
        memcpy(buff.data(), &data, sizeof(data));

        return buff;
    }

    // 将整数转为大端字节序写入缓冲区
    template<typename T>
    void write_big_endian(std::vector<uint8_t>& buff, T value) {
        for (int i = sizeof(T) - 1; i >= 0; --i) {
            buff.push_back(static_cast<uint8_t>((value >> (i * 8)) & 0xFF));
        }
    }

    // 从缓冲区按大端字节序读取整数
    template<typename T>
    T read_big_endian(const std::vector<uint8_t>& buff, size_t& offset) {
        T value = 0;
        for (size_t i = 0; i < sizeof(T); ++i) {
            value = (value << 8) | buff[offset++];
        }
        return value;
    }

    template<typename T>
    T decode(const std::vector<uint8_t>& buff){
        T data{};
        memcpy(&data, buff.data(), sizeof(T));

        return data;
    }

    struct Person{
        int age;
        double score;
        std::string name;
    };

    template<>
    std::vector<uint8_t> encode(const Person& data){
        std::vector<uint8_t> buff;

        //age
        buff.resize(sizeof(data.age));
        memcpy(buff.data(), &data.age, sizeof(data.age));

        //score
        size_t old_size = buff.size();
        buff.resize(old_size + sizeof(data.score));
        memcpy(buff.data() + old_size, &data.score, sizeof(data.score));

        //name: 先写长度，再写内容
        old_size = buff.size();
        uint64_t  len = data.name.size();
        buff.resize( old_size + sizeof(uint64_t) + len);
        memcpy(buff.data() + old_size, &len, sizeof(uint64_t));
        memcpy(buff.data() + old_size + sizeof(uint64_t), data.name.data(), len);

        return buff;
    }

    template<>
    Person decode(const std::vector<uint8_t>& buff){
        Person p{};
        size_t offset = 0;

        //age
        memcpy(&p.age, buff.data() + offset, sizeof(p.age));
        offset += sizeof(p.age);
        std::cout << "age:" << p.age << std::endl;

        //score
        size_t old_size = buff.size();
        memcpy(&p.score, buff.data() + offset, sizeof(p.score));
        offset += sizeof(p.score);
        std::cout << "score:" << p.score<< std::endl;

        uint64_t  len{};
        memcpy(&len, buff.data() + offset, sizeof(uint64_t));
        offset += sizeof(uint64_t);
        std::cout << "len:" << len << std::endl;

        p.name.resize(len);
        memcpy(&p.name[0], buff.data() + offset, len);
        offset += len;
        std::cout << "name:" << p.name << std::endl;

        std::cout << "---------" << std::endl;

        return p;
    }

    std::vector<uint8_t> encode(const Person& data) {
        std::cout << "common: " << std::endl;
        std::vector<uint8_t> buff;

        // age
        write_big_endian<int>(buff, data.age);

        // score (double 转成 uint64_t 位模式)
        uint64_t score_bits;
        memcpy(&score_bits, &data.score, sizeof(double));
        write_big_endian<uint64_t>(buff, score_bits);

        // name: 先写长度，再写内容
        uint64_t len = data.name.size();
        write_big_endian<uint64_t>(buff, len);
        buff.insert(buff.end(), data.name.begin(), data.name.end());

        return buff;
    }

    Person decode(const std::vector<uint8_t>& buff) {
        Person p{};
        size_t offset = 0;

        // age
        p.age = read_big_endian<int>(buff, offset);

        // score
        uint64_t score_bits = read_big_endian<uint64_t>(buff, offset);
        memcpy(&p.score, &score_bits, sizeof(double));

        // name
        uint64_t len = read_big_endian<uint64_t>(buff, offset);
        p.name.assign(reinterpret_cast<const char*>(buff.data() + offset), len);
        offset += len;

        return p;
    }



    void text(){
        class B{
            virtual void do_f(){
                std::cout << "B::do_f()" << std::endl;
            }
        public:
            void f() {do_f();}
        };

        struct D : B{
            void do_f() override{
                std::cout << "D::do_f()" << std::endl;
            }
        };


        D d;
        B* bp = &d;
        bp->f();
    }

    struct A{
        virtual void f(){
            std::cout << "A::f()" << std::endl;
        }
    };

    struct B : A {
        void f(){
            std::cout << "B::f()" << std::endl;
        }};
    struct C : virtual B {
        void f(){
            std::cout << "C::f()" << std::endl;
        }
    };

    struct D : virtual B{};

    struct E : C, D{
        using A::f;
    };

    void test(){
        E e;
        e.f();
        e.E::f();

        std::cout << "---------" << std::endl;

        string s1("helloworld!!");
        std::cout << s1.c_str() << std::endl;
        std::cout << static_cast<const void*> (s1.data()) << std::endl;
        std::cout << static_cast<const void*> (&s1[0]) << std::endl;

        Person p1{25, 99.5, "Alice Wonderland"};
        auto buff = encode(p1);
        Person p2 = decode(buff);
        std::cout << p2.age << " " << p2.score << " " << p2.name << std::endl;
    }

    void test1(){

        Person p1{10, 20.1, string("maiev")};
        std::cout << "---------" << std::endl;

        std::cout << &p1.age << std::endl;
        std::cout << &p1.score << std::endl;
        std::cout << &p1.name << std::endl;

        std::vector<uint8_t> buff = encode(p1);
        auto p = decode<Person>(buff);

        std::cout << p.age << std::endl;
        std::cout << p.score << std::endl;
        std::cout << p.name << std::endl;
    }

    void test2(){
        std::vector<uint8_t> vc{};
        string name(300, 'a');
        uint64_t len = name.size(); //8

        vc.resize(len + sizeof(len));
        memcpy(vc.data() , &len, sizeof(uint64_t));
        memcpy(vc.data() + sizeof(uint64_t), name.data(), name.size());

        for(uint64_t c: vc){
            std::cout << c << " ";
        }

        std::cout << std::endl;

        string x;
        size_t xlen;
        memcpy(&xlen, vc.data(), sizeof(uint64_t));
        std::cout << "xlen: " << xlen << std::endl;
        x.resize(xlen);
        memcpy(&x[0], vc.data() + sizeof(uint64_t), xlen);

        std::cout << x << std::endl;

        if (x == name ){
            std::cout << "equal" << std::endl;
        }else{
            std::cout << "no equal" << std::endl;
        }

        std::cout << std::endl;

    }
}

#endif //STUDY_BYTE_H
