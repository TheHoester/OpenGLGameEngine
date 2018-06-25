#pragma once

#include "GL\glew.h"
#include "GL\freeglut.h"

namespace GameEngine
{
	namespace Core
	{
		struct FramebufferInfo
		{
			unsigned int flags;
			bool msaa;

			FramebufferInfo()
			{
				flags = GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH;
				msaa = false;
			}

			FramebufferInfo(bool colour, bool depth, bool stencil, bool msaa)
			{
				flags = GLUT_DOUBLE;
				if (colour)
					flags |= GLUT_RGBA | GLUT_ALPHA;
				if (depth)
					flags |= GLUT_DEPTH;
				if (stencil)
					flags |= GLUT_STENCIL;
				if (msaa)
					flags |= GLUT_MULTISAMPLE;
				this->msaa = msaa;
			}

			FramebufferInfo(const FramebufferInfo& framebufferInfo)
			{
				this->flags = framebufferInfo.flags;
				this->msaa = framebufferInfo.msaa;
			}

			void operator=(const FramebufferInfo& framebufferInfo)
			{
				this->flags = framebufferInfo.flags;
				this->msaa = framebufferInfo.msaa;
			}
		};
	}
}