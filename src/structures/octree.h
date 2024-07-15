//
// Created by fell on 7/13/24.
//

#ifndef LIVE_WORLD_ENGINE_OCTREE_H
#define LIVE_WORLD_ENGINE_OCTREE_H

#include "../lib/octree-cpp/include/octree-cpp/OctreeCpp.h"
#include "../lib/octree-cpp/include/octree-cpp/OctreeQuery.h"
#include "../lib/octree-cpp/include/octree-cpp/OctreeUtil.h"

#include "../creatures/creature.h"
#include "vec3.h"

using Octree = OctreeCpp<Vec3, Creature*>;


#endif //LIVE_WORLD_ENGINE_OCTREE_H
