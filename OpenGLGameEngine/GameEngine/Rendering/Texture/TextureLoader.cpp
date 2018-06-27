#include "TextureLoader.h"
using namespace GameEngine::Rendering;

TextureLoader::TextureLoader()
{

}

TextureLoader::~TextureLoader()
{

}

unsigned int TextureLoader::LoadTexture(const std::string& filename, unsigned int width, unsigned int height)
{
	unsigned char* data;
	LoadBMPFile(filename, width, height, data);

	//create the OpenGL texture
	unsigned int glTextureObject;
	glGenTextures(1, &glTextureObject);
	glBindTexture(GL_TEXTURE_2D, glTextureObject);

	//filtering
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	float maxAnisotropy;
	glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &maxAnisotropy);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, maxAnisotropy);
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	//Generates texture
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

	//eliminates the array from the RAM
	delete data;

	//creates the mipmap hierarchy
	glGenerateMipmap(GL_TEXTURE_2D);

	//returns the texture object
	return glTextureObject;
}

void TextureLoader::LoadBMPFile(const std::string& filename, unsigned int& width, unsigned int& height, unsigned char*& data)
{
	// Read the file
	std::ifstream file(filename.c_str(), std::ios::in | std::ios::binary);
	if (!file.good()) 
	{
		std::cout << "Texture Loader: Cannot open texture file ";
		width = 0;
		height = 0;
		return;
	}

	// Reads the headers
	Texture::BMPHeader h; 
	Texture::BMPHeaderInfo hInfo;
	file.read((char*)&(h.type[0]), sizeof(char));
	file.read((char*)&(h.type[1]), sizeof(char));
	file.read((char*)&(h.fLength), sizeof(int));
	file.read((char*)&(h.reserved1), sizeof(short));
	file.read((char*)&(h.reserved2), sizeof(short));
	file.read((char*)&(h.offBits), sizeof(int));
	file.read((char*)&(hInfo), sizeof(Texture::BMPHeaderInfo));

	std::cout << "\n**********Texture Input**********" << std::endl;
	std::cout << "Type[0]: " << h.type[0] << std::endl;
	std::cout << "Type[1]: " << h.type[1] << std::endl;
	std::cout << "FLength: " << h.fLength << std::endl;
	std::cout << "Reserved1: " << h.reserved1 << std::endl;
	std::cout << "Reserved2: " << h.reserved2 << std::endl;
	std::cout << "Offbits: " << h.offBits << std::endl;
	std::cout << "HInfo Width: " << hInfo.width << std::endl;
	std::cout << "HInfo Height: " << hInfo.height << std::endl;
	std::cout << "*********************************" << std::endl;

	// Assigning memory (a pixel has 3 components, R, G, B)
	data = new unsigned char[hInfo.width * hInfo.height * 3];

	// Check if the line contains 4 byte groups
	long padd = 0;
	if ((hInfo.width * 3) % 4 != 0) padd = 4 - (hInfo.width * 3) % 4;
	width = hInfo.width;
	height = hInfo.height;

	// Reading the matrix
	long pointer;
	unsigned char r, g, b;
	for (unsigned int i = 0; i < height; i++)
	{
		for (unsigned int j = 0; j < width; j++)
		{
			file.read((char*)&b, 1);
			file.read((char*)&g, 1);
			file.read((char*)&r, 1);

			pointer = (i * width + j) * 3;
			data[pointer] = r;
			data[pointer + 1] = g;
			data[pointer + 2] = b;
		}
		file.seekg(padd, std::ios_base::cur);
	}
	file.close();
}