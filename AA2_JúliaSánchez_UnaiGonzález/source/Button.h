#pragma once
#include "ImageObject.h"
#include <functional>

class Button : public ImageObject
{
public:
	typedef std::function<void()> OnClick;

	Button(OnClick onClick)
		: ImageObject("resources/xd.png", Vector2(0.0f, 0.0f), Vector2(306.0f, 562.0f))
	{
		_onClick = onClick;

		// Test
		_transform->position = Vector2(100.0f, 100.0f);
		_transform->scale = Vector2(1.0f, 1.0f);

		_physics->AddCollider(new AABB(_transform->position, _transform->size));
	}
	virtual void Update() override;
	virtual void Render() override { Object::Render(); }
private:
	bool _isHovered = false;
	OnClick _onClick;

	void OnHoverEnter();
	void OnHoverExit();
	void OnClicked() { _onClick(); }
};