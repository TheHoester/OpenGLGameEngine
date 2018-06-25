#pragma once

namespace GameEngine
{
	namespace Core
	{
		class IListener
		{
		public:
			virtual ~IListener(void) = 0;

			// Drawing Functions
			virtual void NotifyBeginFrame(void) = 0;
			virtual void NotifyDisplayFrame(void) = 0;
			virtual void NotifyEndFrame(void) = 0;
			virtual void NotifyReshape(int width, int height, int prevWidth, int prevHeight) = 0;
		};

		inline IListener::~IListener()
		{
			// Implementation of pure virtual destructor
		}
	}
}