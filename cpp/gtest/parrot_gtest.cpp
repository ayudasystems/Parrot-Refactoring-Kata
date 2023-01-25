#include <gtest/gtest.h>

using namespace std;

#include "Parrot.h"


TEST(ParrotTest, SpeedOfEuropeanParrot) {
    auto parrot = EuropeanParrot();
    EXPECT_NEAR(12.0, parrot.getSpeed(), 0.0);
}

TEST(ParrotTest, SpeedOfAfricanParrot_With_One_Coconut) {
    auto parrot = AfricanParrot(1);
    EXPECT_NEAR(3.0, parrot.getSpeed(), 0.0);
}

TEST(ParrotTest, SpeedOfAfricanParrot_With_Two_Coconuts) {
    auto parrot = AfricanParrot(2);
    EXPECT_NEAR(0.0, parrot.getSpeed(), 0.0);
}

TEST(ParrotTest, SpeedOfAfricanParrot_With_No_Coconuts) {
    auto parrot = AfricanParrot(0);
    EXPECT_NEAR(12.0, parrot.getSpeed(), 0.0);
}

TEST(ParrotTest, SpeedNorwegianBlueParrot_nailed) {
    auto parrot = NorwegianParrot(1.5, true);
    EXPECT_NEAR(0.0, parrot.getSpeed(), 0.0);
}

TEST(ParrotTest, SpeedNorwegianBlueParrot_not_nailed) {
    auto parrot = NorwegianParrot(1.5, false);
    EXPECT_NEAR(18.0, parrot.getSpeed(), 0.0);
}

TEST(ParrotTest, SpeedNorwegianBlueParrot_not_nailed_high_voltage) {
    auto parrot = NorwegianParrot(4, false);
    EXPECT_NEAR(24.0, parrot.getSpeed(), 0.0);
}
