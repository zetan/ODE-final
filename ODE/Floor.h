#ifndef FLOOR_H
#define FLOOR_H
#include <QGLWidget> 
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glut.h>
class Floor{
public:
	Floor(){}
	~Floor(){}
	void Update();
	void Draw();
};
#endif