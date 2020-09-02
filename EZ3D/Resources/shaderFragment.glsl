#version 330 core

in vec2 UV;
in vec3 normal;
in vec3 lightDirection;

out vec3 color;
uniform sampler2D myTextureSampler;

void main(){
  float intensity = dot(normal, lightDirection);
  color = texture( myTextureSampler, UV ).rgb * max(intensity, 0.2);
}