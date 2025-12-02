#pragma once
#include "Vector2.h"

class AABB
{
protected:
	Vector2 _topLeft;
	Vector2 _size;
public:
	AABB(Vector2 topleft, Vector2 size) 
		: _topLeft(topleft), _size(size) { }

	Vector2 const GetTopLeft() { return _topLeft; }
	Vector2 const GetSize() { return _size; }
	void SetTopLeft(Vector2 newTopLeft) { _topLeft = newTopLeft; }
	void SetSize(Vector2 newSize) { _size = newSize; }

	bool CheckOverlappingPoint(Vector2 point);
	bool CheckOverlappingAABB(const AABB* other); // const to avoid modification and errors
};