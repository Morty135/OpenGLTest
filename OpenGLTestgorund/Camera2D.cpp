#include"Camera2D.h"



Camera2D::Camera2D(int width, int height, glm::vec2 position)
{
	Camera2D::width = width;
	Camera2D::height = height;
	Position = position;
}

void Camera2D::Matrix(Shader& shader, const char* uniform)
{
	// Initializes matrices since otherwise they will be the null matrix
	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 projection = glm::mat4(1.0f);

	// Makes camera look in the right direction from the right position
	view = glm::translate(view, glm::vec3(Position,0.0f));
	// Adds perspective to the scene
	projection = glm::ortho(static_cast<float>(width),0.0f ,static_cast<float>(height),0.0f, -1.0f, 1.0f);

	// Exports the camera matrix to the Vertex Shader
	glUniformMatrix4fv(glGetUniformLocation(shader.ID, uniform), 1, GL_FALSE, glm::value_ptr(projection * view));
}



void Camera2D::Inputs(GLFWwindow* window)
{
	// Handles key inputs
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
	{
		Position += speed * Up;
	}
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
	{
		Position += speed * Right;
	}
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
	{
		Position += speed * -Up;
	}
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
	{
		Position += speed * -Right;
	}
	speed = speed;
}