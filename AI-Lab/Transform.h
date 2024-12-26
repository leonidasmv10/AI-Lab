#pragma once

namespace Engine
{
    class Transform : public Component
    {
        CLASS_DECLARATION(Transform)
    public:
        Transform();
        glm::vec2 position;
        glm::vec2 scale;
        float rotation;

        void log();
    };
}
