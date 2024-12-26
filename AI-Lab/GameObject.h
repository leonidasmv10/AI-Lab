#pragma once

#include "EObject.h"
#include "Component.h"

namespace Engine
{
    class GameObject : public EObject
    {
    public:
        template <class ComponentType, typename... Args>
        void AddComponent(Args&&... params);

        template <class ComponentType>
        ComponentType& GetComponent();

        template <class ComponentType>
        bool RemoveComponent();

        template <class ComponentType>
        std::vector<ComponentType*> GetComponents();

        template <class ComponentType>
        int RemoveComponents();

    private:
        std::vector<std::unique_ptr<Component>> components;
    };


    template <class ComponentType, typename... Args>
    void GameObject::AddComponent(Args&&... params)
    {
        components.emplace_back(std::make_unique<ComponentType>(std::forward<Args>(params)...));
    }

    template <class ComponentType>
    ComponentType& GameObject::GetComponent()
    {
        for (auto&& component : components)
        {
            if (component->IsClassType(ComponentType::type))
                return *static_cast<ComponentType*>(component.get());
        }

        return *std::unique_ptr<ComponentType>(nullptr);
    }

    template <class ComponentType>
    bool GameObject::RemoveComponent()
    {
        if (components.empty())
            return false;

        auto index = std::find_if(components.begin(),
            components.end(),
            [classType = ComponentType::type](auto& component)
            {
                return component->IsClassType(classType);
            });

        const bool success = index != components.end();

        if (success)
            components.erase(index);

        return success;
    }


    template <class ComponentType>
    std::vector<ComponentType*> GameObject::GetComponents()
    {
        std::vector<ComponentType*> components_of_type;

        for (auto&& component : components)
        {
            if (component->IsClassType(ComponentType::type))
                components_of_type.emplace_back(static_cast<ComponentType*>(component.get()));
        }

        return components_of_type;
    }

    template <class ComponentType>
    int GameObject::RemoveComponents()
    {
        if (components.empty())
            return 0;

        int num_removed = 0;
        bool success = false;

        do
        {
            auto index = std::find_if(components.begin(),
                components.end(),
                [classType = ComponentType::type](auto& component)
                {
                    return component->IsClassType(classType);
                });

            success = index != components.end();

            if (success)
            {
                components.erase(index);
                ++num_removed;
            }
        } while (success);

        return num_removed;
    }
}
