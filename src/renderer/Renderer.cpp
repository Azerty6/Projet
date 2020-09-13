#include "pch.h"
#include "renderer/Renderer.h"

Renderer::Renderer()
	:Context(SDL_INIT_VIDEO), m_Window(nullptr), m_Renderer(nullptr)
{
	m_Window = SDL_CreateWindow("Render Window",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,600,600,SDL_WindowFlags::SDL_WINDOW_RESIZABLE);
	if(!m_Window)
	{
		std::cerr << "SDL_CreateWindowError : " << SDL_GetError() << std::endl;
	}
	m_Renderer = SDL_CreateRenderer(m_Window,-1,0);
	if(!m_Renderer)
	{
		std::cerr << "SDL_CreateRendererError: " << SDL_GetError() << std::endl;
	}
}

Renderer::~Renderer()
{
	SDL_DestroyWindow(m_Window);
	SDL_DestroyRenderer(m_Renderer);
}

void Renderer::Clear()
{
	SDL_SetRenderDrawColor(m_Renderer,0,0,0,255);
	SDL_RenderClear(m_Renderer);
}

void Renderer::Render()
{
	for(auto& Layer : m_Textures)
	{
		for(auto& texture : Layer)
		{
			SDL_RenderCopy(m_Renderer, texture.m_Texture, nullptr, &texture.m_Rect);
		}
	}
	SDL_RenderPresent(m_Renderer);
}

void Renderer::AddTexture(Texture&& texture, Layer layer)
{
	if(texture.needBinding)
		texture.Bind(m_Renderer);
	m_Textures[layer].emplace_back(texture);
}

void Renderer::AddTexture(const char* dir, size_t x, size_t y, size_t width, size_t height, Layer layer)
{
	m_Textures[layer].emplace_back(Texture(m_Renderer, dir, x, y, width, height));
}

void Renderer::AddMap(const Map& map)
{
	m_Textures[Layer::Background].emplace(m_Textures[Layer::Background].begin() ,Texture(m_Renderer, map.getBackgroundPath().c_str(), 0, 0));
	auto test = map.getMapElements();
	for(size_t i (0); i < test.size(); i++)
	{
		for(size_t k(0); k < test[i].size(); k++)
		{
			m_Textures[Layer::Background].emplace(m_Textures[Layer::Background].end(),
				Texture(m_Renderer,test[i][k]->getTexturePath(),
					test[i][k]->getWidth()*i,test[i][k]->getHeight()*k,
					test[i][k]->getWidth(),test[i][k]->getHeight()
				)
			);
		}
	}
}

void Renderer::RenderPlayer(const Renderable& player)
{
	Texture texture(m_Renderer, player.m_sprite, 
		(int) (player.m_pos.getX()*100), (int)(player.m_pos.getY() * 100), 
		(int)player.m_dim.getWidth(), (int)player.m_dim.getHeight()
	);
	SDL_RenderCopy(m_Renderer, texture.m_Texture, nullptr, &texture.m_Rect);
	SDL_RenderPresent(m_Renderer);
}


