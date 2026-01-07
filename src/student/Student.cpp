//
// Created by redredmaple on 2026/1/6.
//

#include "Student.h"
#include <algorithm>

//ostream& operator<<(ostream& os, const Student& stu){
//    os << "stu:[ " << stu._name << " " << stu._no
//        << " " << stu._grade << "]";
//    return os;
//}
//
//istream& operator>>(istream& is, Student& stu){
//    return is >> stu._name >> stu._no >> stu._grade;
//}

void Student::setStudent(int sid, int sCourseNums, bool sisPaid){
    id = sid;
    courseNums = sCourseNums;
    isPaid = sisPaid;
}

const Course* Student::findCourse(const string &courseNo) const{
    auto p = std::find_if(courses.begin(), courses.end(), [courseNo](const Course& course){
        return course.getCourseNo() == courseNo;
    });

    if (p != courses.end()){
        return &(*p);
    }

    return nullptr;
}

ostream& operator<<(ostream& os, const Student& stu){
    os << "student name : " << stu.person << std::endl;
    os << "student id: " << stu.id << std::endl;
    os << "Number of courses: " << stu.courseNums << std::endl;

    return os;
}

