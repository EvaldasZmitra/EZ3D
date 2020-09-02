#version 330 core

in vec2 UV;
in vec3 normal;
in vec3 lightDirection;
in vec3 tangent;
in vec3 bitTangent;

out vec3 color;
uniform sampler2D myTextureSampler;
uniform sampler2D myNormalSampler;

void main(){
  vec2 uvv = UV * 25;
  vec3 normalColor = normalize(texture(myNormalSampler, uvv).xyz * 2.0 - 1.0);
  vec3 normal2 = normal * normalColor.z + bitTangent * normalColor.y + tangent * normalColor.x;
  vec3 normal3 = normalize(normal2 * 0.2 + normal);
  
  float intensity = dot(normal3, lightDirection);
  color = texture(myTextureSampler, uvv).rgb * max(intensity, 0.2);
}