//
// Created by redredmaple on 2025/8/9.
//

using namespace std;
#include <string>
#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

#ifndef MAIEV_COURSE_H
#define MAIEV_COURSE_H

class courseType{
public:
    void setCourseInfo(string cName, string cNo, char grade, int credit);
    void print(ostream& os, bool isGrade);
    int getCredits();
    void getCourseNumbers(string& cNo);
    char getGrade();

    bool operator==(const courseType&) const;
    bool operator!=(const courseType&) const;
    bool operator<=(const courseType&) const;
    bool operator<(const courseType&) const;
    bool operator>=(const courseType&) const;
    bool operator>(const courseType&) const;

    courseType(string cName="", string cNo="", char grade='*', int credits=0);

private:
    string courseName;
    string courseNo;
    char courseGrade;
    int courseCredit;
};

void courseType::setCourseInfo(string cName, string cNo, char grade, int credit) {
    courseName = cName;
    courseNo = cNo;
    courseGrade = grade;
    courseCredit = credit;
}

void courseType::print(ostream& os, bool isGrade) {
    os << left;
    os << setw(8) << courseNo << " ";
    os << setw(8) << courseName << " ";
    os.unsetf(ios::left);
    os << setw(3) << courseCredit << " ";

    if (isGrade){
        os << setw(4) << courseGrade << endl;
    }else{
        os << setw(4) << "***"<< endl;
    }
}

courseType::courseType(string cName, string cNo, char grade, int credits) {
    setCourseInfo(cName,cNo,grade,credits);
}

int courseType::getCredits() {
    return courseCredit;
}

char courseType::getGrade() {
    return courseGrade;
}

void courseType::getCourseNumbers(string &cNo) {
    cNo = courseNo;
}

bool courseType::operator>=(const courseType & other) const {
    return courseNo >= other.courseNo;
}

bool courseType::operator>(const courseType & other) const {
    return courseNo > other.courseNo;
}

bool courseType::operator==(const courseType & other) const {
    return courseNo == other.courseNo;
}

bool courseType::operator!=(const courseType & other) const {
    return courseNo != other.courseNo;
}

bool courseType::operator<=(const courseType & other) const {
    return courseNo <= other.courseNo;
}

bool courseType::operator<(const courseType & other) const {
    return courseNo < other.courseNo;
}

class personType{
public:
    personType():_firstname(""), _lastname(""){}
    personType(string firstName, string lastName):_firstname(firstName),_lastname(lastName){}
    void setName(string firstName, string lastName){
        _firstname = firstName;
        _lastname = lastName;
    }
    void print() const{
        cout << _firstname << " " << _lastname;
    }
    string getFirstName(){return _firstname;}
    string getLastName(){return _lastname;}
private:
    string _firstname;
    string _lastname;
};



class studentType{
public:
    void setInfo(string fName, string lName, int Id, bool isTPaid, vector<courseType> courses);
    void print(ostream& os, double tuitionRate);
    studentType();
    int getHoursEnRolled();
    double getGPa();
    double billingAmount(double  tuitionRate);
private:
    int sId;
    int numberOfCourse;
    bool isTuitionPaid;
    personType person;
    vector<courseType> coursesEnrolled;
};

void studentType::setInfo(string fName, string lName, int Id, bool isTPaid, vector<courseType> courses) {
    person.setName(fName,lName);
    sId = Id;
    isTuitionPaid = isTPaid;

    numberOfCourse = courses.size();
    coursesEnrolled = courses;
    sort(coursesEnrolled.begin(), coursesEnrolled.end());
}
studentType::studentType():person() {
    sId = 0;
    numberOfCourse = 0;
    isTuitionPaid = false;
}

void studentType::print(ostream &os, double tuitionRate) {
    os << "student name :" << person.getFirstName();
    os << " "  << person.getLastName() << endl;
    os << "Student Id: " << sId << endl;
    os << "NUmber of courses enrolled:" << numberOfCourse << endl;

    os << left;
    os << "Course No:" << setw(15) << " Course Name"
        << setw(8) << "Credit"
        << setw(6) << "Grade" << endl;

    os.unsetf(ios::left);

    for(int i = 0; i < numberOfCourse; i++){
        coursesEnrolled[i].print(os, isTuitionPaid);
    }
    os << endl;

    os << "Total number of credit hours:" << getHoursEnRolled() << endl;

    os << fixed << showpoint << setprecision(2);

    if (isTuitionPaid){
        os << "Mid semester GPA :" << getGPa() << endl;
    }else{
        os << "*** Grades are being held for not playing "
           << "the tuition.***" << endl;
        os << "Amount Due : $" << billingAmount(tuitionRate) << endl;
    }

    os << "_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*_*" << endl<<endl;
}

int studentType::getHoursEnRolled() {
    int totalCredits = 0;
    for(int i = 0; i < numberOfCourse; i++){
        totalCredits += coursesEnrolled[i].getCredits();
    }

    return totalCredits;
}

double studentType::billingAmount(double tuitionRate) {
    return tuitionRate * getHoursEnRolled();
}

double studentType::getGPa() {
    double sum = 0.0;
    for(int i = 0; i < numberOfCourse; i++){
        switch(coursesEnrolled[i].getGrade()){
            case 'A':
                sum += coursesEnrolled[i].getCredits() * 4;
                break;
            case 'B':
                sum += coursesEnrolled[i].getCredits() * 3;
                break;
            case 'C':
                sum += coursesEnrolled[i].getCredits() * 2;
                break;
            case 'D':
                sum += coursesEnrolled[i].getCredits() * 1;
                break;
            case 'F':
                break;
            default:
                cout << "Invalid Course Grade" << endl;
        }
    }

    if (getHoursEnRolled()){
        return sum / getHoursEnRolled();
    }else{
        return 0;
    }
}

void getStudentData(ifstream& infile, vector<studentType> & studentList){
    string fName;
    string lName;
    int ID;
    int nofCourses;
    char isPaid;
    bool isTuitionPaid;

    string cName;
    string cNo;
    char grade;
    int credits;

    vector<courseType> courses;
    courseType cTemp;
    studentType sTemp;

    infile >> fName;
    while(infile){
        infile >> lName >> ID >> isPaid;
        if (isPaid == 'Y'){
           isTuitionPaid = true;
        }else{
            isTuitionPaid = false;
        }

        infile >> nofCourses;

        courses.clear();

        for(int i = 0; i < nofCourses; i++){
            infile >> cName >> cNo >> credits >> grade;
            cTemp.setCourseInfo(cName, cNo, grade, credits);
            courses.push_back(cTemp);
        }

        sTemp.setInfo(fName,lName, ID, isTuitionPaid, courses);
        studentList.push_back(sTemp);

        infile >> fName;
    }
}

void printGradeReports(ofstream& outfile, vector<studentType> studentList, double tuitionRate){
    std::cout << studentList.size() << std::endl;
    for(int count = 0 ; count < studentList.size(); count++){
        studentList[count].print(outfile, tuitionRate);
    }
}

#endif //MAIEV_COURSE_H
