#version 440 core

layout(location = 0) out vec4 outColour;

in vec4 colour;
 
void main(void)
{
	outColour = colour;
}