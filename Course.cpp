#include "Course.h"
#include <iostream>
#include <set>

Course::Course() {
      code = 0;
      title = "Enter title";
      instructorName = "Enter Instructor's Name";
  } 
  Course::Course(int coursCode, string courseTitle, string courseInstructor, int cap) {
      code = coursCode;
      title = courseTitle;
      instructorName = courseInstructor;
      capacity = cap;
      
  }
  void Course::setCode(int coursCode) {
      code = coursCode;
  } 
  void Course::setTitle(string courseTitle) {
      title = courseTitle;
  } 
  void Course::setCapacity(int cap) {
      capacity = cap;
  } 
  void Course::setInstructor(string courseInstructor) {
      instructorName = courseInstructor;
  }
  int Course::getCode() {
      return code;
  } 
  int Course::getCapacity() {
      return capacity;
  }
  string Course::getTitle() {
      return title;
  } 
  string Course::getInstructor() {
      return instructorName;
  }
  void Course::enrollStudent(string student_id) {
      if (courseInfo.find(student_id) != courseInfo.end()) {
          cout << "Already contains " << student_id;
      }
      else {
          if (courseInfo.size() < capacity) {
            courseInfo.insert(student_id);
            cout << "Added" << endl;
          }
          else {
              waitList.push(student_id);
              cout << "Student Added to WaitList" << endl;
          }
      }
  }  
  void Course::removeStudent(string student_id) {
      if (courseInfo.find(student_id) == courseInfo.end()) {
          cout << "You can't remove this course" << endl;
      }
      else {
          courseInfo.erase(student_id);
          cout << "Removed " << endl;
      }
      if (!waitList.empty()) {
          string enrolledFromWaitList = waitList.front();
          waitList.pop();
          courseInfo.insert(enrolledFromWaitList);
          cout << "Student" << enrolledFromWaitList << " has now been added to the enrollment list" << endl;
      }
  }
void Course::PrintStudent() {
    if (courseInfo.empty()) {
        cout << "No Student currently Enrolled in Course" << endl;
    }
    else {
        cout << "Students Enrolled in Course:" << endl;
        for (string id : courseInfo) {
            cout << id << endl;
        }
        if (!waitList.empty()) {
            cout << "WaitList:" << endl;
            queue < string > temp = waitList;
            while (!temp.empty()) {
                cout << temp.front() << endl;
                temp.pop();
            }
        }
    }
}
