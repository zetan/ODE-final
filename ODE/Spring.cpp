#include "Spring.h"


Spring::Spring(){
	status = STATUS::NONE;
	method = METHOD::EULAR;
	orgLength = 60;
	curLength = orgLength;//+2;
	mass = 5;
	k = 15;
	gravity = -10;
	//gravity = 0;
	velocity = 0;
}

void Spring::Update(){
	if(status == STATUS::PLAY){
		if(method == METHOD::EULAR) Eular();
		if(method == METHOD::MIDPOINT) MidPoint();
	}
}

void Spring::Draw(){
	glLoadIdentity();
/*	GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};  
	GLfloat mat_shininess[] = {50.0};
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);  
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess);
*/	
		glColor3f(1.0f,1.0f,1.0f);
		glLineWidth(3.0f);
		GLfloat ceiling = 20.0f;
		//ceiling
		glBegin(GL_LINES);
		glVertex3f(-20, ceiling,0);
		glVertex3f(20, ceiling,0);
		glEnd();
		for(int i = -20; i < 20; i+=5){
			glBegin(GL_LINES);
			glVertex3f(i, ceiling,0);
			glVertex3f(i+5, ceiling+4,0);
			glEnd();
		}
		//spring
		int segment = 10;
		for(int i = 0; i < segment; i++){
			GLfloat start = curLength / segment * i;
			GLfloat end = curLength / segment * (i+1);
			GLfloat x1, x2;
			if(i%2 == 0){
				x1 = 5;
				x2 = -5;
			}else{
				x1 = -5;
				x2 = 5;
			}
			if(i == 0) x1 = 0;
			if(i == segment-1) x2 = 0;
			glBegin(GL_LINES);
			glVertex3f(x1, ceiling-start,0);
			glVertex3f(x2, ceiling-end,0);
			glEnd();
			
		}

		glLoadIdentity();
		GLfloat mat_diffuse[] = {0.4, 0.4, 1.0, 1.0};
		GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};  
		GLfloat mat_shininess[] = {50.0};
		glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);  
		glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);  
		glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess); 
		glPushMatrix();
		glTranslatef(0, ceiling-curLength-2,0);
		glutSolidSphere(4, 16, 16);

		DrawText();
}

void Spring::Eular(){
	/*	clock_t  clockBegin, clockEnd;  
		clockBegin = clock();  
		for(int i = 0; i < 10000; i++){*/
	GLfloat pull = mass * gravity;
	GLfloat springForce  = (curLength - orgLength) * k;
	GLfloat force = pull + springForce;

	GLfloat t = 0.02f;
	curLength += -1 * (t * velocity);
	velocity += t * force;

	/*	}
		clockEnd = clock();  
		qDebug()<<(clockEnd-clockBegin);*/
	//qDebug()<<curLength;
}

void Spring::MidPoint(){
	/*clock_t  clockBegin, clockEnd;  
	clockBegin = clock();  
	for(int i = 0; i < 10000; i++){*/

	GLfloat pull = mass * gravity;
	GLfloat eularSpringForce  = (curLength - orgLength) * k;
	GLfloat eularForce = pull + eularSpringForce;

	GLfloat t = 0.02f;
	GLfloat eularLength = curLength - 1 * (t * velocity);
	GLfloat midLength = (curLength + eularLength)/2;

	GLfloat midSpringForce = (midLength - orgLength) * k;
	GLfloat midForce = pull + midSpringForce;

	curLength += -1 * (t * velocity);
	velocity += t * midForce;
//	}
	//clockEnd = clock();  
	//qDebug()<<(clockEnd-clockBegin);
	////qDebug()<<curLength;
}

void Spring::StartPlay(){
	//init the status
	velocity = 0;
	curLength = orgLength;
	status = STATUS::PLAY;
}

void Spring::StopPlay(){
	status = STATUS::NONE;
}

void Spring::DrawText(){
	char* text = "Method: ";
	if(method == METHOD::EULAR) text = "Method: Eular";
	if(method == METHOD::MIDPOINT) text = "Method: Mid Point";
	glLoadIdentity();
	int strlength = (int)strlen(text);
	glPushMatrix();
	glTranslatef(-150, 100, 0.0);
	glColor3f(1.0, 1.0, 1.0);
	glScalef(0.06f,0.06f,1);
	glLineWidth(3.0);
	for (int i = 0; i < strlength; i++)
	{
		glTranslatef(i*5+((strlength - i)*(strlength - i)*0.5), 0, 0.0);
		glutStrokeCharacter(GLUT_STROKE_ROMAN, text[i]);
	}
	glPopMatrix();
}