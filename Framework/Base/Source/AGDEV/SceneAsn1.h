#ifndef SCENE_ASN1_H
#define SCENE_ASN1_H

#include "../Scene/Scene.h"
#include "../Graphics/RenderHelper.h"
#include "../GameObject/GameObjectFactory.h"
#include "../Others/Skybox.h"

class SceneAsn1 : public Scene {

private:
	//Variable(s)
	GameObject* player;
	Skybox skybox;

public:
	//Constructor(s) & Destructor
	SceneAsn1(const string& name);
	virtual ~SceneAsn1();
	
	//Virtual Function(s)
	virtual void Init();
	virtual void Save() {}
	virtual void Load() {}
	virtual void Update(double _deltaTime);
	virtual void Render();
	virtual void Exit();

	//Temporary Stuff
	float debugCountdown = 3.0f;
};

#endif