// --------------------------
// projects/date/TestDate.c++
// Copyright (C) 2010
// Glenn P. Downing
// --------------------------

/*
To test the program:
    % g++ -ansi -pedantic -lcppunit -ldl -Wall TestDate.c++ -o TestDate.app
    % valgrind TestDate.app >& TestDate.out
*/

// --------
// includes
// --------

#include <cstring>   // strcmp
#include <sstream>   // ostringstream
#include <stdexcept> // invalid_argument
#include <string>    // ==

#include "cppunit/extensions/HelperMacros.h" // CPPUNIT_TEST, CPPUNIT_TEST_SUITE, CPPUNIT_TEST_SUITE_END
#include "cppunit/TestFixture.h"             // TestFixture
#include "cppunit/TestSuite.h"               // TestSuite
#include "cppunit/TextTestRunner.h"          // TestRunner

#include "Date.h"

// --------
// TestDate
// --------

struct TestDate : CppUnit::TestFixture {
    // ----------------
    // test_valid
    // ----------------

    void test_valid () {
      try {
        const Date<int> x(0, 1, 1600);
        CPPUNIT_ASSERT(!x.valid());}
      catch (std::invalid_argument& e) {
        CPPUNIT_ASSERT(std::strcmp(e.what(), "Date::Date()") == 0);}}
  
    // ----------------
    // test_constructor
    // ----------------

