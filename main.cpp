#include <iostream>
#include <boost/signals2/signal.hpp>
#include <cstdint>

using ret_type = void(*)(float, float);

ret_type print_args = [](float x, float y){printf("The arguments are x = %f and y = %f.\n", x, y);};

void print_sum(float x, float y)
{
    std::cout << "The sum is " << x + y << std::endl;
}

struct print_product
{
    void operator()(float x, float y)
    {
        std::cout << "The product is " << x * y << std::endl;
    }
};

class print_diff {
    
    public:
        explicit print_diff(float x = 0, float y = 0)
            : m_x {x}
            , m_y {y}
        {}

        ~print_diff() = default;


        explicit print_diff(const print_diff& ) = default;
        explicit print_diff(print_diff&&      ) = default;

        print_diff& operator= (const print_diff& ) = default;
        print_diff& operator= (print_diff&& )      = default;

        void print() { std::cout << "The difference is " << m_x - m_y << std::endl; }

    private:
        float m_x {0.0};
        float m_y {0.0};
};


int32_t main([[maybe_unused]] int argc, [[maybe_unused]] char const* argv[])
{
    boost::signals2::signal<void(float, float)> sig;

    //Don't work; ERROR:
    //invalid use of incomplete type ‘struct
    //boost::detail::function_traits_helper<void (**)(float, float)>’
    //boost::signals2::signal<ret_type> sig;
    
    // It's correct for using lambda - function.
    sig.connect(print_args);

    // It's correct for using function.
    sig.connect(&print_sum);

    sig.connect(print_product());


    sig.connect([=](float x, float y) {
            print_diff pd(x, y);
            pd.print();
            });

    sig(5.0, 0.3);
    
    return 0;
}


