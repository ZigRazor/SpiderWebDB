#pragma once

#include <memory>

namespace SPIDERWEBDB
{

    template <class T, class U>
    bool compare_shared_ptr(const std::shared_ptr<T> &a, const std::shared_ptr<U> &b)
    {
        if (a == b)
            return true;
        if (a && b)
            return *a == *b;
        return false;
    }
}