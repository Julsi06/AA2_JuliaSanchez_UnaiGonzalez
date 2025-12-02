#pragma once
#include "Vector2.h"

class Transform
{
public:
	Vector2 position;
	float rotation;
	Vector2 scale; // A multiplier that can be used to change the size of the object
	Vector2 size; // The number of pixels of the object

	Transform() 
		: position(Vector2(0.0f, 0.0f)), rotation(0.0f), 
		scale(Vector2(1.0f, 1.0f)), size(Vector2(100.0f, 100.0f)) { }

	Transform(Vector2 _position, float _rotation, Vector2 _scale, Vector2 _size)
		: position(_position), rotation(_rotation), scale(_scale), size(_size) { }
};