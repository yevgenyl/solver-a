#pragma once
#include <complex>

#define EPSILON 0.0001

using namespace std;

namespace solver{

    class RealVariable{

        private:

        public:
        friend const RealVariable operator^ (RealVariable r, double d);
        friend const RealVariable operator* (double d, RealVariable r);
        friend const RealVariable operator* (RealVariable r, double d);
        friend const RealVariable operator* (RealVariable r1, RealVariable r2);
        friend const RealVariable operator/ (double d, RealVariable r);
        friend const RealVariable operator/ (RealVariable r, double d);
        friend const RealVariable operator/ (RealVariable r1, RealVariable r2);
        friend const RealVariable operator- (RealVariable r, double d);
        friend const RealVariable operator- (double d, RealVariable r);
        friend const RealVariable operator- (RealVariable r1, RealVariable r2);
        friend const RealVariable operator+ (RealVariable r, double d);
        friend const RealVariable operator+ (double d, RealVariable r);
        friend const RealVariable operator+ (RealVariable r1, RealVariable r2);
        friend const RealVariable operator== (RealVariable r, double d);
        friend const RealVariable operator== (double d, RealVariable r);
        friend const RealVariable operator== (RealVariable r1, RealVariable r2);
    };

    class ComplexVariable{

        private:

        public:
        friend const ComplexVariable operator^ (ComplexVariable c, double d);
        friend const ComplexVariable operator* (double d, ComplexVariable c);
        friend const ComplexVariable operator* (ComplexVariable c, double d);
        friend const ComplexVariable operator* (ComplexVariable c1, ComplexVariable c2);
        friend const ComplexVariable operator* (ComplexVariable c1, complex<double> c2);
        friend const ComplexVariable operator* (complex<double> c1, ComplexVariable c2);
        friend const ComplexVariable operator/ (double d, ComplexVariable c);
        friend const ComplexVariable operator/ (ComplexVariable c, double d);
        friend const ComplexVariable operator/ (ComplexVariable c1, ComplexVariable c2);
        friend const ComplexVariable operator/ (ComplexVariable c1, complex<double> c2);
        friend const ComplexVariable operator/ (complex<double> c1, ComplexVariable c2);
        friend const ComplexVariable operator- (ComplexVariable c, double d);
        friend const ComplexVariable operator- (double d, ComplexVariable c);
        friend const ComplexVariable operator- (ComplexVariable c1, ComplexVariable c2);
        friend const ComplexVariable operator- (ComplexVariable c1, complex<double> c2);
        friend const ComplexVariable operator- (complex<double> c1, ComplexVariable c2);
        friend const ComplexVariable operator+ (ComplexVariable c1, double d);
        friend const ComplexVariable operator+ (double d, ComplexVariable c1);
        friend const ComplexVariable operator+ (ComplexVariable c1, ComplexVariable c2);
        friend const ComplexVariable operator+ (ComplexVariable c1, complex<double> c2);
        friend const ComplexVariable operator+ (complex<double> c1, ComplexVariable c2);
        friend const ComplexVariable operator== (ComplexVariable c, double d);
        friend const ComplexVariable operator== (double d, ComplexVariable c);
        friend const ComplexVariable operator== (ComplexVariable c1, ComplexVariable c2);
        friend const ComplexVariable operator== (ComplexVariable c1, complex<double> c2);
        friend const ComplexVariable operator== (complex<double> c1, ComplexVariable c2);
    };
    
    const double solve(RealVariable real);
    const complex<double> solve(ComplexVariable cpx);

};
