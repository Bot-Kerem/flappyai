#version 460 compatibility

vec2 vert[4] = vec2[](
    vec2(0.0f, -1.0f),
    vec2(1.0f, -1.0f),
    vec2(0.0f, 0.0f),
    vec2(1.0f, 0.0f)
    );

uniform vec2 size;
uniform vec2 position;

void main(){
  gl_Position = vec4(vert[gl_VertexID] * size + vec2(0.0f, 1.0f) + position, 0.0f, 1.0f);
}
