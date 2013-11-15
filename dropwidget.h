#ifndef DROPWIDGET_H
#define DROPWIDGET_H
#include <QtGui>
#include <QWidget>
#include <Phonon/VideoWidget>

class DropWidget : public Phonon::VideoWidget
{
    Q_OBJECT
public:
    explicit DropWidget(QWidget *parent = 0);
    
signals:
    void geturls(const QMimeData *mimeData = 0);
    void capturespace(QKeyEvent *event);
protected:
    void dragEnterEvent(QDragEnterEvent *event);
        void dragMoveEvent(QDragMoveEvent *event);
        void dropEvent(QDropEvent *event);
        void mouseDoubleClickEvent(QMouseEvent *event);
        void mouseMoveEvent(QMouseEvent *event);
        void keyPressEvent(QKeyEvent *event);
    
public slots:
    
};

#endif // DROPWIDGET_H
