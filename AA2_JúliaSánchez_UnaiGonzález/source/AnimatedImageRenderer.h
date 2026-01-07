#pragma once
#include "ImageRenderer.h"
#include "TimeManager.h"

class AnimatedImageRenderer : public ImageRenderer
{
private:
	int _numFrames, _numColumns;
	int _currentFrame;
	float _frameWidth, _frameHeight;

	bool _looping;
	float _currentFrameTime;
	float _frameDuration;

public:
	AnimatedImageRenderer(Transform* transform, std::string resourcePath, Vector2 sourceOffset, Vector2 sourceSize,
		int numFrames, int numColumns, float frameWidth, float frameHeight, bool looping, float frameDuration)
		: ImageRenderer(transform, resourcePath, sourceOffset, sourceSize),
		_numFrames(numFrames), _numColumns(numColumns), _frameWidth(frameWidth), _frameHeight(frameHeight),
		_looping(looping), _frameDuration(frameDuration), _currentFrameTime(0.f), _currentFrame(0)
	{
		//Mida d'un únic frame (perquè no es vegi tota la spritesheet in-game)
		_sourceRect = SDL_FRect
		{
			sourceOffset.x,
			sourceOffset.y,
			frameWidth,
			frameHeight
		};
	}

	virtual void Update(float dt) override
	{
		_destinationRect.x = _transform->position.x;
		_destinationRect.y = _transform->position.y;

		_destinationRect.w = _sourceRect.w * _transform->scale.x;
		_destinationRect.h = _sourceRect.h * _transform->scale.y;

		//Temps transcorregut des de l'inici del frame
		_currentFrameTime += dt;

		//Si el temps transcorregut és major que la durada màxima d'un frame
		if (_currentFrameTime >= _frameDuration)
		{
			//Passar al següent frame
			_currentFrame++;
			_currentFrameTime = 0;

			//Si l'anterior era l'últim frame
			if (_currentFrame >= _numFrames)
			{
				if (_looping)
				{
					//Reiniciar el cicle de l'animació
					_currentFrame = 0;
				}
				else
				{
					//Quedar-se en l'últim frame
					_currentFrame = _numFrames - 1;
				}
			}

			//Calcular la "cel·la" en la spritesheet del frame actual
			int currentColumn = _currentFrame % _numColumns;
			int currentRow = _currentFrame / _numColumns;

			//Agafar els píxels de la cel·la
			_sourceRect.x = currentColumn * _frameWidth;
			_sourceRect.y = currentRow * _frameHeight;
		}
	}

	virtual void Render() override
	{
		SDL_RenderTextureRotated
		(
			RM->GetRenderer(),
			RM->GetTexture(_resourcePath),
			&_sourceRect,
			&_destinationRect,
			_transform->rotation,
			NULL,
			SDL_FLIP_NONE
		);
	}
};