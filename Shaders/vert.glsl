#version 330 core

layout (location = 0) in vec3 position;


uniform vec3 scale;
uniform vec3 pos;

uniform float angle;

void main() {
    // float dis_from_center = 10f;

    float newposx = (position.x * scale.x) + pos.x;
    float newposy = (position.y * scale.y) + pos.y;
    float newposz = (position.z * scale.z) + pos.z;
    vec3 newpos = vec3(newposx, newposy, newposz);

    // Apply rotation transformation
    float x_rotated = newposx * cos(angle) - newposy * sin(angle);
    float y_rotated = newposx * sin(angle) + newposy * cos(angle);

    newpos.x = x_rotated;
    newpos.y = y_rotated;
    gl_Position = vec4(newpos, 1.0);
}
