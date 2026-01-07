//
// Created by redredmaple on 2025/8/4.
//

#ifndef MAIEV_CLOCK_H
#define MAIEV_CLOCK_H
class ClockType{
public:
    ClockType(int,int,int);
    ClockType();
    void setTime(int, int ,int);
    void getTime(int&, int&, int&) const;
    void printTime() const;
    void incrementSeconds();
    void incrementMinutes();
    void incrementHours();
    bool equalTime(const ClockType&)const;
private:
    int hr;
    int min;
    int sec;
};

void _assert(int hour, int minute, int second){
    assert(hour >= 0 && hour < 24);
    assert(minute >= 0 && minute < 60);
    assert(second >= 0 && second < 60);
}

ClockType::ClockType() {
    hr = 0;
    min = 0;
    sec = 0;
}

ClockType::ClockType(int hour, int minute = 0, int second = 0) {
    _assert(hour,minute,second);
    hr = hour;
    min = minute;
    sec = second;
}

void ClockType::setTime(int hour, int minute, int second) {
    _assert(hour,minute,second);
    hr = hour;
    min = minute;
    sec = second;
}

bool ClockType::equalTime(const ClockType &other) const {
    return other.min == min && other.hr == hr && other.sec == sec;
}

void ClockType::incrementHours() {
    if (++hr > 23){ //24小时制
        hr = 0;
    }
}

void ClockType::incrementSeconds() {
    if (++sec > 59){
        ++min;
        sec = 0;
    }
};

void ClockType::incrementMinutes(){
    if (++min > 59){
        ++hr;
        min = 0;
    }
}

void ClockType::getTime(int &hour, int &minute, int &second) const {
    hour = hr;
    minute = min;
    second = sec;
}

void ClockType::printTime() const {
    std::cout << " hour: " << hr;
    std::cout << " minute: " << min ;
    std::cout << " second: " << sec;
    std::cout << std::endl;
}

#endif //MAIEV_CLOCK_H
