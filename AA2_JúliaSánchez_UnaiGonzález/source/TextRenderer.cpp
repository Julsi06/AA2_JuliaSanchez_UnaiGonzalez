#include "TextRenderer.h"
#include "RenderManager.h"

void TextRenderer::Update(float dt)
{
	Vector2 offset = (Vector2(-_transform->size.x, -_transform->size.y) / 2.0f) * _transform->scale;

	_destinationRect.x = _transform->position.x + offset.x;
	_destinationRect.y = _transform->position.y + offset.y;

	if (_autoSize)
	{
		_destinationRect.w = _sourceRect.w * _transform->scale.x;
		_destinationRect.h = _sourceRect.h * _transform->scale.y;
	}
	else
	{
		_destinationRect.w = _transform->size.x * _transform->scale.x;
		_destinationRect.h = _transform->size.y * _transform->scale.y;
	}
}

void TextRenderer::Render()
{
	SDL_RenderTextureRotated(
		RM->GetRenderer(),
		_textTexture,
		&_sourceRect,
		&_destinationRect,
		_transform->rotation,
		NULL,
		SDL_FLIP_NONE
	);
}

void TextRenderer::SetText(std::string text)
{
	if (_textTexture != nullptr)
		SDL_DestroyTexture(_textTexture);

	SDL_Surface* surface = TTF_RenderText_Solid(
		RM->GetFont(_resourcePath),
		text.c_str(),
		text.length(),
		_color
	);
	assert(surface);

	_textTexture = SDL_CreateTextureFromSurface(RM->GetRenderer(), surface);
	assert(_textTexture);

	_sourceRect = { 0.0f, 0.0f, (float)surface->w, (float)surface->h };

	_text = text;
}