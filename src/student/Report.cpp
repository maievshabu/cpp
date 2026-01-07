//
// Created by redredmaple on 2026/1/7.
//

#include "Report.h"
#include "Student.h"
#include <fstream>
#include <algorithm>

void Report::read() {
    string filename = "../stData.txt";
    fstream fs(filename);

    if (!fs){
        std::cerr << "file open errors!!!!";
        return;
    }

    string firstName;
    string lastName;
    int Id;
    char isPaid;
    int courseNums;

    while(fs >> firstName >> lastName >> Id >> isPaid >> courseNums){
        Person p1(firstName, lastName);

        vector<Course> courses;

        for (int i = 0; i < courseNums; i++){
            string courseName;
            string courseNo;
            int credit;
            char grade;
            fs >> courseName >> courseNo >> credit >> grade;
            Course course(courseName, courseNo, credit,grade);
            courses.push_back(course);
        }

        sort(courses.begin(), courses.end());

        Student stu(p1, courses);
        stu.setStudent(Id, courseNums, isPaid);
        students.push_back(stu);
        std::cout << "-------------" << std::endl;
    }
}

void Report::result(){
    ofstream os("../xs.txt");
    if (!os){
        std::cerr << "no file" << std::endl;
        return;
    }

    for(Student& stu: students){
        os << stu;
        std::cout << stu << std::endl;

        for (const auto& c : stu.getCourses()) {
            std::cout << c << std::endl;
        }
        std::cout << "------------------" << std::endl;

        std::cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
    }
}

void Report::search(int id) {
    auto p = std::find(students.begin(), students.end(), id);

    if (p != students.end()){
        cout << *p << endl;
        std::cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
    }else{
        cout << "no found id :" << id << endl;
    }
}

void Report::search(string courseNo) {
    bool found = false;
    for(const auto& stu: students){
        const Course* c = stu.findCourse(courseNo);
        if (c != nullptr){
            found =  true;
            std::cout << "student id: " << stu.getId() << std::endl;
            std::cout << *c << std::endl;
            std::cout << "-*-*-*-*-*-*-*-*-*-*-*-*-*" << std::endl;
        }
    }

    if (found == false){
        std::cout << "no found courseNo: " << courseNo << std::endl;
    }
}
