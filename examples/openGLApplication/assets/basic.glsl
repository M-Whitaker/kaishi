#shadertype vertex
    #version 330 core
    layout (location = 0) in vec3 aPos;
    uniform mat4 transform;
    void main() {
        gl_Position = transform * vec4(aPos, 1.0);
    }
#endshadertype

#shadertype fragment
    #version 330 core
    out vec4 FragColor;
    uniform vec4 ourColour;
    void main() {
        FragColor = ourColour;
    }
#endshadertype