#include <iostream>
#include <boost/signals2/signal.hpp>
#include <cstdint>

auto hw = [](){std::cout << "Hellow world. Hi boost signals2!!!" << std::endl;};

struct hw_func {
    void operator()() {
        std::cout << "Hellow world from func. obj. !!!" << std::endl;
    };
};

int32_t main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
    // step 1. create signal.
    boost::signals2::signal<void()> sig;
    boost::signals2::signal<void()> sig1;

    // step 2. connect hw slot.
    sig.connect(hw);
    sig1.connect(hw_func());

    // step3. call all of the slot;
    sig();
    sig1();

    return 0;
}


