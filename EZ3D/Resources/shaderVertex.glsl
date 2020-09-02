#version 330 core
layout(location = 0) in vec3 vertexPosition_modelspace;
layout(location = 1) in vec2 vertexUV;
layout(location = 2) in vec3 in_normal;
layout(location = 3) in vec3 in_tangent;
layout(location = 4) in vec3 in_bitTangent;

uniform mat4 MVP;
uniform mat4 M;
uniform vec3 lightPosition;

out vec2 UV;
out vec3 normal;
out vec3 tangent;
out vec3 bitTangent;
out vec3 lightDirection;

void main(){
    gl_Position = MVP * vec4(vertexPosition_modelspace,1);
    UV = vertexUV;
    normal = (M * vec4(in_normal, 0)).xyz;
    tangent = (M * vec4(in_tangent, 0)).xyz;
    bitTangent = (M * vec4(in_bitTangent, 0)).xyz;
    lightDirection = normalize(lightPosition - vertexPosition_modelspace);
}