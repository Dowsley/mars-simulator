#include "../core/world.h"
#include "../utils/geometry.h"
#include "manager.h"
#include "creature.h"

CreatureManager::CreatureManager(World *worldRef) : worldRef(worldRef) {}
CreatureManager::~CreatureManager()
{
    for(auto & pair : creatureMap) {
        delete pair.second;
    }
}

const CreatureType* CreatureManager::GetTypeById(const std::string &id) const
{
    return registry.GetTypeById(id);
}


Creature* CreatureManager::GetCreatureAt(const Vec3 &pos) const
{
    int index = GeometryUtils::Flatten3DCoords(pos, worldRef->GetDimensions());
    if(creatureMap.find(index) != creatureMap.end()) {
        return creatureMap.at(index);
    }
    return nullptr;
}

bool CreatureManager::InstanceCreature(const std::string &id, const Vec3 &pos)
{
    int index = GeometryUtils::Flatten3DCoords(pos, worldRef->GetDimensions());
    // If creature already exists at that position, return false
    if (creatureMap.find(index) != creatureMap.end()) {
        return false;
    }

    CreatureType *type = registry.GetTypeById(id);
    if (type == nullptr) {
        throw std::runtime_error("Type not implemented: " + id);
    }

    Creature* newCreature = new Creature(type, pos);
    creatureMap[index] = newCreature;
    return true;
}

void CreatureManager::RemoveCreatureAt(const Vec3 &pos)
{
    int index = GeometryUtils::Flatten3DCoords(pos, worldRef->GetDimensions());
    if(creatureMap.find(index) != creatureMap.end()) {
        delete creatureMap[index]; // Delete the creature from the heap
        creatureMap.erase(index);  // Remove the entry from the map
    }
}

void CreatureManager::TraverseCreatures(std::function<void(Creature*)> callback)
{
    for(auto & pair : creatureMap) {
        callback(pair.second);
    }
}

void CreatureManager::UpdateCreatures()
{
    for(auto& pair : creatureMap) {
        pair.second->Update();
    }
}

int CreatureManager::GetTotalCreatureCount() const
{
    return creatureMap.size();
}

void CreatureManager::ClearCreatures()
{
    // TODO Make sure there will be non dangling references of creatures outside.
    creatureMap.clear();
}