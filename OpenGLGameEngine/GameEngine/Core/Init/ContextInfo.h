#pragma once

namespace GameEngine
{
	namespace Core
	{
		struct ContextInfo
		{
			int majorVersion, minorVersion;
			bool core;

			ContextInfo()
			{
				majorVersion = 4;
				minorVersion = 4;
				core = true;
			}

			ContextInfo(int majorVersion, int minorVersion, bool core)
			{
				this->majorVersion = majorVersion;
				this->minorVersion = minorVersion;
				this->core = core;
			}

			ContextInfo(const ContextInfo& contextInfo)
			{
				this->majorVersion = contextInfo.majorVersion;
				this->minorVersion = contextInfo.minorVersion;
				this->core = contextInfo.core;
			}

			void operator=(const ContextInfo& contextInfo)
			{
				this->majorVersion = contextInfo.majorVersion;
				this->minorVersion = contextInfo.minorVersion;
				this->core = contextInfo.core;
			}
		};
	}
}