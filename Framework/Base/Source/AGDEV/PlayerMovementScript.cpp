#include "PlayerMovementScript.h"
#include "../Input/InputManager.h"
#include "../GameObject/GameObject.h"
#include "../Component/Physics/Transform.h"

//Constructor(s) & Destructor
PlayerMovementScript::PlayerMovementScript(GameObject& gameObject) : Script(gameObject) {
	movementSpeed = 5.0f;
	rotationSpeed = 60.0f;
}

PlayerMovementScript::~PlayerMovementScript() {
}

//Interface Function(s)
void PlayerMovementScript::Update(double deltaTime) {
	Transform& transform = GetGameObject().GetComponent<Transform>();
	if(InputManager::GetInstance().GetInputInfo().keyDown[INPUT_MOVE_LEFT]) {
		transform.Translate(movementSpeed * deltaTime * transform.GetLeft());
	}
	if(InputManager::GetInstance().GetInputInfo().keyDown[INPUT_MOVE_RIGHT]) {
		transform.Translate(movementSpeed * deltaTime * -transform.GetLeft());
	}
	if(InputManager::GetInstance().GetInputInfo().keyDown[INPUT_MOVE_FORWARD]) {
		transform.Translate(movementSpeed * deltaTime * transform.GetForward());
	}
	if(InputManager::GetInstance().GetInputInfo().keyDown[INPUT_MOVE_BACKWARD]) {
		transform.Translate(movementSpeed * deltaTime * -transform.GetForward());
	}
	if(InputManager::GetInstance().GetInputInfo().keyDown[INPUT_LOOK_LEFT]) {
		transform.Rotate(0,deltaTime * rotationSpeed, 0);
	}
	if(InputManager::GetInstance().GetInputInfo().keyDown[INPUT_LOOK_RIGHT]) {
		transform.Rotate(0,-deltaTime * rotationSpeed, 0);
	}
	if(InputManager::GetInstance().GetInputInfo().keyDown[INPUT_ROLL_LEFT]) {
		//transform.Rotate(0, 0, -deltaTime * rotationSpeed);
	}
	if(InputManager::GetInstance().GetInputInfo().keyDown[INPUT_ROLL_RIGHT]) {
		//transform.Rotate(0, 0, deltaTime * rotationSpeed);
	}
}