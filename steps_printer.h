#pragma once

#include "optimizing_method.h"
#include <iomanip>
#include <iostream>

class steps_printer {
public:
    static void show_steps(const result &s) {
        std::cout << "Total number of function's invocations: " << s.steps.back().number_of_computations << std::endl;
        for (int i = 0; i < s.steps.size(); i++) {
            std::cout << "Iteration " << i + 1 << ":" << std::endl;
             std::cout << std::setprecision(8) << "Current invocations number: " << s.steps[i].number_of_computations
                       << ". Current bounds : ["
                       << s.steps[i].left_bound << ", " << s.steps[i].right_bound << "].";
             std::cout << "Calculated point(s): (" << s.steps[i].calc_x << ", " << s.steps[i].f_cal_x << ")" << std::endl;
             if (s.steps[i].calc_x2.has_value()) {
                 std::cout << " (" << s.steps[i].calc_x2.value() << ", " << s.steps[i].f_calc_2.value() << ")."
                           << std::endl;
             }
        }
        std::cout << std::setprecision(8) << "Function minima is " << s.f_min << " at x = " << s.x_min << std::endl;
    }
};