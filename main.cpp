//#include "ui/mainwindow.h"
//#include "ui/enrolled_courses.h"
//#include "ui/addnewclass.h"
//#include "ui/addnewstudent.h"
//#include "ui/addnewstudent.h"
//#include "ui/course_create.h"
//#include "ui/scoreboard_course_staff.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

#include "operating_function/structure.h"
#include "global.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "Login_Page_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

//   MainWindow as;
//    as.show();

//    enrolled_courses w;
//    w.show();

//    Course_Create ew;
//    ew.show();

//    AddNewClass anc;
//    anc.show();

//    addnewstudent ans;
//    ans.show();
    return a.exec();
}
