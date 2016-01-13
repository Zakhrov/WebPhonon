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
    void loadGLTexture();

  GLfloat xRot;
  GLfloat yRot;
  GLfloat zRot;
  GLuint texture[1];

  GLfloat LightAmbient[4]= { 0.5f, 0.5f, 0.5f, 1.0f };                 // Ambient Light Values ( NEW )

  GLfloat LightDiffuse[4]= { 1.0f, 1.0f, 1.0f, 1.0f };              // Diffuse Light Values ( NEW )
  GLfloat LightPosition[4]= { 0.0f, 0.0f, 2.0f, 1.0f };                 // Light Position ( NEW )
};

#endif // VISUALIZER_H
