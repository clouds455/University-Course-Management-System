#include <set>
#include <map>
#include <deque>
#include <list>
#include <string>
#include <iostream>
#include "Student.h"
#include "Course.h"
#include "AdministrativeTools.h"

void AdministrativeTools::addStudent(Student student) {
    students[student.getStuID()] = student;
    activityLog.push_back("Added Student " + to_string(student.getStuID()));
    
}
void AdministrativeTools::removeStudent(int studentId) {
    students.erase(studentId);
    activityLog.push_back("Removed Student " + to_string(studentId));
    
}
void AdministrativeTools::addCourse(Course course) {
    courses[course.getCode()] = course;
    activityLog.push_back("Added Course " + to_string(course.getCode()));
    
    
}
void AdministrativeTools::removeCourse(int courseCode) {
    courses.erase(courseCode);
    activityLog.push_back("Removed Course " + to_string(courseCode));
    
}
void AdministrativeTools::enroll(int studentId, int courseCode) {
    //Check whether the course exists or not
    if (courses.find(courseCode) == courses.end()) {
        cout << "Course Not Found" << endl;
        return; 
    }
    //check whether the student exists 
    if (students.find(studentId) == students.end()) {
        cout << "Student Not Found" << endl;
        return;
    }
    //reteriving the specfic student and course based on the student id and course code
    Student& s = students[studentId];
    Course& c = courses[courseCode];
    // testing to see if this student is already in the course
    if (s.IsEnrolledIn(to_string(courseCode))) {
        cout << s.getStuName() << " is already enrolled in " << courseCode << endl;
        return;
    }
    //for each course, we are mataining the list of students who are enrolled in the course
    s.courseEnroll(to_string(courseCode));
    c.enrollStudent(to_string(studentId));
    //displaying the message that the student is enrolled in the course and adding it to activity log
    cout << studentId << " enrolled in course " << courseCode << endl;
    activityLog.push_back(to_string(studentId) + " enrolled in course " + to_string(courseCode));
    
}
void AdministrativeTools::drop(int student_id, int coursCode) {
    if (students.find(student_id) == students.end()) {
        cout << "Student is not in the list" << endl;
        return;
    }
    if (courses.find(coursCode) == courses.end()) {
        cout << "Course is not in the list" << endl;
        return;
    }
    Student& s = students[student_id];
    Course& c = courses[coursCode];
    // testing to see if this student is already in the course
    string courseString = to_string(coursCode);
    if (!s.IsEnrolledIn(courseString)) {
        cout << "Error: Student is not in the Course" << endl;
        return;
    }
    s.courseDrop(courseString);
    c.removeStudent(to_string(student_id));
    activityLog.push_back(to_string(student_id) + " is not in the course anymore " + courseString);
    
}
void AdministrativeTools::PrintStudentsCourses(int studentId) {
    auto it = students.find(studentId);
    if (it == students.end()) {
        cout << "Student not found";
        return;
    }
    it->second.PrintCourse();
    
    
    
    
}
void AdministrativeTools::PrintCourseStudents(int coursCode) {
    auto it = courses.find(coursCode);
    if (it == courses.end()) {
        cout << "Course not found";
        return;
    }
    it->second.PrintStudent();
    
    
}
void AdministrativeTools::PrintActivityLog() {
    cout << "Activity Log" << endl;
    for (string value : activityLog) {
        cout << value << " " << endl;
    }
    
}
