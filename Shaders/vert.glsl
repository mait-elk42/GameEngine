#version 330 core

layout (location = 0) in vec3 offset;


uniform vec3 position;
uniform vec3 scale;
uniform vec3 pivot;

uniform float angle;

void main() {
    
    vec3 scaledOffset = offset * scale;

    vec3 relativePosition = scaledOffset + pivot;

    float rotatedx = relativePosition.x; // relativePosition.x * cos(angle) - relativePosition.y * sin(angle);
    float rotatedy = relativePosition.y; // relativePosition.x * sin(angle) + relativePosition.y * cos(angle);
    float rotatedz = relativePosition.z; // relativePosition.z;

    vec3    newpos = vec3(rotatedx, rotatedy, rotatedz) + position;
    
    gl_Position = vec4(newpos, 1.0);
}
