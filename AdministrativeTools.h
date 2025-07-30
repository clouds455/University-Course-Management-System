#include <set>
#include <map>
#include <deque>
#include <list>
#include <string>
#include <iostream>
#include "Student.h"
#include "Course.h"

using namespace std;
class AdministrativeTools {
    public:
    void addStudent(Student student);
    void removeStudent(int student_id);
    void addCourse(Course course);
    void removeCourse(int coursCode);
    void enroll(int student_id, int coursCode);
    void drop(int student_id, int coursCode);
    void PrintStudentsCourses(int student_id);
    void PrintCourseStudents(int coursCode); 
    void PrintActivityLog();
    
    
    
    private:
    map<int, Student> students;
    map<int, Course> courses;
    deque<string > activityLog; 
    
};
