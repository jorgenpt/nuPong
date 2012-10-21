inline Entity& Component::getEntity()
{
    return mOwner;
}

inline b2Body* Component::getBody()
{
    return mOwner.body;
}

inline void Component::setBody(b2Body* body)
{
    mOwner.body = body;
}

template<typename T>
inline T* Component::getComponent() const {
    return mOwner.getComponent<T>();
}

inline void Component::addComponent(Component *component)
{
    mOwner.addComponent(component);
}