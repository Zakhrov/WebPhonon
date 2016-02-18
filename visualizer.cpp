#include "visualizer.h"
#include <QTimer>
#include <QDebug>

Visualizer::Visualizer(QWidget *parent)
    : QGLWidget(parent)
{
    setAcceptDrops(true);
    //setAttribute(Qt::WA_TransparentForMouseEvents);
    setCursor(Qt::BlankCursor);
    setFocus();
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


    GLfloat LightAmbient[4]= { 0.5f, 0.5f, 0.5f, 1.0f };                 // Ambient Light Values ( NEW )

    GLfloat LightDiffuse[4]= { 1.0f, 1.0f, 1.0f, 1.0f };              // Diffuse Light Values ( NEW )
    GLfloat LightPosition[4]= { 0.0f, 0.0f, 2.0f, 1.0f };                 // Light Position ( NEW )
    loadGLTexture();
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glShadeModel(GL_SMOOTH);
    glDepthFunc(GL_LEQUAL);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glLightfv(GL_LIGHT1, GL_AMBIENT, LightAmbient);             // Setup The Ambient Light
    glLightfv(GL_LIGHT1, GL_DIFFUSE, LightDiffuse);             // Setup The Diffuse Light
    glLightfv(GL_LIGHT1, GL_POSITION,LightPosition);            // Position The Light
    glEnable(GL_LIGHT1);
    glColor4f(1.0f,1.0f,1.0f,0.5f);         // Full Brightness, 50% Alpha ( NEW )
    glBlendFunc(GL_SRC_ALPHA,GL_ONE);
    glEnable(GL_BLEND);

}

void Visualizer::paintGL()
{

    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0f,0.0f,-10.0f);
    glRotatef(xRot, 0.0, 0.0, 1.0);
    glRotatef(yRot,0.0f,1.0f,0.0f);
    //glRotatef(zRot,0.0f,0.0f,1.0f);
    glBindTexture(GL_TEXTURE_2D, texture[0]);
      /*glBegin(GL_TRIANGLES);
      glColor3f(1,0,0);
        glVertex3f( 0.0f, 1.0f, 0.0f);
        glColor3f(0,1,0);
        glVertex3f(-1.0f,-1.0f, 1.0f);
        glColor3f(0,0,1);
        glVertex3f( 1.0f,-1.0f, 1.0f);
        glColor3f(1.0f,0.0f,0.0f);          // Red
        glVertex3f( 0.0f, 1.0f, 0.0f);          // Top Of Triangle (Right)
        glColor3f(0.0f,0.0f,1.0f);          // Blue
        glVertex3f( 1.0f,-1.0f, 1.0f);          // Left Of Triangle (Right)
        glColor3f(0.0f,1.0f,0.0f);          // Green
        glVertex3f( 1.0f,-1.0f, -1.0f);         // Right Of Triangle (Right)
        glColor3f(1.0f,0.0f,0.0f);          // Red
        glVertex3f( 0.0f, 1.0f, 0.0f);          // Top Of Triangle (Back)
        glColor3f(0.0f,1.0f,0.0f);          // Green
        glVertex3f( 1.0f,-1.0f, -1.0f);         // Left Of Triangle (Back)
        glColor3f(0.0f,0.0f,1.0f);          // Blue
        glVertex3f(-1.0f,-1.0f, -1.0f);         // Right Of Triangle (Back)
        glColor3f(1.0f,0.0f,0.0f);          // Red
          glVertex3f( 0.0f, 1.0f, 0.0f);          // Top Of Triangle (Left)
          glColor3f(0.0f,0.0f,1.0f);          // Blue
          glVertex3f(-1.0f,-1.0f,-1.0f);          // Left Of Triangle (Left)
          glColor3f(0.0f,1.0f,0.0f);          // Green
          glVertex3f(-1.0f,-1.0f, 1.0f);          // Right Of Triangle (Left)
      glEnd();*/
    glBegin(GL_QUADS);
        // Front Face
        glNormal3f( 0.0f, 0.0f, 1.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);  // Top Right Of The Texture and Quad
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);  // Top Left Of The Texture and Quad
        // Back Face
        glNormal3f( 0.0f, 0.0f,-1.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  // Bottom Right Of The Texture and Quad
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);  // Top Right Of The Texture and Quad
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);  // Top Left Of The Texture and Quad
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);  // Bottom Left Of The Texture and Quad
        // Top Face
        glNormal3f( 0.0f, 1.0f, 0.0f);
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);  // Top Left Of The Texture and Quad
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f,  1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f,  1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);  // Top Right Of The Texture and Quad
        // Bottom Face
        glNormal3f( 0.0f,-1.0f, 0.0f);
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  // Top Right Of The Texture and Quad
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f, -1.0f, -1.0f);  // Top Left Of The Texture and Quad
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
        // Right face
        glNormal3f( 1.0f, 0.0f, 0.0f);
        glTexCoord2f(1.0f, 0.0f); glVertex3f( 1.0f, -1.0f, -1.0f);  // Bottom Right Of The Texture and Quad
        glTexCoord2f(1.0f, 1.0f); glVertex3f( 1.0f,  1.0f, -1.0f);  // Top Right Of The Texture and Quad
        glTexCoord2f(0.0f, 1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);  // Top Left Of The Texture and Quad
        glTexCoord2f(0.0f, 0.0f); glVertex3f( 1.0f, -1.0f,  1.0f);  // Bottom Left Of The Texture and Quad
        // Left Face
        glNormal3f(-1.0f, 0.0f, 0.0f);
        glTexCoord2f(0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, -1.0f);  // Bottom Left Of The Texture and Quad
        glTexCoord2f(1.0f, 0.0f); glVertex3f(-1.0f, -1.0f,  1.0f);  // Bottom Right Of The Texture and Quad
        glTexCoord2f(1.0f, 1.0f); glVertex3f(-1.0f,  1.0f,  1.0f);  // Top Right Of The Texture and Quad
        glTexCoord2f(0.0f, 1.0f); glVertex3f(-1.0f,  1.0f, -1.0f);  // Top Left Of The Texture and Quad
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

void Visualizer::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasUrls())
        event->acceptProposedAction();
}

void Visualizer::dragMoveEvent(QDragMoveEvent *event)
{
  event->acceptProposedAction();
}

void Visualizer::dropEvent(QDropEvent *event)
{
    if(event->mimeData()->hasUrls())
        emit geturls(event->mimeData());
}

void Visualizer::animate()
{
#ifdef Q_OS_LINUX
    xRot+=0.4f;
    yRot-=4.0f;
#else
    xRot+=0.2f;
    yRot-=0.2f;
#endif
   // zRot-=4.0f;
    updateGL();
}

void Visualizer::loadGLTexture()
{
    QImage t;
      QImage b;
#ifdef Q_OS_LINUX

        if(!b.load(":/splash/WebPhonon-Master-text2.png","PNG"))
        qDebug() <<"Image not loaded";
#else
      if(!b.load( ":/texture/texture.jpg","JPEG" ))
      qDebug() <<"Image not loaded";
#endif
      t = QGLWidget::convertToGLFormat( b );
      glGenTextures( 1, &texture[0] );
      glBindTexture( GL_TEXTURE_2D, texture[0] );
      glTexImage2D( GL_TEXTURE_2D, 0, 3, t.width(), t.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, t.bits() );
      glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
      glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
}
