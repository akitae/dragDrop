#include "dragdrop.h"
#include "ui_dragdrop.h"

DragDrop::DragDrop(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DragDrop)
{
    ui->setupUi(this);
}

DragDrop::~DragDrop()
{
    delete ui;
}
