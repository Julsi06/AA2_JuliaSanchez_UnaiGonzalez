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
	_isHovered = true;
}

void Button::OnHoverExit()
{
	_isHovered = false;
}
