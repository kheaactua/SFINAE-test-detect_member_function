#include <iostream>
#include <type_traits>

#include <boost/tti/has_member_function.hpp>

BOOST_TTI_HAS_MEMBER_FUNCTION(PPV)

class NoPPV {
   public:
    NoPPV() {
        std::cout << "No PPV" << std::endl;
    }
};

class HasPPV {
   public:
    HasPPV() {
        std::cout << "Has PPV" << std::endl;
    }

    auto PPV() -> void {};
};

static_assert(has_member_function_PPV<HasPPV, void>::value, "Error detecting property");
static_assert(!has_member_function_PPV<NoPPV, void>::value, "Error detecting missing property");


template <typename T>
auto PrintType() -> typename std::enable_if<has_member_function_PPV<T, void>::value, void>::type
{
    std::cout << "Choose object WITH ppv" << std::endl;
}

template <typename T>
auto PrintType() -> typename std::enable_if<!has_member_function_PPV<T, void>::value, void>::type
{
    std::cout << "Choose object WITHOUT ppv" << std::endl;
}

auto main() -> int
{
    NoPPV t1;
    PrintType<decltype(t1)>();

    HasPPV t2;
    PrintType<decltype(t2)>();

    return 0;
}

/* vim: set ts=4 sw=4 sts=4 expandtab ffs=unix,dos : */
