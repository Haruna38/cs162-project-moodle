#include "structure.h"
#include <iostream>

bool enroll(Student *student, string courseID_x, string &failed_reason) { // Returns 'true' if success, 'false' if failed
    if (student == NULL) return false;
    enrolledCourse *courses = student->myCourses.monitor->nextEnrolledCourse;
    while (courses != NULL) {
        if (courses->courseID == courseID_x) {
            failed_reason = "You are already enrolled in this course!";
            return false;
        }
        courses = courses->nextEnrolledCourse;
    }
    student->myCourses.addNewEnrolledCourse(courseID_x);
    return true;
}

bool remove(Student *student, string courseID_x) { // Returns 'true' if success, 'false' if failed
    if (student == NULL) return false;
    enrolledCourse *prev = student->myCourses.monitor, *start = prev->nextEnrolledCourse, *course = start;
    if (course == NULL) return false;
    start->nextEnrolledCourse = course;
    bool removed = false;
    while (course != NULL) {
        enrolledCourse *inter = course;
        course = course->nextEnrolledCourse;
        if (course->courseID == courseID_x) {
            prev->nextEnrolledCourse = course;
            removed = true;
            delete inter;
            break;
        }
        else prev = inter;
    }
    return removed;
}

void viewAllEnrolledCourses(Student *student) {
    if (student == NULL) {
        cout << "Error: Student not found or could not get courses info!" << endl;
        return;
    }
    enrolledCourse *list = student->myCourses.monitor->nextEnrolledCourse;
    cout << "Student's Enrolled Courses:" << endl;
    if (list == NULL) return;
    list = list->nextEnrolledCourse;
    int i = 0;
    while (list != NULL) {
        cout << ++i << ". " << list->courseID << endl;
        list = list->nextEnrolledCourse;
    }
    if (student->myCourses.sizeofList == 0) cout << "No courses to display." << endl;
}