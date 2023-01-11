#include <gtest/gtest.h>

using namespace std;

#include "Parrot.h"


TEST(ParrotTest, SpeedOfEuropeanParrot) {
    auto *parrot = european_parrot_factory();
    EXPECT_NEAR(12.0, parrot->getSpeed(), 0.0);
    delete parrot;
}

TEST(ParrotTest, SpeedOfAfricanParrot_With_One_Coconut) {
    auto *parrot = african_parrot_factory(1);
    EXPECT_NEAR(3.0, parrot->getSpeed(), 0.0);
    delete parrot;
}

TEST(ParrotTest, SpeedOfAfricanParrot_With_Two_Coconuts) {
    auto *parrot = african_parrot_factory(2);
    EXPECT_NEAR(0.0, parrot->getSpeed(), 0.0);
    delete parrot;
}

TEST(ParrotTest, SpeedOfAfricanParrot_With_No_Coconuts) {
    auto *parrot = african_parrot_factory(0);
    EXPECT_NEAR(12.0, parrot->getSpeed(), 0.0);
    delete parrot;
}

TEST(ParrotTest, SpeedNorwegianBlueParrot_nailed) {
    auto *parrot = norwegian_blue_parrot_factory(1.5, true);
    EXPECT_NEAR(0.0, parrot->getSpeed(), 0.0);
    delete parrot;
}

TEST(ParrotTest, SpeedNorwegianBlueParrot_not_nailed) {
    auto *parrot = norwegian_blue_parrot_factory(1.5, false);
    EXPECT_NEAR(18.0, parrot->getSpeed(), 0.0);
    delete parrot;
}

TEST(ParrotTest, SpeedNorwegianBlueParrot_not_nailed_high_voltage) {
    auto *parrot = norwegian_blue_parrot_factory(4, false);
    EXPECT_NEAR(24.0, parrot->getSpeed(), 0.0);
    delete parrot;
}
