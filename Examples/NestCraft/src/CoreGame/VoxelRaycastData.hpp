#pragma once

#include "glm/glm.hpp"
#include "Voxel.hpp"

struct VoxelRaycastData {
    Voxel *voxel;
    glm::vec3 end;
    glm::vec3 normal;

    VoxelRaycastData(Voxel *voxel, const glm::vec3 &anEnd, const glm::vec3 &normal)
        : voxel(voxel)
        , end(anEnd)
        , normal(normal) {}
};
