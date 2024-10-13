#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>

// Declaring functions
// ----------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow *window, int width, int height);

void processInput(GLFWwindow *window);

// ----------------------------------------------------------------------

// Settings
// ----------------------------------------------------------------------
constexpr unsigned int HEIGHT = 600;
constexpr unsigned int WIDTH = 800;
// ----------------------------------------------------------------------

int main() {
    // Initializing and configuring GLFW
    // ----------------------------------------------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    // ----------------------------------------------------------------------

    // Window Creation
    // ----------------------------------------------------------------------
    GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
    if (window == nullptr) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    // ----------------------------------------------------------------------

    // Load GLAD to have access to the OpenGL function pointers
    // ----------------------------------------------------------------------
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress))) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    // ----------------------------------------------------------------------

    // Render Loop
    // ----------------------------------------------------------------------
    while (!glfwWindowShouldClose(window)) {
        // input
        // ----------------------------------------------------------------------
        processInput(window);

        // render
        // ----------------------------------------------------------------------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // GLFW: Swap buffers and poll I/O events
        // ----------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    // ----------------------------------------------------------------------

    // Terminate GLFW before exiting
    // ----------------------------------------------------------------------
    glfwTerminate();
    return 0;
    // ----------------------------------------------------------------------
}

// Function Implementations
// ----------------------------------------------------------------------
void processInput(GLFWwindow *window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
}

void framebuffer_size_callback(GLFWwindow *window, const int width, const int height) {
    glViewport(0, 0, width, height);
}

// ----------------------------------------------------------------------
