#ifndef SPRING_H
#define SPRING_H
#include "Vector3D.h"
#include "global.h"
#include <time.h>
#include <QGLWidget> 
#include <gl/GL.h>
#include <gl/GLU.h>
#include <gl/glut.h>
#include <QDebug>
class Spring{ //a spring with a box at bottom
public:
	Spring();
	~Spring(){}
	void Update();
	void Draw();

	void StartPlay();
	void StopPlay();

	void SetMass(GLfloat mass){ this->mass = mass;}
	void SetK(GLfloat k){this->k = k;}
	void SetMethod(METHOD method){this->method = method;}
private:
	void DrawText();

	STATUS status;
	METHOD method;
	void Eular();
	void MidPoint();
	GLfloat gravity;
	GLfloat velocity;
	GLfloat k;
	GLfloat mass;
	GLfloat orgLength;
	GLfloat curLength;
};
#endif