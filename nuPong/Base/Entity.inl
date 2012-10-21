template<typename T>
inline T* Entity::getComponent() const
{
    for (auto component : mComponents)
    {
        T* componentCast = dynamic_cast<T*>(component);
        if (componentCast != NULL)
            return componentCast;
    }

    return NULL;
}