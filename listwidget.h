#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QAbstractListModel>

class ListWidget : public QAbstractListModel
{
    Q_OBJECT

public :
    ListWidget(QWidget *parent = 0) ;
protected :
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dropEvent(QDropEvent *event);
private :
    void startDrag(Qt::DropAction);
    QPoint startPos ;

};

#endif // LISTWIDGET_H
