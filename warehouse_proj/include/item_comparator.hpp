#ifndef ITEM_COMPARATOR_HPP
#define ITEM_COMPARATOR_HPP

#include "item.hpp"

template <typename T_> struct ItemComparator
{
    bool operator()(const Item<T_>& fstItem, const Item<T_>& secItem) const
    {
        return std::tie(fstItem.getValue(), fstItem.getId()) <
               std::tie(secItem.getValue(), secItem.getId());
    }
};

#endif
