//
// Created by redredmaple on 2026/1/7.
//

#ifndef STUDENT_COURSE_H
#define STUDENT_COURSE_H
#include <string>
#include <iostream>
using namespace std;


class Course {
public:
    Course() = default;
    Course(string name, string no, unsigned int credit, char grade)
            :courseName(name),courseNo(no),courseCredit(credit),courseGrade(grade){}
    void setCourse(string name, string no, unsigned int credit, char grade){
        courseName = name;
        courseNo = no;
        courseCredit = credit;
        courseGrade = grade;
    }
    bool operator<(const Course& oth)const{
        return  courseNo < oth.courseNo;
    }
    bool operator==(const Course& oth)const{
        return courseNo == oth.courseNo;
    }
    bool operator==(const string& cNo)const{
        return courseNo == cNo;
    }
    string getCourseNo()const{return courseNo;}
    friend ostream& operator<<(ostream&os, const Course& course){
        return os << course.courseNo << " " << course.courseName << " "
                << course.courseCredit << " " << course.courseGrade;
    }
private:
    string courseName;
    string courseNo;
    unsigned int courseCredit{};
    char courseGrade{'*'};
};

#endif //STUDENT_COURSE_H
