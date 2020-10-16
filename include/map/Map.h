#pragma once

#include "map/MapElement.h"
#include "entity/Entity.h"
#include "entity/npc/Npc.h"

class Map
{

public:
    Map(std::string name, int width, int height, std::vector<std::vector<MapElement*>> elements, std::string backgroundPath, std::vector<Npc*> entities);
    Map(Map& map);
    Map(const Map& map);
    Map(Map&& map);
    ~Map();
    std::string getName() const;
    std::string getBackgroundPath() const;
    int getWidth() const;
    int getHeight() const;
    std::vector<Npc*> getEntities() const;
    bool canEntityMoveAt(int x, int y, Entity* entity) const;
    MapElement* getAt(int x, int y) const;
    std::vector<std::vector<MapElement*>> getMapElements() const;
    //const Map& copy() const;

private:
    std::string m_Name;
    int m_Width;
    int m_Height;
    std::vector<std::vector<MapElement*>> m_Elements;
    std::vector<Npc*> m_Entities;
    std::string m_BackgroundPath;

};