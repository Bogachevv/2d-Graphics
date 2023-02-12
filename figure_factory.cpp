#include "figure_factory.h"

figure *figure_factory::create(figures fig_type) const {
    auto it = factory_.find(fig_type);
    if (it == factory_.end()){
        throw std::runtime_error("Can't create unregister figure");
    }
    return it->second->create();
}
