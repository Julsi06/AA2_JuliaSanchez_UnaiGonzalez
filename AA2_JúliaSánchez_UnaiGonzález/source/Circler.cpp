#include "Circler.h"

void Circler::Update()
{
	_positionHistory.push_front(_transform->position);

	if (_positionHistory.size() > _trailSize * _segmentSpacing)
		_positionHistory.pop_back();

	for (int i = 0; i < _trail.size(); i++)
	{
		int index = i * _segmentSpacing;

		if (index < _positionHistory.size())
		{
			_trail[i]->GetTransform()->position = _positionHistory[index];
		}
	}

	Enemy::Update();
}
