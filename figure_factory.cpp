#include "figure_factory.h"

figure *figure_factory::create(figures fig_type) const {
    auto it = factory_.find(fig_type);
    if (it == factory_.end()){
        throw std::runtime_error("Can't create unregister figure");
    }
    return it->second->create();
}

figure_factory::~figure_factory() {
    for (auto it = factory_.begin(); it != factory_.end(); ++it){
        delete (it->second);
    }
}