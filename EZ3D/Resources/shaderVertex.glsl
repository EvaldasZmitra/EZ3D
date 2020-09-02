#version 330 core
layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec2 vertexUV;
layout(location = 2) in vec3 in_normal;

uniform mat4 MVP;
uniform mat4 M;
uniform vec3 lightPosition;

out vec2 UV;
out vec3 normal;
out vec3 lightDirection;

void main(){
    gl_Position = MVP * vec4(vertexPosition_modelspace,1);
    UV = vertexUV;
    normal = in_normal;
    lightDirection = normalize((M * vec4((lightPosition - vertexPosition_modelspace), 0)).xyz);
}