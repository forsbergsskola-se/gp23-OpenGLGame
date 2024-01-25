#pragma once
#include "Mesh.h"
#include "Material.h"

class Triangle
{
	Mesh* mesh;
	Material* material;
public:
	Triangle(Mesh* mesh, Material* material)
	{
		this->mesh = mesh;
		this->material = material;
	}

	void renderer() {
		mesh->Render();
		material->use();
	}
};

