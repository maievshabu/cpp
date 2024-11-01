//
// Created by xiaowei003 on 2024/10/31.
//

#include "Fun.h"
#include <list>
#include <algorithm>
#include <iterator>
#include "../util/Util.h"
#include <vector>
#include <ctype.h>
#include <map>
#include <numeric>
using namespace std;
using namespace std::placeholders;

int main(void)
{
    /**
    list<int> col1;
    generate_n(back_inserter(col1), 10, IntSequence(1));

//    print_r<decltype(col1)>(col1);
    PRINT_CONTAINER(col1);

    generate(next(col1.begin()), prev(col1.end()), IntSequence(42));
    PRINT_CONTAINER(col1);

    IntSequence seq(1);
    generate_n<back_insert_iterator<std::list<int>>, int , IntSequence&>(back_inserter(col1), 4, seq);
    PRINT_CONTAINER(col1);

    generate_n(back_inserter(col1), 4, IntSequence(100));
    PRINT_CONTAINER(col1);

    generate_n(back_inserter(col1), 4, seq);
    PRINT_CONTAINER(col1);

    generate_n(back_inserter(col1), 4, seq);
    PRINT_CONTAINER(col1);

    std::vector<int> col1{1,2,3,4,5,6,7,8};
    MeanValue mv = for_each(col1.begin(), col1.end(), MeanValue());
    for_each(col1.begin(), col1.end(),[](int elem)->void{
        std::cout << elem << std::endl;
    }),
    std::cout << "mean value : " << mv.value() << std::endl;

    list<int> col1{1,2,3,4,5,6,7,8,9,10};
    PRINT_CONTAINER(col1, "init: ");

//    list<int>::iterator pos;
//    pos = remove_if(col1.begin(), col1.end(), Nth(3));
//    col1.erase(pos);
//    PRINT_CONTAINER(col1);

    for_each(col1.begin(), col1.end(), negate<int>());
    PRINT_CONTAINER(col1, "negate: ");
     **/

    /**
     * predefined function objects
     * negate
     * plus
     * minus
     * mutiplies
     * divides
     * modules
     * equal_to
     * not_equal_to
     * less
     * greater
     * less_equal
     * greater_equal
     * logic_not
     * logic_and
     * logic_or
     * bit_and
     * bit_or
     * bir_xor
     */

    /**
     * function adapter and binders
     * bind(op, args...) bind args to op
     * mem_fn(op) calls op as memeber function for an object or pointer ot object
     * not1(op) Unary negation !op(param) deprecated
     * not2(op) binary negation !op(param1, param2) deprecated
     */

    /**
    auto neg = std::bind(std::negate<int>(), std::placeholders::_1);
    std::cout << neg(1) << std::endl;

    auto plus10time2 =  std::bind(std::multiplies<int>(), std::bind(std::plus<int>(), std::placeholders::_1, 10), 2);
    std::cout << plus10time2(7) << std::endl;

    auto bb = std::bind(std::plus<int>(), std::placeholders::_1, 10); //param + 10
    std::cout << bb(10) << std::endl;

    auto a = std::bind(foo,  std::bind(std::negate<int>(), std::placeholders::_1), std::bind(std::plus<int>(),  std::placeholders::_2, 10));
    //foo(-param1, param2 +10);
    cout << a(1,2) << endl;

    string s("Internationalization");
    string sub("Nation");

    auto pos = search(s.begin() ,s.end(),
            sub.begin(), sub.end(),
            std::bind(equal_to<char>(),
                    std::bind(myToupper, _1),
                    std::bind(myToupper, _2)));
    if (pos != s.end()){
        std::cout << sub << " is a part of " << s << std::endl;
    }

    int aa = 010;
    std::cout << "before aa " << aa <<std::endl;
    auto ab = std::bind([=](int &i)->int{
        ++i; return i;
    }, std::ref(aa));

    auto ab = std::bind(incr, std::ref(aa))();
    std::cout << "after aa "<< aa <<std::endl;

    **/

    /**
    vector<Hor> col1{Hor("Maiev"), Hor("Udo"), Hor("Mike")};
//    for_each(vc.begin(), vc.end(), std::bind(&Hor::print, _1));
    for_each(col1.begin(), col1.end(), std::mem_fn(&Hor::print));

    std::cout << "---------------" << std::endl;
//    std::mem_fn(&Hor::print)(n); //call n.print();
    Hor n("Too Yound!!!");
    std::mem_fn(&Hor::print2)(n, "can u fell ");

    std::cout << "---------------" << std::endl;
    std::mem_fn(&Hor::print)(col1.begin());
    std::mem_fn(&Hor::print)(col1.begin()+1);
    std::mem_fn(&Hor::print)(col1.begin()+2);

    std::cout << "---------------" << std::endl;
    for_each(col1.begin(), col1.end(), std::bind(std::mem_fn(&Hor::print2), _1, "Hor: "));
    **/

    /**
    map<string,int> col1;
    col1.insert({"maiev", 11});
    col1.insert({"uki", 12});
    col1.insert({"kiz", 13});
    col1.insert({"uuz", 14});
    int sum = accumulate(
            col1.begin(),
            col1.end(), 0,
            bind(plus<int>(), _1,
                 bind(&map<string, int>::value_type::second, _2)));

    std::cout << "sum of :" << sum << std::endl;
    **/

    /**
    vector<int> col1  = {1,2,3,4,5,6,7,8,9};
    vector<int> col2(col1.size());
    vector<int> result(col1.size());

    copy(col1.begin(), col1.end(), std::ostream_iterator<int>(cout, " "));
    std::cout << std::endl;

    std::transform(col1.begin(), col1.end(), col2.begin(), [](int elem){
        return elem * 2;
    });

    copy(col2.begin(), col2.end(), std::ostream_iterator<int>(cout, " "));
    std::cout << std::endl;

    std::transform(col1.begin(), col1.end(), col2.begin(), result.begin(), [](int x, int y)->int{
        return x + y;
    });

    copy(result.begin(), result.end(), std::ostream_iterator<int>(cout, " "));
    std::cout << std::endl;

    for_each(col2.begin(), col2.end(), [](int elem){
        std::cout << elem << " ";
    });

    std::cout << endl;

    transform(col1.begin(),
            col1.end(),
            ostream_iterator<float>(cout, " "),
            bind(fopow<float,int>(), 3, _1)
            );
    std::cout << std::endl;

    fopow<double,int> fopow;
    std::cout << fopow.operator()(2,3)<< std::endl;
    std::cout << fopow(2,3)<< std::endl;
    **/

    /**
    string s("Internation");
    string sub("nation");

    auto pos = search(s.begin() ,s.end(), sub.begin(), sub.end(), [](char c1, char c2){
        return toupper(c1)  == toupper(c2);
    });

    if (pos != s.end()){
        std::cout << sub << " is sub of " << s << std::endl;
    }

    **/

    return 0;
}


