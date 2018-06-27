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
			glm::vec2 texture;

			VertexFormat(const glm::vec3 &iPos, const glm::vec4 &iColour)
			{
				position = iPos;
				colour = iColour;
				texture.x = texture.y = 0;
			}

			VertexFormat(const glm::vec3 &iPos, const glm::vec2 &iTexture)
			{
				position = iPos;
				texture = iTexture;
				colour.r = colour.g = colour.b = colour.a = 0;
			}

			VertexFormat(void) { }
		};
	}
}

#endif