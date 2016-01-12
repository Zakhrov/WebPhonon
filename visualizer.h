#ifndef VISUALIZER_H
#define VISUALIZER_H
#include <QtOpenGL/QGLWidget>
#include <QTimer>
class Visualizer : public QGLWidget
{
    Q_OBJECT
public:
    Visualizer(QWidget *parent = 0);
    ~Visualizer();
    QTimer *timer;
protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
public slots:
    void animate();
private:

  GLfloat xRot;
  int yRot;
  int zRot;
};

#endif // VISUALIZER_H
