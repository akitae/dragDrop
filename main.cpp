#include "dragdrop.h"
#include <QApplication>
#include "listwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //DragDrop w;
    ListWidget w;
    w.show();

    return a.exec();
}
