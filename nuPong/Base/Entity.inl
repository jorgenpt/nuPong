template<typename T>
inline T* Entity::getComponent() const
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