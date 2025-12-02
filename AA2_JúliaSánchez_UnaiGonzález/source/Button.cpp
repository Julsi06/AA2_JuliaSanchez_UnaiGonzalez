#include "Button.h"
#include "InputManager.h"

void Button::Update()
{
	if (!_isHovered && _physics->CheckOverlappingPoint(
		{ (float)IM->GetMouseX(), (float)IM->GetMouseY() }))
		OnHoverEnter();

	else if (_isHovered && !_physics->CheckOverlappingPoint(
		{ (float)IM->GetMouseX(), (float)IM->GetMouseY() }))
		OnHoverExit();

	else if (_isHovered && IM->GetLeftClick())
		OnClicked();

	Object::Update();
}

void Button::OnHoverEnter()
{
	// Only rotates to visually check if the button's selected state is being selected
	_transform->rotation = 90.0f;
	_isHovered = true;
}

void Button::OnHoverExit()
{
	_transform->rotation = 0.0f;
	_isHovered = false;
}
