#pragma once

#include "../GameEngine/Rendering/Models/Model.h"
#include <time.h>
#include <stdarg.h>

using namespace GameEngine::Rendering::Models;

class Cube : public Model
{
private:
	glm::vec3 rotation, rotationSpeed;
	int prevTimeSinceStart;

public:
	Cube(void);
	~Cube(void);

	void Create(void);
	virtual void Draw(const glm::mat4& projectionMatrix, const glm::mat4& viewMatrix) override final;
	virtual void Update(void) override final;
};