#include "ImageRenderer.h"

ImageRenderer::ImageRenderer(Transform* transform, std::string resourcePath, Vector2 sourceOffset, Vector2 sourceSize)
	: Renderer(transform, resourcePath)
{
	RM->GetTexture(resourcePath);

	// Gets the measurements from the source image/texture
	_sourceRect = SDL_FRect
	{
		sourceOffset.x,
		sourceOffset.y,
		sourceSize.x,
		sourceSize.y
	};

	// Sets where the texture will be placed in the transform (of the image object)
	_destinationRect = SDL_FRect
	{
		transform->position.x,
		transform->position.y,
		transform->scale.x,
		transform->scale.y
	};
}

void ImageRenderer::Update(float dt)
{
	Vector2 offset;
	offset.x = (_transform->size.x / 2.0f) * _transform->scale.x;
	offset.y = (_transform->size.y / 2.0f) * _transform->scale.y;

	_destinationRect.x = _transform->position.x + offset.x;
	_destinationRect.y = _transform->position.y + offset.y;

	_destinationRect.w = _transform->size.x * _transform->scale.x;
	_destinationRect.h = _transform->size.y * _transform->scale.y;
}

void ImageRenderer::Render()
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
