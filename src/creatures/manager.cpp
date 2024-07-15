#include "manager.h"
#include "geometry.h"
#include "../core/world.h"
#include <stdexcept>

CreatureManager::CreatureManager(World *world) : ManagerBase<Creature>(world), octree({{0, 0, 0}, world->GetDimensions()}) {
    registry.Initialize();
}

CreatureManager::~CreatureManager() {
    ClearItems();
}

Creature* CreatureManager::GetItemAt(const Vec3 &pos) const {
    auto hits = octree.Query(Octree::Sphere{{pos.x, pos.y, pos.z}, 0.001f}); // Use a very small radius to mimic point query
    return !hits.empty() ? hits.front().Data : nullptr;
}

void CreatureManager::TraverseItems(std::function<void(Creature*)> callback) {
    auto hits = octree.Query(Octree::All());
    for (const auto& hit : hits) {
        callback(hit.Data);
    }
}

int CreatureManager::GetTotalItemCount() const {
    return octree.Size();
}

void CreatureManager::ClearItems() {
    auto hits = octree.Query(Octree::All());
    for (const auto& hit : hits) {
        delete hit.Data;
    }
    // Manually clear the octree
    _clearOctree(octree);
}

void CreatureManager::_clearOctree(Octree& octree) {
    auto hits = octree.Query(Octree::All());
    for (const auto& hit : hits) {
        octree.Remove(hit); // Remove each item from the octree
    }
}

const CreatureType* CreatureManager::GetTypeById(const std::string &id) const {
    return registry.GetTypeById(id);
}

Creature* CreatureManager::InstanceCreature(const std::string &typeID, const Vec3 &pos) {
    auto hits = octree.Query(Octree::Sphere{{pos.x, pos.y, pos.z}, 0.001f}); // Use a very small radius to mimic point query

    // If creature already exists at that position
    if (!hits.empty()) {
        return nullptr;
    }

    CreatureType *type = registry.GetTypeById(typeID);
    if (type == nullptr) {
        throw std::runtime_error("Type not implemented: " + typeID);
    }

    auto *newCreature = new Creature(*type, pos);
    octree.Add({.Vector{pos}, .Data=newCreature});

    return newCreature;
}

void CreatureManager::RemoveCreatureAt(const Vec3 &pos) {
    auto hits = octree.Query(Octree::Sphere{{pos.x, pos.y, pos.z}, 0.001f}); // Use a very small radius to mimic point query
    if (!hits.empty()) {
        delete hits.front().Data; // Delete the creature from the heap
        octree.Remove(hits.front()); // Remove the creature from the octree
    }
}

void CreatureManager::UpdateCreatures(const World &world) {
    auto hits = octree.Query(Octree::All());
    Octree updatedOctree({{0, 0, 0}, world.GetDimensions()});

    for (auto& hit : hits) {
        Creature *creature = hit.Data;
        std::optional<Vec3> posOpt = creature->Update(world);

        if (!posOpt.has_value()) {
            updatedOctree.Add(hit);
            continue;
        }

        Vec3 newPos = posOpt.value();
        if (!worldRef->IsInBounds(newPos) || !worldRef->IsPositionWalkable(newPos)) {
            updatedOctree.Add(hit);
            continue;
        }

        auto newHit = Octree::TDataWrapper{.Vector{newPos}, .Data=creature};
        if (!updatedOctree.Query(Octree::Sphere{{newPos.x, newPos.y, newPos.z}, 0.001f}).empty()) {
            updatedOctree.Add(hit);
            continue;
        }

        creature->SetPosition(newPos);
        updatedOctree.Add(newHit);
    }

    octree = std::move(updatedOctree);
}

void CreatureManager::ClearCreatures() {
    ClearItems();
}

std::vector<const CreatureType*> CreatureManager::GetAllTypes() const {
    return registry.GetAllTypes();
}