#include "structure.h"

bool enroll(Student *student, string courseID_x) { // Returns 'true' if success, 'false' if failed
    if (student == NULL) return false;
    enrolledCourse *course = student->myCourses->monitor;
    while (courses != NULL) {
        if (courses->courseID == courseID_x) return false;
        course = course->nextEnrolledCourse;
    }
    student->myCourses->addNewEnrolledCourse(course);
    return true;
}

bool remove(Student *student, string courseID_x) { // Returns 'true' if success, 'false' if failed
    if (student == NULL) return false;
    enrolledCourse *course = student->myCourses->monitor, *start = new enrolledCourse, *prev = start;
    start->nextEnrolledCOurse = course;
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
    student->myCourses->monitor = start->nextEnrolledCourse;
    delete start;
    return removed;
}

bool viewAllEnrolledCourses(Student *student) {
    if (student == NULL || student->myCourses == NULL) {
        cout << "Student not found or could not get courses info!" << endl;
        return;
    }
    enrolledCourses courseList = student->myCourses->monitor;
    cout << "Student's Enrolled Courses:" << endl;
    while (courseList != NULL) {
        cout << "Course ID: " << courseList->courseID << endl;
    }
    if (student->myCourses->sizeofList == 0) cout << "No courses to display." << endl;
}