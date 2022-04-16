#include "structure.h"
#include <iostream>

void getAllCourses(School *school) { // get all courses info in school
    if (school == NULL) {
        cout << "Data not found!" << endl;
        return;
    }
    string daysOfWeek[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    string sessions[4] = {"07:30", "09:30", "13:30", "15:30"};
    cout << "All courses:" << endl;
    Course *list = school->allCourses.monitor->nextCourse;
    int i = 0;
    while (list != NULL) {
        cout << ++i << ". " << list->courseName << " (" << list->courseID << ")" << endl;
        cout << " Teacher: " << list->teacherName << endl;
        cout << " Number of credits: " << list->numberofCredit << endl;
        cout << " Maximum number of students allowed: " << list->maxStudent << endl;
        cout << " Schedule (Sessions):" << endl;
        for (int j = 0; j < 2; ++i) {
            int ses = list->session[j];
            cout << "  " << daysOfWeek[list->day[j] - 1] << " at S" << ses << " (" << sessions[ses] << ")" << endl;
        }
        cout << " Semester: " << list->semester << "/" << list->schoolyear << endl;
        cout << " Classes: ";
        Class* cl = &(list->courseClass);
        while (cl->nextClass != NULL) {
            cout << cl->classID << ", ";
            cl = cl->nextClass;
        }
        cout << cl->nextClass;
        list = list->nextCourse;
    }
    if (school->allCourses.sizeofCourses == 0) cout << "No courses to display.";
}

void getAllClasses(School* school) { // get all classes info in school
    if (school == NULL) {
        cout << "Data not found!" << endl;
        return;
    }
    cout << "All classes:" << endl;
    Class *list = school->allClasses.monitor->nextClass;
    int i = 0;
    while (list != NULL) {
        cout << ++i << ". " << list->classID << endl;
        list = list->nextClass;
    }
    if (school->allClasses.numberofClasses == 0) cout << "No classes to display.";
}

void getStudentsOnCourse(Course* course) {
    Class* classes = &course->courseClass;
    cout << "List of students in the course " << course->courseName << " (" << course->courseID << "):" << endl;
    int classIndex = 0;
    while (classes != NULL) {
        cout << ++classIndex << ". Class " << classes->classID << " (" << classes->sizeOfClass << " student(s)):" << endl;
        Student* students = classes->monitor->nextStudent;
        int studentIndex = 0;
        while (students != NULL) {
            cout << " " << ++studentIndex << ". ID " << students->studentID << " | " << students->firstName << " " << students->lastName << endl;
            students = students->nextStudent;
        }
        if (studentIndex == 0) cout << "This class has no students.";
        classes = classes->nextClass;
    }
    if (classIndex == 0) cout << "This course has no classes.";
}