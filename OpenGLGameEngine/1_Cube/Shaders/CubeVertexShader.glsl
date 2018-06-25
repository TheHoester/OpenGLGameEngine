#version 440 core
layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec4 inColour;

uniform mat4 projectionMatrix, viewMatrix;
uniform vec3 rotation;

out vec4 colour;

void main()
{

	colour = inColour;
	mat4 rotateX, rotateY, rotateZ;
	
	rotateX = mat4(1.0, 0.0, 0.0, 0.0,
					0.0, cos(rotation.x), sin(rotation.x), 0.0,
					0.0, -sin(rotation.x), cos(rotation.x), 0.0,
					0.0, 0.0, 0.0, 1.0);

	rotateY = mat4(cos(rotation.y), 0.0, -sin(rotation.y), 0.0,
					0.0, 1.0, 0.0, 0.0,
					sin(rotation.y), 0.0, cos(rotation.y), 0.0,
					0.0, 0.0, 0.0, 1.0);

	rotateZ = mat4(cos(rotation.z), -sin(rotation.z), 0.0, 0.0,
					sin(rotation.z), cos(rotation.z), 0.0, 0.0,
					0.0, 0.0, 1.0, 0.0,
					0.0, 0.0, 0.0, 1.0);

	gl_Position = projectionMatrix * viewMatrix * rotateY * rotateX * rotateZ * vec4(inPosition, 1);
	
}