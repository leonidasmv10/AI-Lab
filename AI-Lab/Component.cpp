#include "stdafx.h"
#include "Component.h"

namespace Engine
{
    Component::Component()
    {
    }

    bool Component::IsClassType(const std::size_t class_type) const
    {
        return class_type == type;
    }
}
