#include "ode.h"

ODE::ODE(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	canvas = new GLCanvas(ui.centralWidget);
	canvas->setGeometry(0,0, 800, 600);
}

ODE::~ODE()
{

}


void ODE::BallStartPlay(){
	int height = ui.gunHeight->value();
	canvas->getBallisticScene().SetBallHeight(height);
	int mass = ui.ballMassBox->value();
	int powder = ui.ballPowerAmountMass->value();
	if(mass != 0){
		GLfloat velocity = powder * 10000 / mass * 0.1;//t=0.1
		float xz = ui.ballVxBox->value();
		float y = ui.ballVyBox->value();
		float vy = velocity * sin(y*3.14/180);
		float vx = velocity * cos(y*3.14/180) * cos(xz*3.14/180);
		float vz = velocity * cos(y*3.14/180) * sin(xz*3.14/180);
		canvas->getBallisticScene().SetBallVelocity(vx, vy, vz);
	}
	if(ui.ballEularRadio->isChecked() == true) canvas->getBallisticScene().SetBallMethod(METHOD::EULAR);
	if(ui.ballMidPointRadio->isChecked() == true) canvas->getBallisticScene().SetBallMethod(METHOD::MIDPOINT);

	canvas->getBallisticScene().StartPlay();
	canvas->SetScene(SCENCE::BALLISTIC);
}

void ODE::BallStopPlay(){
	canvas->getBallisticScene().StopPlay();
}

void ODE::SpringStartPlay(){
	int mass = ui.SpringMassBox->value();
	canvas->getSpring().SetMass(mass);
	int k = ui.springStiffBox->value();
	canvas->getSpring().SetK(k);
	if(ui.springEularRadio->isChecked() == true) canvas->getSpring().SetMethod(METHOD::EULAR);
	if(ui.springMidPointRadio->isChecked() == true) canvas->getSpring().SetMethod(METHOD::MIDPOINT);
	canvas->getSpring().StartPlay();
	canvas->SetScene(SCENCE::SPRING);
}

void ODE::SpringStopPlay(){
	canvas->getSpring().StopPlay();
}