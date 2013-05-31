#include "Floor.h"

void Floor::Update(){

}

void Floor::Draw(){
	glLoadIdentity();
	GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};  
	GLfloat mat_shininess[] = {50.0};
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);  
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
	glLineWidth(1.0);
	for(int i = -200; i < 200; i=i+10){
		glBegin(GL_LINES);
		glVertex3f(-200, 0,i);
		glVertex3f(200, 0,i);
		glEnd();
		glBegin(GL_LINES);
		glVertex3f(i, 0,-200);
		glVertex3f(i, 0,200);
		glEnd();
	}
	
	
}