#include "Student.h"
#include "Course.h"
#include "AdministrativeTools.h"

int main() 
{
    Student student1(839485, "Daisy");
    Student student2(45879, "Moose");
    Student student3(57389, "Luna");
    Course course1(101, "Intro to CIS", "Mr. Hoppkins", 2);
    course1.PrintStudent();
    AdministrativeTools administrative;

    student1.PrintCourse();
    student2.PrintCourse();
    student3.PrintCourse();
    administrative.addStudent(student1);
    administrative.addStudent(student2);
    administrative.addStudent(student3);
    
    administrative.addCourse(course1);
    
    administrative.enroll(839485, 101);
    administrative.enroll(45879, 101);
    administrative.enroll(57389, 101);
    
    administrative.PrintCourseStudents(101);
    administrative.PrintStudentsCourses(839485);
    
    administrative.drop(45879, 101);
    administrative.PrintCourseStudents(101);
    administrative.PrintActivityLog();
    
    
    
    
     
    

    return 0;
}


