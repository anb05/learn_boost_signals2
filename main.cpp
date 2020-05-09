#include <iostream>
#include <boost/signals2/signal.hpp>
#include <cstdint>

// combiner which returns the maximum value returned by all slots

template<typename T> 
struct maximum {
    typedef T result_type;

    template<typename InputIterator> 
    T operator()(InputIterator first, InputIterator last) const
    {
        // If there are no slots to call, just return the default-constreucted value
        if (first == last) {
            return T();
        }

        T max_value = *first++;
        while (first != last) {
            if (max_value < *first) {
                max_value = *first;
            }
            ++first;
        }

        return max_value;
    }
};

int32_t main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{    
    // We actually use this new function object type by installing it as
    // a combiner for our signal. The combiner template argument follows
    // the signal's calling signature:
    boost::signals2::signal<float (float, float), maximum<float>> sig;

    sig.connect([](float x, float y){return x * y;});
    sig.connect([](float x, float y){return x / y;});
    sig.connect([](float x, float y){return x + y;});
    sig.connect([](float x, float y){return x - y;});

    std::cout << "Maximum: ";
    std::cout << sig(5, 3);
    std::cout << std::endl;
    
    return 0;
}


