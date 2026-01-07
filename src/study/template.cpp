//
// Created by redredmaple on 2025/12/10.
//

#include "inc.h"
#include "template.h"

namespace _tpl{
    void test1(){
        auto f = Foo{};

        auto greet = std::mem_fn(&Foo::display_greeting);
        greet(f);

        auto print_num = std::mem_fn(&Foo::display_number);
        print_num(f, 3);

        auto access_data = std::mem_fn(&Foo::data);
        std::cout << "data: " << access_data(f) << '\n';

        auto add_xy = std::mem_fn(&Foo::add_xy);
        std::cout << "add_xy:" << add_xy(f, 1,2) << '\n';

//        auto u = std::make_unique<Foo>();
//        std::cout << "access_data(u): " << access_data(u) << '\n';
//        std::cout << "add_xy(u, 1,2):" << add_xy(u, 1,2) << '\n';

        auto add_many = std::mem_fn(&Foo::add_many<short, int, long>);
        std::cout << "add_many(u,...)" << add_many(f, 1,1, 1000L) << '\n';

        std::function<int()> ff = nullptr;
        try{
            ff();
        }catch(const std::bad_function_call& e){
            std::cout << e.what() << std::endl;
        }
    }
}