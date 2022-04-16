#include "structure.h"

bool enroll(Student *student, string courseID_x) { // Returns 'true' if success, 'false' if failed
    if (student == NULL) return false;
    enrolledCourse *course = student.myCourses->monitor->nextEnrolledCourse;
    while (courses != NULL) {
        if (courses->courseID == courseID_x) return false;
        course = course->nextEnrolledCourse;
    }
    student.myCourses->addNewEnrolledCourse(course);
    return true;
}

bool remove(Student *student, string courseID_x) { // Returns 'true' if success, 'false' if failed
    if (student == NULL) return false;
    enrolledCourse *prev = student.myCourses->monitor, *start = prev->nextEnrolledCourse;
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

bool viewAllEnrolledCourses(Student *student) {
    if (student == NULL || student.myCourses == NULL) {
        cout << "Error: Student not found or could not get courses info!" << endl;
        return;
    }
    enrolledCourses courseList = student.myCourses->monitor->next;
    cout << "Student's Enrolled Courses:" << endl;
    if (courseList == NULL) return;
    courseList = courseList->nextEnrolledCourse;
    int i = 0;
    while (courseList != NULL) {
        courseList->displayInfo(++i);
        courseList = courseList->nextEnrolledCourse;
    }
    if (student.myCourses->sizeofList == 0) cout << "No courses to display." << endl;
}