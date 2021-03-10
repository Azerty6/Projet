#include "pch.h"

#include "renderer/Texture.h"
#include "renderer/TextureManager.h"

Texture::Texture(const Position<float>* _position, const Dimension<float>* _size, SDL_Texture* _texture, void* _texture_info)
	:position(_position), size(_size), texture(_texture), texture_info(_texture_info), src_rect{0, 0, static_cast<int>(_size->getWidth()), static_cast<int>(_size->getHeight())}
{
}

Texture::~Texture()
{
	position = nullptr;
	size = nullptr;
	texture = nullptr;
	texture_path = nullptr;
	texture_info = nullptr;
}

Position<int> Texture::ComputeActualPosition(Dimension<int> mapSize, Dimension<int> windowSize) const
{
	return Position<int>(std::ceil(position->getX() * windowSize.getWidth() / mapSize.getWidth()),
							std::ceil(position->getY() * windowSize.getHeight() / mapSize.getHeight()));
}

Dimension<int> Texture::ComputeActualSize(Dimension<int> mapSize, Dimension<int> windowSize) const
{
	return Dimension<int>(std::ceil(size->getWidth() * windowSize.getWidth() / mapSize.getWidth()),
							std::ceil(size->getHeight() * windowSize.getHeight() / mapSize.getHeight()));
}

SDL_Rect* Texture::ComputeActualSrcRect() const
{
	if(texture_info) {
		TextureInfo* info = (TextureInfo*)texture_info;
		src_rect.w = info->offsetx;
		src_rect.h = info->offsety;
		src_rect.y = 0;
		src_rect.x = info->current_frame * info->offsetx;
		return &src_rect;
	} else {
		return nullptr;
	}
}
