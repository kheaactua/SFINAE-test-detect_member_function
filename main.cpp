#include <iostream>
#include <type_traits>

template <typename T>
class NoPPV {
   public:
    NoPPV() {
        std::cout << "No PPV" << std::endl;
    }
};

template <typename T>
class HasPPV {
   public:
    HasPPV() {
        std::cout << "Has PPV" << std::endl;
    }

    auto PPV() -> void {};
};

namespace { // {{{

    template <typename T>
    struct has_min_ppv
    {
		template <class, class> class checker;

		template <typename C>
		static std::true_type test(checker<C, decltype(&C::PPV)> *);

		template <typename C>
		static std::false_type test(...);

		typedef decltype(test<T>(nullptr)) type;
		static const bool value = std::is_same<std::true_type, decltype(test<T>(nullptr))>::value;
    };

} // }}}

static_assert(has_min_ppv<HasPPV<int>>::value, "error");
static_assert(!has_min_ppv<NoPPV<int>>::value, "error");

template <typename T>
auto PrintType() -> typename std::enable_if<has_min_ppv<T>::value, void>::type
{
    std::cout << "Choose object WITH ppv" << std::endl;
}

template <typename T>
auto PrintType() -> typename std::enable_if<!has_min_ppv<T>::value, void>::type
{
    std::cout << "Choose object WITHOUT ppv" << std::endl;
}

auto main() -> int
{
    NoPPV<int> t1;
    PrintType<decltype(t1)>();

    HasPPV<int> t2;
    PrintType<decltype(t2)>();

    return 0;
}

/* vim: set ts=4 sw=4 sts=4 expandtab ffs=unix,dos : */
