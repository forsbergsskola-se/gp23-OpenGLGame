#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 aCol;
layout (location = 2) in vec2 aTexCoord;
//                              ^ input #2 tex Coord
out vec4 vertexColor;
out vec2 texCoord; // << we want to output a tex Coord

uniform float horizontalOffset;
uniform mat4 transform;

void main()
{
    gl_Position = transform * vec4(aPos.x + horizontalOffset, aPos.y, aPos.z, 1.0);
    vertexColor = aCol;
    //texCoord = vec2(aPos.x + horizontalOffset, aPos.y); // we do output the value
    texCoord = aTexCoord;
}