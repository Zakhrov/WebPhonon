#ifndef VISUALIZER_H
#define VISUALIZER_H
#include <QtOpenGL/QGLWidget>
#include <QtGui>
#include <QWidget>
#include <QTimer>
#include <QImage>
#include <QMimeData>

class Visualizer : public QGLWidget
{
    Q_OBJECT
public:
    Visualizer(QWidget *parent = 0);
    ~Visualizer();
signals:
    void geturls(const QMimeData *mimeData = 0);

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void dragEnterEvent(QDragEnterEvent *event);
        void dragMoveEvent(QDragMoveEvent *event);
        void dropEvent(QDropEvent *event);


public slots:
    void animate();
private:
    void loadGLTexture();
   QTimer *timer;
  GLfloat xRot;
  GLfloat yRot;
  GLfloat zRot;
  GLuint texture[1];
};

#endif // VISUALIZER_H