    void test_constructor () {
        try {
            const Date<int> x(1, 1, 1963);
            const Date<int> y(2, 4, 1918);
            const Date<int> z(6, 12, 1777);
            const Date<int> a(8, 9, 1703);
            const Date<int> b(12, 8, 1600);
            const Date<int> c(28, 2, 1900);
            const Date<int> d(31, 4, 1921);
            const Date<int> e(16, 1, 1838);
            const Date<int> f(8, 7, 1632);
            const Date<int> g(21, 11, 1739);
            const Date<int> h(31, 12, 1989);
            CPPUNIT_ASSERT(x.get_days() == 132583);
            CPPUNIT_ASSERT(y.get_days() == 116238);
            CPPUNIT_ASSERT(z.get_days() == 64988);
            CPPUNIT_ASSERT(a.get_days() == 37870 );
            CPPUNIT_ASSERT(b.get_days() ==  224);
            CPPUNIT_ASSERT(c.get_days() ==  109631);
            CPPUNIT_ASSERT(d.get_days() ==  117363);
            CPPUNIT_ASSERT(e.get_days() ==  86943);
            CPPUNIT_ASSERT(f.get_days() ==  11877);
            CPPUNIT_ASSERT(g.get_days() ==  51093);
            CPPUNIT_ASSERT(h.get_days() ==  142444);
		}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(std::strcmp(e.what(), "Date::Date()") == 0);}}
            
    // ----------------
    // test_days_constructor
    // ----------------

    void test_days_constructor () {
        try {
            const Date<int> x(146155);
            std::cout << "the day: " << x.get_day << "\n" << std::endl;
            CPPUNIT_ASSERT(x.get_day() == 28);
            CPPUNIT_ASSERT(x.get_month() == 2);
            CPPUNIT_ASSERT(x.get_year() == 2000);
            const Date<int> y(116238);
            CPPUNIT_ASSERT(y.get_day() == 2);
            CPPUNIT_ASSERT(y.get_month() == 4);
            CPPUNIT_ASSERT(y.get_year() == 1918);
            const Date<int> z(64988);
            CPPUNIT_ASSERT(z.get_day() == 6);
            CPPUNIT_ASSERT(z.get_month() == 12);
            CPPUNIT_ASSERT(z.get_year() == 1777);
            const Date<int> a(37870);
            CPPUNIT_ASSERT(a.get_day() == 8);
            CPPUNIT_ASSERT(a.get_month() == 9);
            CPPUNIT_ASSERT(a.get_year() == 1703);
            const Date<int> b(224);
            CPPUNIT_ASSERT(b.get_day() == 12);
            CPPUNIT_ASSERT(b.get_month() == 8);
            CPPUNIT_ASSERT(b.get_year() == 1600);
            const Date<int> c(109631);
            CPPUNIT_ASSERT(c.get_day() == 28);
            CPPUNIT_ASSERT(c.get_month() == 2);
            CPPUNIT_ASSERT(c.get_year() == 1900);
            const Date<int> d(117363);
            CPPUNIT_ASSERT(d.get_day() == 31);
            CPPUNIT_ASSERT(d.get_month() == 4);
            CPPUNIT_ASSERT(d.get_year() == 1921);
            const Date<int> e(86943);
            CPPUNIT_ASSERT(e.get_day() == 16);
            CPPUNIT_ASSERT(e.get_month() == 1);
            CPPUNIT_ASSERT(e.get_year() == 1838);
            const Date<int> f(11877);
            CPPUNIT_ASSERT(f.get_day() == 8);
            CPPUNIT_ASSERT(f.get_month() == 7);
            CPPUNIT_ASSERT(f.get_year() == 1632);
            const Date<int> g(51093);
            CPPUNIT_ASSERT(g.get_day() == 21);
            CPPUNIT_ASSERT(g.get_month() == 11);
            CPPUNIT_ASSERT(g.get_year() == 1739);
            const Date<int> h(142444);
            CPPUNIT_ASSERT(h.get_day() == 31);
            CPPUNIT_ASSERT(h.get_month() == 12);
            CPPUNIT_ASSERT(h.get_year() == 1989);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(std::strcmp(e.what(), "Date::Date()") == 0);}}

    // -------------
    // test_to_days
    // -------------

    void test_to_days () {
      try {
        const Date<int> x(28, 2, 2000);
        int q = x.to_days();
        CPPUNIT_ASSERT(q == 146155);
        const Date<int> y(2, 4, 1918);
        q = y.to_days();
        CPPUNIT_ASSERT(q == 116238);
        const Date<int> z(6, 12, 1777);
        q = z.to_days();
        CPPUNIT_ASSERT(q == 64988);
        const Date<int> a(8, 9, 1703);
        q = a.to_days();
        CPPUNIT_ASSERT(q == 37870);
        const Date<int> b(12, 8, 1600);
        q = b.to_days();
        CPPUNIT_ASSERT(q == 224);
        const Date<int> c(28, 2, 1900);
        q = c.to_days();
        CPPUNIT_ASSERT(q == 109631);
        const Date<int> d(31, 4, 1921);
        q = d.to_days();
        CPPUNIT_ASSERT(q == 117363);
        const Date<int> e(16, 1, 1838);
        q = e.to_days();
        CPPUNIT_ASSERT(q == 86943);
        const Date<int> f(8, 7, 1632);
        q = f.to_days();
        CPPUNIT_ASSERT(q == 11877);
        const Date<int> g(21, 11, 1739);
        q = g.to_days();
        CPPUNIT_ASSERT(q == 51093);
        const Date<int> h(31, 12, 1989);
        q = h.to_days();
        CPPUNIT_ASSERT(q == 142444);
      }
      catch (std::invalid_argument& e) {
        CPPUNIT_ASSERT(false);}}

    // -------------
    // test_equal_to
    // -------------

    void test_equal_to () {
        try {
            const Date<int> x(28, 2, 2000);
            const Date<int> y(28, 2, 2000);
            const Date<int> x2(1, 1, 2001);
            const Date<int> y2(1, 1, 2001);
            CPPUNIT_ASSERT(x == y);
            CPPUNIT_ASSERT(x2 == y2);
            CPPUNIT_ASSERT(!(x != y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // ---------
    // test_less
    // ---------

    void test_less () {
        try {
            const Date<int> x(27, 2, 2000);
            const Date<int> y(28, 2, 2000);
            CPPUNIT_ASSERT(x <  y);
            CPPUNIT_ASSERT(x <= y);
            CPPUNIT_ASSERT(!(x >  y));
            CPPUNIT_ASSERT(!(x >= y));}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // ---------
    // test_plus
    // ---------

    void test_plus () {
        try {
            const Date<int> x(1, 1, 2000);
            const Date<int> y(1, 1, 2001);
            std::cout << "plus\n" << std::endl;
            CPPUNIT_ASSERT(x + 366 == y);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // ----------
    // test_minus
    // ----------

    void test_minus () {
        try {
            const Date<int> x(1, 1, 2000);
            const Date<int> y(1, 1, 2001);
            std::cout << "minus\n" << std::endl;
            CPPUNIT_ASSERT(y - 366 == x);}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // -----------
    // test_output
    // -----------

    void test_output () {
        try {
            const Date<int> x(16, 6, 2008);
            std::ostringstream out;
            out << x;
            CPPUNIT_ASSERT(out.str() == "16 Jun 2008");}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // --------------
    // test_leap_year
    // --------------

    void test_leap_year () {
        try {
            CPPUNIT_ASSERT(Date<int>(1, 1, 2000).leap_year());}
        catch (std::invalid_argument& e) {
            CPPUNIT_ASSERT(false);}}

    // -----
    // suite
    // -----

    CPPUNIT_TEST_SUITE(TestDate);
    CPPUNIT_TEST(test_valid);
    CPPUNIT_TEST(test_constructor);
    CPPUNIT_TEST(test_days_constructor);
    CPPUNIT_TEST(test_to_days);
    CPPUNIT_TEST(test_equal_to);
    CPPUNIT_TEST(test_less);
    CPPUNIT_TEST(test_plus);
    CPPUNIT_TEST(test_minus);
    CPPUNIT_TEST(test_output);
    CPPUNIT_TEST(test_leap_year);
    CPPUNIT_TEST_SUITE_END();};

// ----
// main
// ----

int main () {
    using namespace std;
    ios_base::sync_with_stdio(false);  // turn off synchronization with C I/O
    cout << "TestDate.c++" << endl;

    CppUnit::TextTestRunner tr;
    tr.addTest(TestDate::suite());
    tr.run();

    cout << "Done." << endl;
    return 0;}

