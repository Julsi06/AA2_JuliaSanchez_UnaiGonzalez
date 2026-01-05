#pragma once
#include "ImageObject.h"
#include <functional>

class Button : public ImageObject
{
public:
	typedef std::function<void()> OnClick;

	Button(Vector2 startPos, OnClick onClick)
		: ImageObject("resources/images/button.png", Vector2(0.0f, 0.0f), Vector2(966.0f, 350.0f))
	{
		_onClick = onClick;

		_transform->position = startPos;
		_transform->size = Vector2(450.0f, 200.0f);

		_physics->AddCollider(new AABB(_transform->position, _transform->size));
	}
	virtual void Update() override;
	virtual void Render() override { Object::Render(); }
	void OnCollisionEnter(Object* other) { }
private:
	bool _isHovered = false;
	OnClick _onClick;

	void OnHoverEnter();
	void OnHoverExit();
	void OnClicked() { _onClick(); }
};