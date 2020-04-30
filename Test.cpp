 
#include "doctest.h"
#include "solver.hpp"

#include <string>
using namespace std;
using namespace solver;

/*
* Helper function for comparing two doubles.
* EPSILON = 0.0001
*/
int areEqual(double a, double b){
    if(fabs(a - b) < EPSILON){
        return 0;
    }else{
        return -1;
    }
}

TEST_CASE("Test linear equations in one variable (foramt: ax + b, where x is a variable and a,b are constants)."){
    RealVariable x;
    CHECK(areEqual((solve(x-7 == 11)), 18) == 0); //1
    CHECK(areEqual((solve(x-0.25 == 2.25)), 2.5) == 0); //2
    CHECK(areEqual((solve(-9*x == 36)), -4) == 0); //3
    CHECK(areEqual((solve(-15*x == -45)), 3) == 0); //4
    CHECK(areEqual((solve(-12*x == -30)), 2.5) == 0); //5
    CHECK(areEqual((solve(8*x+6 == 6)), 0) == 0); //6
    CHECK(areEqual((solve(2*x-3*x == -5+11)), -6) == 0); //7
    CHECK(areEqual((solve(29+11*x+7 == 15*x)), 9) == 0); //8
    CHECK(areEqual((solve(6.4 +2.5*x +2.6 == -3.5*x)), -1.5) == 0); //9
    CHECK(areEqual((solve((3*(1/3)*x)-(2*(1/6)) == x+2.5)), 2) == 0); //10
    CHECK(areEqual((solve(-50*x-10+30*x-11-x == 0)), -1) == 0); //11
    CHECK(areEqual((solve(-4*x+1-(3*x)+(18*x) == 3-x+(5*x))), 2/7) == 0); //12
    CHECK(areEqual((solve(0.5*x + (3/4) -2*x == 2.25-(5*x)+16)), 5) == 0); //13
    CHECK(areEqual((solve(12 +5*(x+4) == 22)), -2) == 0); //14
    CHECK(areEqual((solve(-6+4*(2-x)+2 == 0)), 1) == 0); //15
    CHECK(areEqual((solve(11*(x+6)-76 == 4*(x+1))), 2) == 0); //16
    CHECK(areEqual((solve(6*(x-3) == 18-2*(x+6))), 3) == 0); //17
    CHECK(areEqual((solve(8*(x+4)+6*(x+3) == 1+7*(x+5))), -2) == 0); //18
    CHECK(areEqual((solve(7*(2*x-3)-5*(x-4) == 35-3*(2*x-8))), 4) == 0); //19
    CHECK(areEqual((solve(8*x -(3*x-7) == 3-(5*x+6))), -1) == 0); //20
    CHECK(areEqual((solve(3+(x-7)/4 + (5-4*x)/5 == 9-x)), 15) == 0); //32
    CHECK(areEqual((solve(-7/x == 0.5)), -14) == 0); //35
    CHECK(areEqual((solve(4/x + 2/5 == 6/x)), 5) == 0); //36
    CHECK(areEqual((solve(4/x-5/2 == 5/6-1/x)), 1.5) == 0); //37
    CHECK(areEqual((solve(-1/2+9/(2*x+8)-x/(x+4) == 0)), 1+2/3) == 0); //38
    CHECK(areEqual((solve((3*x-5)/(6-4*x) == -2/3)), 3) == 0); //39
    CHECK(areEqual((solve(1/(x+1) == 7/(x-5))), -2) == 0); //40
    CHECK(areEqual((solve((x+6)/((x^2)-7*x)+1/(x-7) == 0)), -3) == 0); //41
    CHECK(areEqual((solve(8/4*(x-1) == 1/3)), 7) == 0); //42
    CHECK(areEqual((solve(5/4*(x+3) == 2/(x+3)-(3/4))), -2) == 0); //43
    CHECK(areEqual((solve(2/(x-7)-1/(2*x+14) == 4/((x^2)-49))), -9) == 0); //44
    CHECK(areEqual((solve(1/x+1/(x-1) == 5/((x^2)-x))), 3) == 0); //45
}

