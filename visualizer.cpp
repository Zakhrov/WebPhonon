#include "visualizer.h"
#include <QTimer>

Visualizer::Visualizer(QWidget *parent)
    : QGLWidget(parent)
{
         xRot = 0;
         yRot = 0;
         zRot = 0;
         timer=new QTimer(this);
         timer->setInterval(1);
         connect(timer,SIGNAL(timeout()),this,SLOT(animate()));
         timer->start();




}

Visualizer::~Visualizer()
{

}

void Visualizer::initializeGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glShadeModel(GL_SMOOTH);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

}

void Visualizer::paintGL()
{



    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f,0.0f,-6.0f);
    glRotatef(xRot, 0.0, 0.0, 1.0);
      glBegin(GL_TRIANGLES);
      glColor3f(1,0,0);
        glVertex3f( 0.0f, 1.0f, 0.0f);
        glColor3f(0,1,0);
        glVertex3f(-1.0f,-1.0f, 0.0f);
        glColor3f(0,0,1);
        glVertex3f( 1.0f,-1.0f, 0.0f);
      glEnd();

}

void Visualizer::resizeGL(int w, int h)
{
    glViewport( 0, 0, (GLint)w, (GLint)h );
       glMatrixMode( GL_PROJECTION );
       glLoadIdentity();
       glFrustum( -1.0, 1.0, -1.0, 1.0, 5.0, 15.0 );
       glMatrixMode( GL_MODELVIEW );
}

void Visualizer::animate()
{
    xRot+=10;
    updateGL();
}
