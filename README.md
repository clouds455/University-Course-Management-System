# University-Course-Management-System
#include <iostream>
#include <set>
#include <list>
#include <queue>
#include <map>
#include <deque>
#include <string>
using namespace std;


class Student {
    public:
    Student();
    Student(int stuID, string stuName);
    int getStuID();
    string getStuName();
    void setStuID(int stuID);
    void setStuName(string stuName);
    void courseEnroll(string courseEnroll);
    void courseDrop(string courseEnroll);
    bool IsEnrolledIn(string courseEnroll);
    void PrintCourse();


    private:
    int id;
    string name;
    set<string> coursesEnrolled;
};
