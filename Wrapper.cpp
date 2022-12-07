#include <iostream>
#include <memory>
#include <type_traits>

template<typename StoredType>
struct Wrapper {
    template<typename ForwardRef, std::enable_if_t<!std::is_base_of_v<Wrapper, std::remove_cvref_t<StoredType>>, bool> = false>
    explicit Wrapper(ForwardRef&& u)
        : val(std::forward<StoredType>(u))
    {}

    StoredType val;
};

void use_wrapper() {
    std::shared_ptr<int> a = std::make_shared<int>();
    Wrapper<std::shared_ptr<int>> s(a);
    std::cout << std::boolalpha << (a == nullptr) << "\n";
    std::cout << s.val << "\n";
}

// What does this code do?

// 1] Does not compile
// 2] prints false
// 3] prints true
