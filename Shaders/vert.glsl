#version 330 core

layout (location = 0) in vec3 offset;


uniform vec3 position;
uniform vec3 rotation;
uniform vec3 scale;
uniform vec3 pivot;
uniform vec3 projection;

void main() {
    
    vec3 scaledOffset = offset * scale;

    vec3 relativePosition = scaledOffset + pivot;

    // float rotatedx = relativePosition.x * cos(angle) - relativePosition.y * sin(angle);
    // float rotatedy = relativePosition.x * sin(angle) + relativePosition.y * cos(angle);
    // float rotatedz = relativePosition.z;

    vec3 rotatedPosition = vec3(
        relativePosition.x * cos(rotation.x) - relativePosition.z * sin(rotation.z),
        relativePosition.y * cos(rotation.y) - relativePosition.z * sin(rotation.y),
        relativePosition.y * sin(rotation.y) + relativePosition.z * cos(rotation.z) 
    ); //FIX THE ROTATION // <Tue Apr 16 18:44:20 +01 2024>

    vec3    newpos = rotatedPosition + position;
	    
    gl_Position = vec4(newpos / projection, 1.0);
}
