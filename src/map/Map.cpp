#include "pch.h"

#include "map/Map.h"

Map::Map(std::string name, int width, int height, std::vector<std::vector<MapElement*>> elements, std::string backgroundPath) :
    m_Name(name),
    m_Width(width),
    m_Height(height),
    m_Elements(elements),
    m_BackgroundPath(backgroundPath)
{

}

Map::Map(const Map& map) :
    m_Name(map.m_Name),
    m_Width(map.m_Width),
    m_Height(map.m_Height),
    m_BackgroundPath(map.m_BackgroundPath)
{
    for (int x = 0; x < m_Width; x++) {
        m_Elements.push_back(std::vector<MapElement*>());
        for (int y = 0; y < m_Height; y++) {
            m_Elements[x].push_back(map.m_Elements[x][y]->copy());
        }
    }
}

Map::~Map()
{
    for (int x(0); x < m_Elements.size(); x++) {
        for (int y(0); y < m_Elements[x].size(); y++) {
            delete m_Elements[x][y];
        }
    }
}

std::string Map::getName() const
{
    return m_Name;
}

std::string Map::getBackgroundPath() const
{
    return m_BackgroundPath;
}

bool Map::canEntityMoveAt(int x, int y, Entity* entity)
{
    return m_Elements[x][y]->canEntityMoveOn(entity);
}

MapElement* Map::getAt(int x, int y)
{
    if (x < 0 || x >= m_Width || y < 0 || y >= m_Height) {
        return nullptr;
    }
    return m_Elements[x][y];
}

int Map::getWidth()
{
    return m_Width;
}

int Map::getHeight()
{
    return m_Height;
}