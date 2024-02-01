#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aCol;
layout (location = 2) in vec2 aTexCoord; //input #2 tex Coord

out vec4 vertexColor;
out vec2 texCoord; //output a tex Coord

uniform float horizontalOffset;

void main()
{
// gl_Position = vec4(aPos.xyz, 1.0) + vec4(0, sin(time), 0, 1));

gl_Position = vec4(aPos.x + horizontalOffset, aPos.y, aPos.z, 1.0);
vertexColor = aCol;
texCoord = aTexCoord; //do output the value
}