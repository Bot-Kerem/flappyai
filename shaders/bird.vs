#version 460 compatibility

vec2 vert[4] = vec2[](
    vec2(-1.0f, 1.0f),
    vec2(1.0f, 1.0f),
    vec2(-1.0f, -1.0f),
    vec2(1.0f, -1.0f)
    );

uniform vec2 size;
uniform vec2 position;

out vec2 FragPos;

void main(){
  gl_Position = vec4(vert[gl_VertexID] * size + position, 0.0f, 1.0f);
  FragPos = vert[gl_VertexID];
}
