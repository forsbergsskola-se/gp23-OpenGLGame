#version 330 core
out vec4 FragColor;

uniform vec4 tintColor;
uniform sampler2D diffuseTexture;

in vec4 vertexColor;
in vec2 texCoord;

void main()
{
	//FragColor = vec4(texCoord.x, texCoord.y, 0 , 1);
	FragColor = vertexColor * texture(diffuseTexture, texCoord);
}