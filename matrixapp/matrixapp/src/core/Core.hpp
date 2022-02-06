#ifndef Core_hpp
#define Core_hpp

#include <memory>

namespace MatrixApp {
    template<class T>
    using Ref = std::shared_ptr<T>;
}

#endif
