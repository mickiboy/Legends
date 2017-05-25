#include "Camera.h"

namespace graphics {
    Camera::Camera(int width, int height) {
        setViewport(width, height);
    }

    const glm::mat4& Camera::getViewMatrix() {
        return viewMatrix;
    }

    const glm::mat4& Camera::getProjectionMatrix() {
        return projectionMatrix;
    }

    void Camera::setPosition(float x, float y) {
        viewMatrix = glm::translate(glm::mat4(), glm::vec3(x, y, 0.0f));
    }

    void Camera::setViewport(int width, int height) {
        projectionMatrix = glm::ortho(0.0f, static_cast<float>(width), static_cast<float>(height), 0.0f);
    }

    void Camera::move(float x, float y) {
        viewMatrix = glm::translate(viewMatrix, glm::vec3(x, y, 0.0f));
    }
}
