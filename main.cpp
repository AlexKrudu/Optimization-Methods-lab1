#include <functional>
#include <cmath>
#include "dichotomy_method.h"
#include "golden_ratio_method.h"
#include "fibonacci_method.h"
#include "parabola_method.h"
#include "brent_method.h"
#include "steps_printer.h"


int main() {
    std::function<long double(long double)> func = [](long double x) {
        return powl(log10l(x - 2), 2) + powl(log10l(10 - x), 2) - powl(x, (0.2));
    };
    std::function<long double(long double)> func1 = [](long double x) {
        return sinl(x) * powl(x, 3);
    };
    auto dichotomy = dichotomy_method();
    auto golden_ratio = golden_ratio_method();
    auto fibonacci = fibonacci_method();
    auto parabola = parabola_method();
    auto brent = brent_method();


    auto brent_r = brent.optimize(func1, 4.0, 6.0, 0.000000000000000025);
    auto deh_r = dichotomy.optimize(func1, -3.0, -1.6, 1e-8);
    auto fibchi_r = fibonacci.optimize(func1, -3.0, -1.6, 1e-8);
    auto parabola_r = parabola.optimize(func1, -3.0, -1.6, 1e-8);
    auto g_ratio_r = golden_ratio.optimize(func1, -3.0, -1.6, 1e-8);
    steps_printer::show_steps(brent_r); // sample use
    return 0;
}
