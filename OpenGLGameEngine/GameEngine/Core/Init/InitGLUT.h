#pragma once

#include "ContextInfo.h"
#include "FramebufferInfo.h"
#include "WindowInfo.h"
#include "InitGLEW.h"
#include "IListener.h"
#include "DebugOutput.h"
#include <iostream>

namespace GameEngine
{
	namespace Core
	{
		namespace Init
		{
			class InitGLUT
			{
			private:
				static Core::IListener* listener;
				static Core::WindowInfo windowInfomation;

				static void IdleCallback(void);
				static void DisplayCallback(void);
				static void ReshapeCallback(int width, int height);
				static void CloseCallback(void);
			public:
				static void Init(const Core::WindowInfo& window, const Core::ContextInfo& context, const Core::FramebufferInfo& framebufferInfo);
				static void Run(void);
				static void Close(void);

				static void SetListener(Core::IListener*& iListener);

				void EnterFullscreen(void);
				void ExitFullscreen(void);

				static void PrintOpenGLInfo(const Core::WindowInfo& windowInfo, const Core::ContextInfo& context);
			};
		}
	}
}