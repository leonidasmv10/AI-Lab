#version 330 
in vec2 TexCoord;
out vec4 fragColor;

uniform sampler2D mTexture;

void main()
{
	fragColor = texture(mTexture, TexCoord);
}