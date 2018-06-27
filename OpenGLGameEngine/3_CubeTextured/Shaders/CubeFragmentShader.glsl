#version 440 core

layout(location = 0) out vec4 outColour;

uniform sampler2D texture1;

in vec2 texCoord;
 
void main(void)
{
	vec4 colour = texture(texture1, texCoord);
	outColour = colour;
}