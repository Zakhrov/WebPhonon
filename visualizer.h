#ifndef VISUALIZER_H
#define VISUALIZER_H
#include <QtOpenGL/QGLWidget>
#include <QTimer>
#include <QImage>
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
    void loadGLTexture();

  GLfloat xRot;
  GLfloat yRot;
  GLfloat zRot;
  GLuint texture[1];
};

#endif // VISUALIZER_H
