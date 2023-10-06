#include "QT_Mark.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QT_Mark w;
    w.showMaximized();// 最大化显示窗口
    //w.setWindowFlags(w.windowFlags() & ~Qt::WindowMaximizeButtonHint);// 禁止最大化按钮
    w.show();
    return a.exec();
}
