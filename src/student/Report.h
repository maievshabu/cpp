//
// Created by redredmaple on 2026/1/7.
//

#ifndef STUDENT_REPORT_H
#define STUDENT_REPORT_H
#include "Person.h"
#include "Course.h"
#include "Student.h"
#include <vector>


class Report {
public:
    Report() = default;
    void read();
    void result();
    void quit(){cout << "bye bye!!" << endl;}
    void search(int id);
    void search(string courseNo);
private:
    vector<Student> students;
};


#endif //STUDENT_REPORT_H
