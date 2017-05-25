#version 430 core

in vec2 vs_texCoord;

out vec4 color;

uniform sampler2D tex;

void main() {
    color = texture(tex, vs_texCoord);
}
