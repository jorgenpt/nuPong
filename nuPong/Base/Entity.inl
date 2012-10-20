template<typename T>
T* Entity::getComponent() const
{
    for (auto it = mComponents.begin(); it != mComponents.end(); ++it)
    {
        T* component = dynamic_cast<T*>(*it);
        if (component != NULL)
        {
            return component;
        }
    }

    return NULL;
}

template<typename T>
void Entity::createComponent()
{
    addComponent(new T(this));
}
