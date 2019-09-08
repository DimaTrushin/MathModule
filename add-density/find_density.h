#include <math.h>
#define VCL_FASTEXP
#include "vectorclass/vectormath_exp.h"
#include "vectorclass/vectorclass.h"

#define M_PI 3.14159265358979323846264338327950288
#define one_over_sqrt_two_pi 0.398942280401432702863218082712


template<typename T>
static inline T find_density_0(T &x, T &mean, T &deviation) {
    T one_over_div = 1. / deviation;
    T arg_minus_mean = x - mean;

    return exp(-0.5 * arg_minus_mean * arg_minus_mean
               * one_over_div * one_over_div)
           * one_over_div * one_over_sqrt_two_pi;
}


template<typename T>
static inline T find_density_1(T &x, T &mean, T &deviation) {
    T one_over_div = 1. / deviation;
    T arg_minus_mean = x - mean;

    return - exp(-0.5 * arg_minus_mean * arg_minus_mean
                 * one_over_div * one_over_div)
           * one_over_sqrt_two_pi
           * one_over_div * one_over_div * one_over_div
           * arg_minus_mean;
}


template<typename T>
static inline T find_density_2(T &x, T &mean, T &deviation) {
    T one_over_div = 1. / deviation;
    T arg_minus_mean = x - mean;

    return exp(-0.5 * arg_minus_mean * arg_minus_mean
               * one_over_div * one_over_div)
           * one_over_sqrt_two_pi
           * one_over_div * one_over_div * one_over_div
           * (1. - arg_minus_mean * arg_minus_mean
                   * one_over_div * one_over_div);
}


template<typename T>
constexpr bool is_vector_class =
        std::is_same<std::decay<T>, Vec4f>::value
        || std::is_same<std::decay<T>, Vec2d>::value
        || std::is_same<std::decay<T>, Vec8f>::value
        || std::is_same<std::decay<T>, Vec4d>::value
        ;
