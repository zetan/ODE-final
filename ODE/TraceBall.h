#ifndef TRACEBALL_H
#define TRACEBALL_H
#include "Vector3D.h"
#include <QGLWidget> 
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glut.h>
#include "ball.h"
class TraceBall: public Ball{
public:
	TraceBall(){}
	~TraceBall(){}
	void Draw();
};
#endif