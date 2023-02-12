#pragma once

#include "./figures.h"

#include <map>

class abstract_figure_creator{
public:
    [[nodiscard]] virtual figure *create() const = 0;

};

template <class C>
class figure_creator : public abstract_figure_creator{
public:
    figure *create() const override { return new C(); }
};

class figure_factory{
    std::map<figures, abstract_figure_creator*> factory_;

public:
    template<class C>
    void reg_figure(figures fig) {
        auto it = factory_.find(fig);
        if (it == factory_.end()){ //not found
            factory_[fig] = new figure_creator<C>();
        }
    }

    [[nodiscard]] figure *create(figures fig_type) const;
};