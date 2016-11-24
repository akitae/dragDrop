#include "listwidget.h"

ListWidget::ListWidget(QWidget *parent) : QListWidget(parent){
    setAcceptDrops(true);
}

QVariant ListWidget::headerData(int section, Qt::Orientation orientation, int role) const
{
    // FIXME: Implement me!
}

int ListWidget::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
}

QVariant ListWidget::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    return QVariant();
}
void ListWidget::mousePressEvent(QMouseEvent *event){
    if(event->button() == Qt::LeftButton)
            startPos = event->pos();
    QListWidget :: mousePressEvent ( event) ;
}

void ListWidget::mouseMoveEvent(QMouseEvent *event){
    if(event->buttons() & Qt::LeftButton ) {
        int distance = (event->pos ()-startPos ).manhattanLength () ;
        if(distance >= QApplication::startDragDistance ())
            startDrag(Qt::MoveAction);
    }
    QListWidget::mouseMoveEvent(event);
}

void ListWidget::startDrag(Qt::DropActionaction){
    QListWidgetItem *item = currentItem();
    if(item){
        QMimeData *mimeData = new QMimeData ;
        mimeData->setText(item->text());
        QDrag *drag = new QDrag(this);
        drag->setMimeData(mimeData);
        if(drag->exec(Qt::MoveAction) == action)
            delete item ;
    }
}

void ListWidget::dragEnterEvent(QDragEnterEvent *event){
    ListWidget* source = qobject_cast<ListWidget* >(event-> source());
    if(source && source != this){
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}

void ListWidget::dragMoveEvent(QDragMoveEvent *event){
    ListWidget* source = qobject_cast <ListWidget* >(event->source());
    if(source && source != this){
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}

void ListWidget::dropEvent(QDropEvent *event){
    ListWidget* source = qobject_cast <ListWidget* >(event->source());
    if( source && source != this){
        addItem(event->mimeData()->text ());
        event->setDropAction(Qt::MoveAction);
        event->accept();
    }
}
