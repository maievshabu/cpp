//
// Created by redredmaple on 2026/1/6.
//

#ifndef STUDENT_STUDENT_H
#define STUDENT_STUDENT_H
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Person.h"
#include "Course.h"

using namespace std;
class Student{
public:
    Student(){}
    Student(Person p, vector<Course> c):person(p), courses(c){}
    bool operator==(int sid)const{
        return id == sid;
    }
    int getId()const{return id;}
    const Course* getCourse(const string&)const;
    void setStudent(int id, int courseNums, bool isPaid);
    friend ostream& operator<<(ostream& os, const Student& stu);
private:
    Person person;
    vector<Course>courses;
    int id;
    int courseNums;
    bool isPaid;
};

#ifdef TRUE
class Student {
public:
    Student(){}
    Student(int grade, string name,string no):_no(no),_grade(grade),_name(name){}
    Student(const Student& oth){
        _no = oth._no;
        _name = oth._name;
        _grade = oth._grade;
    }
    Student& operator=(const Student& oth){
        _no = oth._no;
        _name = oth._name;
        _grade = oth._grade;
        return *this;
    }
    ~Student(){
        std::cout << "~Student()" << std::endl;
    }
    friend ostream& operator<<(ostream& os, const Student& stu);
    friend istream& operator>>(istream& os, Student& stu);
private:
    int _grade; //年纪
    string _no; //学号
    string _name; //名字
};
#endif

#endif //STUDENT_STUDENT_H
