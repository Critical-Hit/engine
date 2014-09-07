#ifndef Core_ResourceView_h
#define Core_ResourceView_h

#include <memory>

#include "ResourceManager.h"

class ResourceView
{
public:
    ResourceView();
    ~ResourceView();

    void Initialize();

    void Update(std::shared_ptr<ResourceManager> resourceManager);

private:
    // Private constructors to disallow access.
    ResourceView(ResourceView const &other);
    ResourceView operator=(ResourceView other);
};

#endif
