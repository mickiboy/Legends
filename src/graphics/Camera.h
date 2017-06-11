#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace graphics {
    class Camera {
    public:
        Camera();
        Camera(int width, int height);

        const glm::mat4& getViewMatrix();
        const glm::mat4& getProjectionMatrix();

        void setPosition(float x, float y);
        void setViewport(int width, int height);

        void move(float x, float y);

    private:
        glm::mat4 viewMatrix;
        glm::mat4 projectionMatrix;
    };
}
