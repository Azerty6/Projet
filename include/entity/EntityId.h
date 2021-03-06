#pragma once

#define MAP_ELEMENT_COLOR(id) (id << 16)
#define MOVABLE_ENTITY_COLOR(id) (id << 8)
#define INTERACTABLE_COLOR(id) (id)

#define GET_COLOR_OF_MAP_ELEMENT(id) ((id >> 16) & 0xFF)
#define GET_COLOR_OF_MOVABLE_ENTITY(id) ((id >> 8) & 0xFF)
#define GET_COLOR_OF_INTERACTABLE(id) (id & 0xFF)

enum class EntityId {
	None = 0,
	WallMapElement = MAP_ELEMENT_COLOR(100U),
	EmptyMapElement = MAP_ELEMENT_COLOR(255U),
	Player = MOVABLE_ENTITY_COLOR(255U),
};
