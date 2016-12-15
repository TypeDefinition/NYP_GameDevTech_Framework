#include "PlayerMovementScript.h"
#include "../Input/InputManager.h"
#include "../GameObject/GameObject.h"
#include "../Component/Physics/Transform.h"

//Constructor(s) & Destructor
PlayerMovementScript::PlayerMovementScript(GameObject& gameObject) : Script(gameObject) {
	movementSpeed = 5.0f;
	rotationSpeed = 80.0f;
}

PlayerMovementScript::~PlayerMovementScript() {
}

//Interface Function(s)
void PlayerMovementScript::Update(double deltaTime) {
	Transform& transform = GetGameObject().GetComponent<Transform>();	
	transform.Rotate(0, rotationSpeed * InputManager::GetInstance().GetInputInfo().axis[IAXIS_LOOK_HORIZONTAL], 0);
	if(InputManager::GetInstance().GetInputInfo().keyDown[INPUT_MOVE_LEFT]) {
		transform.Translate(movementSpeed * deltaTime * transform.GetLocalLeft());
	}
	if(InputManager::GetInstance().GetInputInfo().keyDown[INPUT_MOVE_RIGHT]) {
		transform.Translate(movementSpeed * deltaTime * -transform.GetLocalLeft());
	}
	if(InputManager::GetInstance().GetInputInfo().keyDown[INPUT_MOVE_FORWARD]) {
		transform.Translate(movementSpeed * deltaTime * transform.GetLocalForward());
	}
	if(InputManager::GetInstance().GetInputInfo().keyDown[INPUT_MOVE_BACKWARD]) {
		transform.Translate(movementSpeed * deltaTime * -transform.GetLocalForward());
	}
	if(InputManager::GetInstance().GetInputInfo().keyDown[INPUT_LOOK_LEFT]) {
		transform.Rotate(0,deltaTime * rotationSpeed, 0);
	}
	if(InputManager::GetInstance().GetInputInfo().keyDown[INPUT_LOOK_RIGHT]) {
		transform.Rotate(0,-deltaTime * rotationSpeed, 0);
	}
}