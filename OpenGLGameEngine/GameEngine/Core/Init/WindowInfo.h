#pragma once
#include <string>

namespace GameEngine
{
	namespace Core
	{
		struct WindowInfo
		{
			std::string name;
			int width, height;
			int posX, posY;
			bool isReshapable;

			WindowInfo()
			{
				name = "OpenGl Game Engine";
				width = 800;
				height = 600;
				posX = 10;
				posY = 10;
				isReshapable = true;
			}

			WindowInfo(std::string name, int posX, int posY,
				int width, int height, bool isReshapable)
			{
				this->name = name;
				this->posX = posX;
				this->posY = posY;
				this->width = width;
				this->height = height;
				this->isReshapable = isReshapable;
			}

			WindowInfo(const WindowInfo& windowInfo)
			{
				name = windowInfo.name;
				posX = windowInfo.posX;
				posY = windowInfo.posY;
				width = windowInfo.width;
				height = windowInfo.height;
				isReshapable = windowInfo.isReshapable;
			}

			void operator=(const WindowInfo& windowInfo)
			{
				name = windowInfo.name;
				posX = windowInfo.posX;
				posY = windowInfo.posY;
				width = windowInfo.width;
				height = windowInfo.height;
				isReshapable = windowInfo.isReshapable;
			}
		};
	}
}