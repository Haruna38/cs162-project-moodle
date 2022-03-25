#include "structure.h"

void getAllCourses(School* school) { // get all courses info in school
    if (school == NULL || school->allCourses == NULL) {
        cout << "Data not found!" << endl;
        return;
    }
    cout << "All courses:" << endl;
    Course *list = school->allCourses->monitor;
    while (list != NULL) {
        cout << "Course ID: " << list->courseID << endl;
    }
    if (school->allCourses->sizeofList == 0) cout << "No courses to display.";
}

void getAllClasses(School* school) { // get all classes info in school
    if (school == NULL || school->allClasses == NULL) {
        cout << "Data not found!" << endl;
        return;
    }
    cout << "All classes:" << endl;
    Course *list = school->allClasses->monitor;
    while (list != NULL) {
        cout << "Class ID: " << list->ID << " | School year: " << list->schoolyear << " | Class size: " << list->sizeOfClass << endl;
    }
    if (school->allClasses->sizeofList == 0) cout << "No classes to display.";
}