#include "stdafx.h"
#include "BackGround.h"
BackGround::BackGround()
{
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();

	modelRender.Init("Assets/modelData/stage/Stage.tkm");
	modelRender.SetScale(25.0f, 0.0f, 25.0f);//サイズ変更（ｘ、ｙ、ｚ）
	modelRender.Update();
	physicsStaticObject.CreateFromModel(modelRender.GetModel(), modelRender.GetModel().GetWorldMatrix());
}

BackGround::~BackGround()
{

}

void BackGround::Render(RenderContext& rc)
{
	modelRender.Draw(rc);
}