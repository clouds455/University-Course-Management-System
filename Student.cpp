#include "Student.h"
#include <iostream>
#include <set>
    
    Student::Student() {
    id = 0;
    name = " ";
    }
    
    Student::Student(int stuID, string stuName) {
      id = stuID;
      name = stuName;
    }
    void Student::setStuID(int stuID) {
      id = stuID;
    }
    void Student::setStuName(string stuName) {
      name = stuName;
    }
    int Student::getStuID() {
      return id;
    } 
    string Student::getStuName() {
      return name;
    }

    void Student::courseEnroll(string courseEnroll) {
      if (IsEnrolledIn(courseEnroll) == true) {
        cout << "Can't Enroll, Enrolled Already" << endl;
      }
      else {
        coursesEnrolled.insert(courseEnroll);
        cout << "Enrolled in " << courseEnroll << endl;
      }
    }  
      void Student::courseDrop(string courseEnroll) {
        if (IsEnrolledIn(courseEnroll) == false) {
          cout << "Can't Drop, You are not in this course" << endl;
        }
        else {
          coursesEnrolled.erase(courseEnroll);
          cout << "Dropped " << courseEnroll << endl;
        }
      }
      bool Student::IsEnrolledIn(string courseEnroll) {
        for (string final : coursesEnrolled) {
          if (final == courseEnroll) {
            return true;
          }
        }  
        return false;
      }  
      void Student::PrintCourse() {
        if (coursesEnrolled.empty()) {
          cout << id << " is not in any course." << endl;
        }
        else {
          for (string final : coursesEnrolled) {
            cout << final << endl;
          }
        
        }
    }  
