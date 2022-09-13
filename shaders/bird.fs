#version 460

out vec4 FragColor;

in vec2 FragPos;

void main(){
  if(sqrt(pow(FragPos.x, 2) + pow(FragPos.y, 2)) >= 1){
    discard;
  }
  FragColor = vec4(0.52f, 0.52f, 0.52f, 0.6f);
}
