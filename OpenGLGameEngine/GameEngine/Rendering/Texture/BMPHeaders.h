#pragma once

namespace GameEngine
{
	namespace Rendering
	{
		namespace Texture
		{
			struct BMPHeader
			{
				unsigned char type[2];
				int fLength, offBits;
				short reserved1, reserved2;
			};

			struct BMPHeaderInfo
			{
				int size, width, height;
				short planes, bitCount;
				int compression, sizeImage;
				int xPelsPerMetre, yPelsPerMetre;
				int clrUsed, clrImportant;
			};
		}
	}
}