//
// Created by Matt Whitaker on 28/02/2021.
//

#include "main.h"

int main(int argc, const char **argv) {
  // Create one application
  Application app = Application((char *) "openGLApplication", 1.0, Kaishi::RENDER_API_OPENGL);

  Kaishi::Log* log = Kaishi::Log::GetInstance(Kaishi::LOGGING_LEVEL_DEBUG);

  printf("Application name: %s\n", app.getName());

  // Specify how many windows we want created and be able to access them
  app.setup(2);

  Kaishi::Window *window1 = app.getWindow(0);
  Kaishi::Window *window2 = app.getWindow(1);
  Kaishi::View *view1 = new ExampleView();
  Kaishi::View *view2 = new ExampleView();

  // Push a render view onto the view hierarchy for each window
  app.pushView(window1, view1);
  app.pushView(window2, view2);
  // Run the application
  app.run();

  return 0;
}

void ExampleView::onAttach() {
  printf("Attached view\n");
  // RENDERING CONTEXT

  // build and compile our shader program
  // ------------------------------------
  shader = new Kaishi::OpenGLShaders("../../../assets/basic.glsl");
  shader->setup();

  // set up vertex data (and buffer(s)) and configure vertex attributes
  // ------------------------------------------------------------------
// Vertices coordinates
  float vertices[] =
      { //     COORDINATES     /        COLORS      /   TexCoord  //
          -0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 0.0f, 0.0f, // Lower left corner
          -0.5f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, // Upper left corner
          0.5f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 1.0f, // Upper right corner
          0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f, 0.0f  // Lower right corner
      };

// Indices for vertices order
  unsigned int indices[] =
      {
          0, 2, 1, // Upper triangle
          0, 3, 2 // Lower triangle
      };

  m_IndicesSize = sizeof(indices) / sizeof(indices[0]);

  m_VertexArray = new Kaishi::OpenGLVertexArray();
  m_VertexArray->bind();

  Kaishi::OpenGLVertexBuffer vertexBuffer = Kaishi::OpenGLVertexBuffer(vertices, sizeof(vertices));

  Kaishi::OpenGLIndexBuffer indexBuffer = Kaishi::OpenGLIndexBuffer(indices, sizeof(indices));

  // Positions
  m_VertexArray->linkVertexBuffer(&vertexBuffer, 0, 3, GL_FLOAT, 8 * sizeof(float), (void *) 0);
  // Colours
  m_VertexArray->linkVertexBuffer(&vertexBuffer, 1, 3, GL_FLOAT, 8 * sizeof(float), (void *) (3 * sizeof(float)));
  // Textures
  m_VertexArray->linkVertexBuffer(&vertexBuffer, 2, 2, GL_FLOAT, 8 * sizeof(float), (void *) (6 * sizeof(float)));


  // unbind both buffers so we don't use them accidentally
  m_VertexArray->unbind();
  vertexBuffer.unbind();
  indexBuffer.unbind();

  texture =
      new Kaishi::OpenGLTexture("../../../assets/pig.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);

  // Set the texture uniform
  shader->use();
  shader->setInt("tex0", 0);

  vertexBuffer.remove();
  indexBuffer.remove();
  // Check for openGL errors
  glCheckError();
}
void ExampleView::onDetach() {
  printf("Detached view\n");
  m_VertexArray->remove();
}
void ExampleView::renderLoop() {

  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  shader->use();
  float currentTime = (float) glfwGetTime();
  // bind textures on corresponding texture units
  texture->bind();

  glm::mat4 transform = glm::mat4(1.0f);
  // identity matrix, speed, rotation (x, y, z)
  transform = glm::rotate(transform, currentTime, glm::vec3(0.5f, 0.75f, 0.25f));

  shader->setMat4("transform", transform);

  // Call renderer draw
  m_VertexArray->bind();
  glDrawElements(GL_TRIANGLES, m_IndicesSize, GL_UNSIGNED_INT, nullptr);
}
