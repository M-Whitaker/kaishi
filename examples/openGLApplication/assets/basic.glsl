#shadertype vertex
    #version 330 core
    layout (location = 0) in vec3 aPos;
    layout (location = 1) in vec3 aColour;
    layout (location = 2) in vec2 aTex;

    out vec3 colour;
    out vec2 texCoord;

    uniform mat4 transform;
    void main() {
        gl_Position = transform * vec4(aPos, 1.0);
        colour = aColour;
        texCoord = aTex;
    }
#endshadertype

#shadertype fragment
    #version 330 core
    out vec4 FragColor;

    in vec3 colour;
    in vec2 texCoord;

    uniform sampler2D tex0;

    void main() {
        FragColor = texture(tex0, texCoord);
    }
#endshadertype