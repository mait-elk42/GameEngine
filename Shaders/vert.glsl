#version 330 core

layout (location = 0) in vec3 offset;


uniform vec3 scale;
uniform vec3 position;

uniform float angle;

void main() {
    float   newposx = (offset.x * scale.x) + position.x;
    float   newposy = (offset.y * scale.y) + position.y;
    float   newposz = (offset.z * scale.z) + position.z;
    vec3    newpos = vec3(newposx, newposy, newposz);

    // Apply rotation transformation
    float x_rotated = newposx * cos(angle) - newposy * sin(angle);
    float y_rotated = newposx * sin(angle) + newposy * cos(angle);

    newpos.x = x_rotated;
    newpos.y = y_rotated;
    gl_Position = vec4(newpos, 1.0);
}
