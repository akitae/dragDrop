#ifndef DRAGDROP_H
#define DRAGDROP_H

#include <QMainWindow>

namespace Ui {
class DragDrop;
}

class DragDrop : public QMainWindow
{
    Q_OBJECT

public:
    explicit DragDrop(QWidget *parent = 0);
    ~DragDrop();

private:
    Ui::DragDrop *ui;
};

#endif // DRAGDROP_H
