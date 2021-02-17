#include "pch.h"

#include "map/elements/EmptyMapElement.h"

EmptyMapElement::EmptyMapElement(Position<float> position)
	:MapElement("assets/textures/empty_map_element.png", position, {1.0f, 1.0f})
{
	MapElement::mapElementType = MapElementType::EmptyMapElement;
}

EmptyMapElement::~EmptyMapElement()
{}

bool EmptyMapElement::operator()(Entity& entity)
{
	return true;
}