TEST_CASE("Test quadratic equations in one variable."){
    RealVariable x;
    CHECK(((areEqual((solve((x^2)-(7*x)+10 == 0)), 2) == 0)||(areEqual((solve((x^2)-(7*x)+10 == 0)), 5) == 0))); //1
    CHECK(((areEqual((solve((x^2)+(5*x)-24 == 0)), -8) == 0)||(areEqual((solve((x^2)+(5*x)-24 == 0)), 3) == 0))); //2 
    CHECK(((areEqual((solve((x^2)+(5*x)-24 == 0)), -8) == 0)||(areEqual((solve((x^2)+(5*x)-24 == 0)), 3) == 0))); //3
    CHECK(((areEqual((solve(3*(x^2)-(4*x)-12 == 0)), 3) == 0)||(areEqual((solve(3*(x^2)-(4*x)-12 == 0)), -(4/3)) == 0))); //4
    CHECK(((areEqual((solve((x^2)-121 == 0)), 11) == 0)||(areEqual((solve((x^2)-121 == 0)), -11) == 0))); //6
    CHECK(((areEqual((solve((x^2) == 9)), 3) == 0)||(areEqual((solve((x^2) == 9)), -3) == 0))); //7
    CHECK(((areEqual((solve(4*(x^2) == 9)), 1.5) == 0)||(areEqual((solve(4*(x^2) == 9)), -1.5) == 0))); //8 
    CHECK(((areEqual((solve(4*(x^2)-17 == 28-(x^2))), 3) == 0)||(areEqual((solve(4*(x^2)-17 == 28-(x^2))), -3) == 0))); //9 
    CHECK(((areEqual((solve((x^2)-(3*x) == 0)), 0) == 0)||(areEqual((solve((x^2)-(3*x) == 0)), 3) == 0))); //10
    CHECK(((areEqual((solve(9*(x^2)-(63*x) == 0)), 0) == 0)||(areEqual((solve(9*(x^2)-(63*x) == 0)), 7) == 0))); //11       
}

