#version 440 core
out vec4 FragColor;
  
in vec3 ourColor;
in vec2 TexCoord;

uniform sampler2D ourTexture;

void main()
{
    vec4 textureColor = texture(ourTexture, TexCoord);

    if(textureColor.a < 0.1)
        discard;

    FragColor = texture(ourTexture, TexCoord);
}