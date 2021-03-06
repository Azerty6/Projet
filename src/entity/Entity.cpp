#include "pch.h"

#include "entity/Entity.h"
#include "entity/EntityManager.h"

Entity::Entity(float _x, float _y)
	:m_ID(EntityManager::GetNewID(this)), m_Position(_x, _y), type(EntityType::Entity)
{}

Entity::~Entity()
{
}

bool Entity::operator()(Entity& e)
{
	return true;
}

int Entity::GetID() const
{
	return m_ID;
}

EntityType Entity::GetType() const
{
	return type;
}

float Entity::GetX() const
{
	return m_Position.getX();
}

float Entity::GetY() const
{
	return m_Position.getY();
}

Position<float> Entity::GetPosition() const
{
	return m_Position;
}

void Entity::Tick(float dt)
{
}
