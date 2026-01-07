//
// Created by redredmaple on 2025/8/25.
//

#ifndef MAIEV_RESULT_H
#define MAIEV_RESULT_H

template<typename T>
class Result {
public:
    T data;
    Result() {}
    Result(T d) : data(d) {}

    friend ostream& operator<<(ostream& os, const Result<T>& r) {
        os << "Result: " << r.data;
        return os;
    }
};


#endif //MAIEV_RESULT_H
