#include "canvas.h"  
#include <QTimer>  
#include <QKeyEvent>  
#include <QMessageBox>  
#include <QApplication>  
#include <QDebug>  

	GLCanvas::GLCanvas(QWidget *parent) :  
QGLWidget(parent), fullscreen(false)  
{  
	setWindowTitle(tr("nehe----lesson01"));  
	timer = new QTimer(this);  
	connect(timer, SIGNAL(timeout()), this, SLOT(updateGL())); //²»Í£Ë¢ÐÂ´°¿Ú  
	timer->start(20);  
	scene = SCENCE::BALLISTIC;
}  

void GLCanvas::initializeGL()  
{  
	glShadeModel(GL_SMOOTH);   // Enables Smooth Shading  
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);  // Black Background  
	glClearDepth(1.0f);             // Depth Buffer Setup  
	glEnable(GL_DEPTH_TEST);        // Enables Depth Testing  
	glDepthFunc(GL_LEQUAL);        // The Type Of Depth Test To Do  
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); // Really Nice Perspective Calculations  

	GLfloat light_ambient[] = {0.7, 0.7, 0.7, 1.0};
	GLfloat light_position[] = {1.0, 1.0, 5.0, 0.0};  
	GLfloat white_light[] = {1.0, 1.0, 1.0, 1.0};  
	GLfloat lmodel_ambient[] = {1.0, 1.0, 1.0, 1.0};  
	glClearColor(0.0, 0.0, 0.0, 0.0);  
	glShadeModel(GL_SMOOTH);  
	
	glLightfv(GL_LIGHT0,GL_POSITION,light_position); 
	glLightfv(GL_LIGHT0,GL_AMBIENT,light_ambient);  
	glLightfv(GL_LIGHT0,GL_DIFFUSE,white_light);  
	glLightfv(GL_LIGHT0,GL_SPECULAR,white_light);  
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT,lmodel_ambient);  

	glEnable(GL_LIGHTING);  
	glEnable(GL_LIGHT0);  
	glEnable(GL_DEPTH_TEST); 

	ballisticScene.Setup();
}  

void GLCanvas::updateGL(){
	//ballisticScene.Update();
	if(scene == SCENCE::BALLISTIC) ballisticScene.Update();
	if(scene == SCENCE::SPRING) spring.Update();
	//spring.Update();
	update();

}


void GLCanvas::paintGL()  
{  
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);  // Clear The Screen And The Depth Buffer  
	glLoadIdentity();       // Reset The Current Modelview Matrix  

	if(scene == SCENCE::BALLISTIC) ballisticScene.Draw();
	if(scene == SCENCE::SPRING) spring.Draw();

}  


void GLCanvas::resizeGL(int width, int height)  
{  
	if (height==0) {    // Prevent A Divide By Zero By  
		height=1;    // Making Height Equal One  
	}  
	glViewport(0, 0, width, height);    // Reset The Current Viewport  
	glMatrixMode(GL_PROJECTION);       // Select The Projection Matrix  
	glLoadIdentity();                  // Reset The Projection Matrix  

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(140.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);  
	gluLookAt(0.0,10.0,50.0,0.0,0.0,-100.0,0.0,1.0,0.0);
	glMatrixMode(GL_MODELVIEW);      // Select The Modelview Matrix  
	glLoadIdentity();                // Reset The Modelview Matrix 
	
}  


void GLCanvas::keyPressEvent(QKeyEvent *e)  
{  
	
}  
void GLCanvas::closeEvent(QCloseEvent *e)  
{  
	QMessageBox::StandardButton reply;  
	reply = QMessageBox::question(this, "NeHe",  
		"Do you want to exit?",  
		QMessageBox::Yes | QMessageBox::No,  
		QMessageBox::No);  
	if (reply == QMessageBox::Yes) {  
		e->accept();  
	} else {  
		e->ignore();  
	}  

}