#include "ball.h"

Ball::Ball(){
	pos.x = 0;
	pos.y = 10;
	pos.z = 0;
	velocity.x = 30;
	velocity.y = 10;
	velocity.z = 10;

	gravity.x = 0;
	gravity.y = -10;
	gravity.z = 0;

	method = METHOD::EULAR;
}

void Ball::Draw(){
	glLoadIdentity();
	GLfloat mat_diffuse[] = {0.4, 0.4, 1.0, 1.0};
	GLfloat mat_specular[] = {1.0, 1.0, 1.0, 1.0};  
	GLfloat mat_shininess[] = {50.0};
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse);  
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular);  
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess); 
	glPushMatrix();
	glTranslatef(pos.x, pos.y, pos.z);
	glutSolidSphere(3, 016, 16);
	//glTranslatef(-pos.x, -pos.y, -pos.z);
	glPopMatrix();
	DrawText();
	
}

void Ball::DrawText(){
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


void Ball::Update(){
	if(method == METHOD::EULAR) Eular();
	if(method == METHOD::MIDPOINT) MidPoint();
	//Eular();
}


void Ball::Eular(){
	GLfloat t = 0.1f;
	GLfloat air = -0.1f;
//	clock_t  clockBegin, clockEnd;  
//	clockBegin = clock();  
//	for(int i = 0; i < 10000; i++){
		Vector3D a = Vector3D::Add(Vector3D::Scale(velocity,air), gravity);
		pos = Vector3D::Add(pos, Vector3D::Scale(velocity, t));
		velocity =  Vector3D::Add(velocity,  Vector3D::Scale(a, t));
		if(pos.y < 0 && velocity.y < 0) {
			velocity.y = - velocity.y;
			velocity = Vector3D::Scale(velocity,0.5);
		}
//	}
	
//	clockEnd = clock();  
//	qDebug()<<(clockEnd-clockBegin);
	//qDebug("velocity.y = " + (int) velocity.y);
}

void Ball::MidPoint(){
	GLfloat t = 0.1f;
	GLfloat air = -0.1f;
//	clock_t  clockBegin, clockEnd;  
//	clockBegin = clock();  
	Vector3D eularA = Vector3D::Add(Vector3D::Scale(velocity,air), gravity);
	Vector3D eularPos = Vector3D::Add(pos, Vector3D::Scale(velocity, t));
	Vector3D eularV =  Vector3D::Add(velocity,  Vector3D::Scale(eularA, t));

//	Vector3D midPos = Vector3D::Scale(Vector3D::Add(pos, eularPos), 0.5f);
	Vector3D midV =  Vector3D::Scale(Vector3D::Add(velocity, eularV), 0.5f);

	Vector3D midA = Vector3D::Add(Vector3D::Scale(midV,air), gravity);
	pos = Vector3D::Add(pos, Vector3D::Scale(velocity, t));
	velocity =  Vector3D::Add(velocity,  Vector3D::Scale(midA, t));

	if(pos.y < 0 && velocity.y < 0) {
		velocity.y = - velocity.y * 0.5;
		//velocity = Vector3D::Scale(velocity,0.5);
	}

//	clockEnd = clock();  
//	qDebug()<<(clockEnd-clockBegin);
//	qDebug()<<pos.y;
}