TEST_CASE("Test complex equations."){
    ComplexVariable x;
    CHECK(((solve((x^2)+9 == 0) == 3i)||(solve((x^2)+9 == 0) == -3i)));
    CHECK(((solve((x^2)-(4*x)+5 == 0) == (2.0+1i))||(solve((x^2)-(4*x)+5 == 0) == (2.0-1i))));
    CHECK(((solve((x^2)-(6*x) + 13 == 0) == (3.0+2i))||(solve((x^2)-(6*x) + 13 == 0) == (3.0-2i))));
    CHECK(solve((x^2) == -1) == 1i);
    CHECK(solve(x-7 == 11) == 18.0+0i);
    CHECK(solve(x-0.25 == 2.25) == 2.5+0i);
    CHECK(solve(-9*x == 36) == -4.0+0i);
    CHECK(solve(-15*x == -45) == 3.0+0i);
    CHECK(solve(-12*x == -30) == 2.5+0i);
    CHECK(solve(8*x+6 == 6) == 0.0+0i);
    CHECK(solve(2*x-3*x == -5+11) == -6.0+0i);
    CHECK(solve(29+11*x+7 == 15*x) == 9.0+0i);
    CHECK(solve(6.4 +2.5*x +2.6 == -3.5*x) == -1.5+0i);
    CHECK(solve((3*(1/3)*x)-(2*(1/6)) == x+2.5) == 2.0+0i);
    CHECK(solve(-50*x-10+30*x-11-x == 0) == -1.0+0i);
    CHECK(solve(0.5*x + (3/4) -2*x == 2.25-(5*x)+16) == 5.0+0i);
    CHECK(solve(12 +5*(x+4) == 22) == -2.0+0i);
    CHECK(solve(-6+4*(2-x)+2 == 0) == 1.0+0i);
    CHECK(solve(11*(x+6)-76 == 4*(x+1)) == 2.0+0i);
    CHECK(solve(6*(x-3) == 18-2*(x+6)) == 3.0+0i);
    CHECK(solve(8*(x+4)+6*(x+3) == 1+7*(x+5)) == -2.0+0i);
    CHECK(solve(7*(2*x-3)-5*(x-4) == 35-3*(2*x-8)) == 4.0+0i);
    CHECK(solve(8*x -(3*x-7) == 3-(5*x+6)) == -1.0+0i);
    CHECK(((solve((x^2)-(7*x)+10 == 0) == 2.0+0i)||(solve((x^2)-(7*x)+10 == 0) == 5.0+0i)));
    CHECK(((solve((x^2)+(5*x)-24 == 0) == -8.0+0i)||(solve((x^2)+(5*x)-24 == 0) == 3.0+0i)));
    CHECK(((solve((x^2)-121 == 0) == 11.0+0i)||(solve((x^2)-121 == 0) == -11.0+0i)));
    CHECK(((solve((x^2) == 9) == 3.0+0i)||(solve((x^2) == 9) == -3.0+0i)));
    CHECK(((solve(4*(x^2) == 9) == 1.5+0i)||(solve(4*(x^2) == 9) == -1.5+0i)));
    CHECK(((solve(4*(x^2)-17 == 28-(x^2)) == 3.0+0i)||(solve(4*(x^2)-17 == 28-(x^2)) == -3.0+0i)));
    CHECK(((solve((x^2)-(3*x) == 0) == 0.0+0i)||(solve((x^2)-(3*x) == 0) == 3.0+0i)));
    CHECK(((solve(9*(x^2)-(63*x) == 0) == 0.0+0i)||(solve(9*(x^2)-(63*x) == 0) == 7.0+0i)));
    CHECK(solve(-7/x == 0.5) == -14.0+0i);
    CHECK(solve(4/x + 2/5 == 6/x) == 5.0+0i);
    CHECK(solve(4/x-5/2 == 5/6-1/x) == 1.5+0i);
    CHECK(solve((3*x-5)/(6-4*x) == -2/3) == 3.0+0i);
    CHECK(solve(1/(x+1) == 7/(x-5)) == -2.0+0i);
    CHECK(solve((x+6)/((x^2)-7*x)+1/(x-7) == 0) == -3.0+0i);
    CHECK(solve(8/4*(x-1) == 1/3) == 7.0+0i);
    CHECK(solve(5/4*(x+3) == 2/(x+3)-(3/4)) == -2.0+0i);
    CHECK(solve(2/(x-7)-1/(2*x+14) == 4/((x^2)-49)) == -9.0+0i);
    CHECK(solve(1/x+1/(x-1) == 5/((x^2)-x)) == 3.0+0i);
}


TEST_CASE("Test throw exceptions."){
    RealVariable x;
    SUBCASE("Check throws for equetions that have no real solution."){
    CHECK_THROWS(solve((x^2) == -1));
    CHECK_THROWS(solve((x^2)+9 == 0));
    CHECK_THROWS(solve((x^2)-(4*x)+5 == 0));
    CHECK_THROWS(solve((x^2)-(6*x) + 13 == 0));
    CHECK_THROWS(solve(-1 == (x^2)));
    CHECK_THROWS(solve(0 == (x^2)+9));
    CHECK_THROWS(solve(0 == (x^2)-(4*x)+5));
    CHECK_THROWS(solve(0 == (x^2)-(6*x) + 13));
    }

    SUBCASE("Check equestions with illegal arithmetical operations or false expression."){
    CHECK_THROWS(solve(2*x + 3 == 2*x));
    CHECK_THROWS(solve(2*x == 2*x + 3));
    CHECK_THROWS(solve(2*x + 2*x + 2*x == 6*x + 3));
    CHECK_THROWS(solve(6*x + 3 == 2*x + 2*x + 2*x));
    CHECK_THROWS(solve(10*x/2 + 3 == 5*x));
    CHECK_THROWS(solve(15*x/3 + 3 == 5*x));
    CHECK_THROWS(solve(20*x/4 + 3 == 5*x));
    CHECK_THROWS(solve(25*x/5 + 3 == 5*x));
    CHECK_THROWS(solve(30*x/6 + 3 == 5*x));
    }
}
