#include <iostream>
#include <glad/glad.h>    // Include GLAD for loading OpenGL functions
#include <GLFW/glfw3.h>
#include "Camera.h"
#include "Shader.h"
#include "Model.h"
#include "Geometry.h"
#include "Physics.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <functional>


int wwidth = 800, wheight = 600;

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void window_size_callback(GLFWwindow* window, int width, int height);

int main(int argc, char** argv) {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cout << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Set OpenGL version and profile
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // Create GLFW window
    GLFWwindow* window = glfwCreateWindow(wwidth, wheight, "LearnOpenGL", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Make the context current
    glfwMakeContextCurrent(window);

    // Set the framebuffer size callback
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    //glfwSetWindowSizeCallback(window, window_size_callback);

    // Initialize GLAD after the OpenGL context is created
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // copied

    Planet planet1(10.0f, 1.0f, glm::vec3(-10.0f, 0.0f, 0.0f), glm::vec3(2.0f, 2.0f, 0.0f));
    Planet planet2(20.0f, 1.0f, glm::vec3(10.0f, -2.0f, 0.0f), glm::vec3(0.0f, 2.0f, 0.0f));
    Planet planet3(50.0f, 1.0f, glm::vec3(15.0f, 4.0f, 0.0f), glm::vec3(0.0f, 0.0f, 2.0f));
    //Planet planet4(50.0f, 1.0f, glm::vec3(15.0f, 8.0f, 0.0f), glm::vec3(0.0f, -1.0f, 6.0f));
    std::vector<Planet*> planets = { &planet1, &planet2, &planet3};
    World world(planets);


    // copied
    Shader shader("Vert.shader", "Frag.shader");
    Camera camera(wwidth, wheight, glm::vec3(0.0f, 0.0f, -10.0f));

    // Time tracking
    float lastFrameTime = 0.0f;  // Stores time of last frame
    float deltaTime = 0.0f;      // Time between current and last frame


    // colors
    glm::vec3 blue = glm::vec3(0.0f, 0.0f, 1.0f);
    glm::vec3 red = glm::vec3(1.0f, 0.0f, 0.0f);
    glm::vec3 green = glm::vec3(0.0f, 1.0f, 0.0f);
    glm::vec3 orange = glm::vec3(0.0f, 0.5f, 0.5f);

    // Set the background color
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glEnable(GL_DEPTH_TEST);
    while (!glfwWindowShouldClose(window)) {
        // Calculate delta time (dt)
        float currentFrameTime = glfwGetTime();  // Get current time
        deltaTime = currentFrameTime - lastFrameTime;  // Calculate time difference
        lastFrameTime = currentFrameTime;  // Update last frame time

        // Poll events and clear the screen
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Update the camera with user inputs
        camera.Inputs(window);
        camera.Matrix(60.0f, 0.01f, 100.0f);  // Update the projection matrix

        shader.use();  // Use the shader program

        // Upload camera matrix
        camera.Upload(shader, "cMatrix");
        world.update(deltaTime);

        // Draw planet1
        shader.uploadVec3("color", blue);  // Set color for planet1
        glm::mat4 model1 = planet1.getModel();  // Get model matrix for planet1
        shader.uploadMat4("wMatrix", model1);  // Upload model matrix
        planet1.draw();  // Draw planet1

        // Draw planet2
        shader.uploadVec3("color", red);  // Set color for planet2
        glm::mat4 model2 = planet2.getModel();  // Get model matrix for planet2
        shader.uploadMat4("wMatrix", model2);  // Upload model matrix
        planet2.draw();  // Draw planet2

        shader.uploadVec3("color", green);  // Set color for planet2
        glm::mat4 model3 = planet3.getModel();  // Get model matrix for planet2
        shader.uploadMat4("wMatrix", model3);  // Upload model matrix
        planet3.draw();  // Draw planet2

        /*shader.uploadVec3("color", orange);  // Set color for planet2
        glm::mat4 model4 = planet4.getModel();  // Get model matrix for planet2
        shader.uploadMat4("wMatrix", model4);  // Upload model matrix
        planet4.draw();  // Draw planet2 */


        // Swap buffers
        glfwSwapBuffers(window);
    }

    // Clean up and terminate GLFW
    glfwTerminate();
    return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
    wwidth = width;
    wheight = height;
}