#include "doctest.h"
#include "NumberWithUnits.hpp"

using namespace std;
using namespace ariel;
TEST_CASE("THROWS")
{
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    CHECK_NOTHROW((NumberWithUnits{2, "m"}));
    CHECK_NOTHROW((NumberWithUnits{1654.32, "m"}));
    CHECK_NOTHROW((NumberWithUnits{-546, "cm"}));
    CHECK_NOTHROW((NumberWithUnits{0, "USD"}));
    CHECK_NOTHROW((NumberWithUnits{3, "ILS"}));
    CHECK_NOTHROW((NumberWithUnits{3, "ILS"} + NumberWithUnits{3, "USD"}));
    CHECK_NOTHROW((NumberWithUnits{3, "km"} + NumberWithUnits{1000000, "cm"}));

    CHECK_THROWS((NumberWithUnits{2, "t"}));
    CHECK_THROWS((NumberWithUnits{100, "m"} + NumberWithUnits{2, "kg"}));
    CHECK_THROWS((NumberWithUnits{1, "ils"}));
    CHECK_THROWS((NumberWithUnits{2, "Km"}));
    CHECK_THROWS((NumberWithUnits{2, "Hour"}));
}

TEST_CASE("NORMAL TESTS")
{
    ifstream units_file{"units.txt"};
    NumberWithUnits::read_units(units_file);
    CHECK(NumberWithUnits{100, "m"} + NumberWithUnits{2, "km"} == NumberWithUnits{2.1, "km"});
    CHECK(NumberWithUnits{100, "m"} + NumberWithUnits{2, "km"} == NumberWithUnits{2100, "m"});

    CHECK(NumberWithUnits{60, "min"} + NumberWithUnits{0.5, "hour"} == NumberWithUnits{90, "min"});

    CHECK(3.5 * NumberWithUnits{1000, "m"} == NumberWithUnits{3500, "m"});
    CHECK(NumberWithUnits{1000, "m"} * 3.5 == NumberWithUnits{3500, "m"});

    CHECK(NumberWithUnits{100, "m"} * 0 == NumberWithUnits{0, "m"});
    CHECK(NumberWithUnits{1500, "m"} == NumberWithUnits{1.5, "km"});
    CHECK(NumberWithUnits{100, "m"} * 1 == NumberWithUnits{100, "m"});

    // CHECK(NumberWithUnits{100, "m"} + NumberWithUnits{2, "km"} == NumberWithUnits{2.1, "km"});
    

}
