#include "TextRenderer.h"
#include "../ComponentManager.h"

//Constructor(s) & Destructor
TextRenderer::TextRenderer(GameObject& _gameObject, PassKey<ComponentManager> _key) : Component("Text Renderer", _gameObject, _key) {
	mesh = nullptr;
	lightEnabled = false;
	textColor.Set(0, 0, 0);
}

TextRenderer::~TextRenderer() {
}