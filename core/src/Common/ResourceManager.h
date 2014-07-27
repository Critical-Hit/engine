#ifndef Core_ResourceManager_h
#define Core_ResourceManager_h

class ResourceManager
{
public:
    ResourceManager();
    ~ResourceManager();

private:
    // Private constructors to disallow access.
    ResourceManager(ResourceManager const &other);
    ResourceManager operator=(ResourceManager other);
};

#endif