#include <set>
#include <iostream>
using namespace std;

class Course {
    public:
    Course();
    Course(int coursCode, string courseTitle, string courseInstructor, int capacity);
    void setCode(int coursCode);
    void setTitle(string courseTitle);
    void setInstructor(string courseInstructor);
    int getCode();
    string getTitle();
    string getInstructor();
    void enrollStudent(string student_id);
    void removeStudent(string student_id);
    void setCapacity(int cap);
    int getCapacity();
    void PrintStudent();


    private:
    int code;
    string title;
    int capacity;
    string instructorName;
    set<string> courseInfo;
    queue<string> waitList;
};   
