#version 330 core

out vec4 FragColor;

void main() {
   FragColor = vec4(0, 0, 0, 1);
   
   int width = 712;
   int height = 712;

   if (int(gl_FragCoord.y) % 40 > 20) discard;

   if (gl_FragCoord.x < width/2 && gl_FragCoord.y >= height/2) {
      FragColor = vec4(1, 0, 0, 1);
   } else if (gl_FragCoord.x >= width/2 && gl_FragCoord.y >= height/2) {
      FragColor = vec4(0, 1, 0, 1);
   } else if (gl_FragCoord.x >= width/2 && gl_FragCoord.y < height/2) {
      FragColor = vec4(0, 0, 1, 1);
   } else { // (gl_FragCoord.x < width/2 && gl_FragCoord.y < height/2)
      FragColor = vec4(1, 1, 0, 1);
   }
}

