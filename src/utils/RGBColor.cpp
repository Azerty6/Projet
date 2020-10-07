#include "pch.h"

#include "utils/RGBColor.h"

bool RGBColor::operator==(RGBColor color)
{
	return ( (R == color.R) && (G == color.G) && (B == color.B) );
}

RGBColor getPixelColor(SDL_Surface* surface, size_t x, size_t y)
{
    RGBColor color;
<<<<<<< HEAD
    // std::cout << "debut" << ((Uint32*) surface->pixels)[y * surface->w + x] << "fin" << std::endl;
=======
    //std::cout << "debut" << ((Uint32*) surface->pixels)[y * surface->w + x] << "fin" << std::endl;
>>>>>>> 06f8ee50cbadb0cf80fdaa2b79155d4a991c05ca
    /*void* test;
    memcpy(test, surface->pixels, surface->pitch * surface->h);
    std::cout << *test << std::endl;*/
    Uint8 alpha;
    SDL_GetRGBA(((Uint32*) surface->pixels)[y * surface->w + x], surface->format, &color.R, &color.G, &color.B, &alpha);
    return color;
    char* ptr;
    memset(ptr, 0xFFFF, 2);
}
