#pragma once

namespace Engine
{
    class Component : public EObject
    {
    public:
        Component();
        virtual ~Component() = default;

    public:
        virtual bool IsClassType(const std::size_t class_type) const;
        static const std::size_t type;
    };
}
