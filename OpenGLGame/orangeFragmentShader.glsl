#version 330 core
out vec4 FragColor;
uniform vec4 tintColor;
in vec4 vertexColor;
in vec3 vertexPosition;
uniform float time;
void main()
{
FragColor = vertexColor + vec4(vertexPosition,1) + vec4(sin(time*4+vertexPosition.x*4)/2,cos(time*4)/2,0,1);
}