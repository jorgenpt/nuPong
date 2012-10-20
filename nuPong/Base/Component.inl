template<typename T>
T* Component::getComponent() const {
    return mOwner.getComponent<T>();
}

template<typename T>
void Component::createComponent()
{
     mOwner.createComponent<T>();
}

void Component::addComponent(Component *component)
{
    mOwner.addComponent(component);
}

Entity& Component::getEntity()
{
    return mOwner;
}