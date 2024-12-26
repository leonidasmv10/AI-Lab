#include "stdafx.h"
#include "CoreBehaviour.h"

namespace Engine
{
    CoreBehaviour::CoreBehaviour()
    {
        gameObject = std::make_shared<GameObject>();

        gameObject->AddComponent<Component>();
        gameObject->AddComponent<Transform>();

        transform = &gameObject->GetComponent<Transform>();
    }

    void CoreBehaviour::Start()
    {
    }

    void CoreBehaviour::Update()
    {
    }

    void CoreBehaviour::Render()
    {
    }
}
