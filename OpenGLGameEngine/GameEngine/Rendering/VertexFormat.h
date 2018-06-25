#ifndef VertexFormat_H_
#define VertexFormat_H_

#include "glm\glm.hpp"

namespace GameEngine
{
	namespace Rendering
	{
		struct VertexFormat
		{
			glm::vec3 position;
			glm::vec4 colour;

			VertexFormat(const glm::vec3 &iPos, const glm::vec4 &iColour)
			{
				position = iPos;
				colour = iColour;
			}

			VertexFormat(void) {}
		};
	}
}

#endif