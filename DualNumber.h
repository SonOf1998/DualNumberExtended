#pragma once

#include <cmath>

struct DualNumber
{
    const double f;     // f(x)     value
    const double d;     // df/dx    value

    inline constexpr DualNumber(double f, double d = 0) : f(f), d(d) {}

    inline constexpr DualNumber operator+(const DualNumber& r) { return DualNumber(f + r.f, d + r.d); }
    inline constexpr DualNumber operator-(const DualNumber& r) { return DualNumber(f - r.f, d - r.d); }
    inline constexpr DualNumber operator*(const DualNumber& r) { return DualNumber(f * r.f, d * r.f + f * r.d); }
    inline constexpr DualNumber operator/(const DualNumber& r) { return DualNumber(f / r.f, (d * r.f - f * r.d) / r.f / r.f); }
};

inline constexpr DualNumber X(double x) { return DualNumber(x, 1); }

// cmath functions arent constexpr
inline DualNumber Sin   (const DualNumber& innerFunction)             { return DualNumber(sin(innerFunction.f), cos(innerFunction.f) * innerFunction.d); }
inline DualNumber Sinh  (const DualNumber& innerFunction)             { return DualNumber(sinh(innerFunction.f), cosh(innerFunction.f) * innerFunction.d);}
inline DualNumber Cos   (const DualNumber& innerFunction)             { return DualNumber(cos(innerFunction.f), -sin(innerFunction.f) * innerFunction.d); }
inline DualNumber Cosh  (const DualNumber& innerFunction)             { return DualNumber(cosh(innerFunction.f), sinh(innerFunction.f) * innerFunction.d);}
inline DualNumber Tan   (const DualNumber& innerFunction)             { return Sin(innerFunction) / Cos(innerFunction); }
inline DualNumber Tanh  (const DualNumber& innerFunction)             { return Sinh(innerFunction) / Cosh(innerFunction); }
inline DualNumber Log   (const DualNumber& innerFunction)             { return DualNumber(log(innerFunction.f), 1 / innerFunction.f * innerFunction.d); }
inline DualNumber Exp   (const DualNumber& innerFunction)             { return DualNumber(exp(innerFunction.f), exp(innerFunction.f) * innerFunction.d); }
inline DualNumber Pow   (const DualNumber& innerFunction, double n)   { return DualNumber(pow(innerFunction.f, n), n * pow(innerFunction.f, n - 1) * innerFunction.d); }
inline DualNumber Sqrt  (const DualNumber& innerFunction)             { return  Pow(innerFunction, 0.5); }
