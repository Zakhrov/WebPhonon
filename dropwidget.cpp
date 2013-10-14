#include "dropwidget.h"
#include<QWidget>
#include<QUrl>
#include <QtGui>

DropWidget::DropWidget(QWidget *parent) :
    Phonon::VideoWidget(parent)
{
    setAcceptDrops(true);
}
void DropWidget::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasUrls())
        event->acceptProposedAction();

}

void DropWidget::dragMoveEvent(QDragMoveEvent *event)
{
    event->acceptProposedAction();
}


void DropWidget::dropEvent(QDropEvent *event)
{
    if(event->mimeData()->hasUrls())
    emit geturls(event->mimeData());
}

