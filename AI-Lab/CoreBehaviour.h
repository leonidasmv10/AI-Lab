#pragma once
#include "GameObject.h"
#include "Transform.h"

namespace Engine
{
    class CoreBehaviour
    {
    public:
        CoreBehaviour();
        virtual ~CoreBehaviour() = default;

        std::shared_ptr<GameObject> gameObject;
        Transform* transform;

        virtual void Start();
        virtual void Update();
        virtual void Render();
    };
}
