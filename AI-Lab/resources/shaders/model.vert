#version 330 
in vec4 vPos;
in vec2 vTexCoord;

uniform mat4 mMvp;
out vec2 TexCoord;

void main()
{
	gl_Position = mMvp*vPos;
	TexCoord = vTexCoord;
}