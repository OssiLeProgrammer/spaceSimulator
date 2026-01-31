#version 330 core
layout (location = 0) in vec3 aPos;

uniform mat4 cMatrix;
uniform mat4 wMatrix;

void main()
{
	gl_Position = cMatrix * wMatrix * vec4(aPos, 1.0);
}