#ifndef CANVAS_H  
#define CANVAS_H  

#include <QGLWidget>  
#include <GL/GL.h>
#include <GL/GLU.h>
#include <gl/glut.h>
#include "global.h"
#include "BallisticScene.h"
#include "Spring.h"
class QTimer;  
class QKeyEvent;  

class GLCanvas : public QGLWidget  
{  
	Q_OBJECT  
public:  
	explicit GLCanvas(QWidget *parent = 0);  

	BallisticScene& getBallisticScene(){return ballisticScene;}
	Spring& getSpring(){return spring;}
	void SetScene(SCENCE scene){this->scene = scene;}
protected:  
	void initializeGL();  
	void resizeGL(int w, int h);  
	void paintGL();  

	void keyPressEvent(QKeyEvent *);  
	void closeEvent(QCloseEvent *);  

	
public Q_SLOTS:
	void updateGL();

private:  
	QTimer *timer;  
	GLfloat left;
	bool fullscreen;  //窗口是否全屏显示  
	BallisticScene ballisticScene;
	Spring spring;
	SCENCE scene;
};  

#endif // MYGLWIDGET_H  