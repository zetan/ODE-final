#include "TraceBall.h"
using namespace std;
void TraceBall::Draw(){
	glLoadIdentity();
	GLfloat mat_diffuse[] = {0.5, 0.5, 0.5, 1.0};
	GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};  
	GLfloat mat_shininess[] = {50.0};
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);  
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);  
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess); 

	glTranslatef(pos.x, pos.y, pos.z);
	glutSolidSphere(0.5, 016, 16);
}