#include "BallisticScene.h"

using namespace std;

void BallisticScene::Setup(){

}

void BallisticScene::Update(){
	if(status == STATUS::PLAY){
		ball.Update();
		TraceBall trace;
		trace.setPos(ball.getPos());
//		trace.setPos(ball.getPos().x, 0, ball.getPos().z);
		traceBallVec.push_back(trace);

	}
}

void BallisticScene::Draw(){
	
	ball.Draw();
	for(int i = 0; i < traceBallVec.size(); i++){
		traceBallVec[i].Draw();
	}
	floor.Draw();
}

void BallisticScene::StartPlay(){
	//init the status
	status = STATUS::PLAY;
	traceBallVec.clear();
}

void BallisticScene::StopPlay(){
	status = STATUS::NONE;
}