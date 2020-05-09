#include <iostream>
#include <boost/signals2/signal.hpp>
#include <cstdint>

auto hw = [](){std::cout << "Hellow";};

struct hw_func {
    void operator()() {
        std::cout << ", world!!!" << std::endl;
    };
};

int32_t main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
    // step 1. create signal.
    boost::signals2::signal<void()> sig;

    // step 2. connect hw slot.
    sig.connect(hw);
    sig.connect(hw_func());

    // step3. call all of the slot;
    sig();

    return 0;
}


