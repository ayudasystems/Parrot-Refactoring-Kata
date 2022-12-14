#include <gtest/gtest.h>

using namespace std;

#include <memory>
#include "Parrot.h"

TEST(ParrotTest, SpeedOfEuropeanParrot) {
    std::unique_ptr<Parrot> parrot(parrot_factory(EUROPEAN, 0, 0, false));
    EXPECT_NEAR(12.0, parrot->getSpeed(), 0.0);
}

TEST(ParrotTest, SpeedOfEuropeanParrot_With_One_Coconut) {
    std::unique_ptr<Parrot> parrot(parrot_factory(EUROPEAN, 1, 0, false));
    EXPECT_NEAR(12.0, parrot->getSpeed(), 0.0);
}

TEST(ParrotTest, SpeedOfAfricanParrot_With_One_Coconut) {
    std::unique_ptr<Parrot> parrot(parrot_factory(AFRICAN, 1, 0, false));
    EXPECT_NEAR(3.0, parrot->getSpeed(), 0.0);
}

TEST(ParrotTest, SpeedOfAfricanParrot_With_Two_Coconuts) {
    std::unique_ptr<Parrot> parrot(parrot_factory(AFRICAN, 2, 0, false));
    EXPECT_NEAR(0.0, parrot->getSpeed(), 0.0);
}

TEST(ParrotTest, SpeedOfAfricanParrot_With_No_Coconuts) {
    std::unique_ptr<Parrot> parrot(parrot_factory(AFRICAN, 0, 0, false));
    EXPECT_NEAR(12.0, parrot->getSpeed(), 0.0);
}

TEST(ParrotTest, SpeedNorwegianBlueParrot_nailed) {
    std::unique_ptr<Parrot> parrot(parrot_factory(NORWEGIAN_BLUE, 0, 1.5, true));
    EXPECT_NEAR(0.0, parrot->getSpeed(), 0.0);
}

TEST(ParrotTest, SpeedNorwegianBlueParrot_not_nailed) {
    std::unique_ptr<Parrot> parrot(new Parrot(NORWEGIAN_BLUE, 0, 1.5, false));
    EXPECT_NEAR(18.0, parrot->getSpeed(), 0.0);
}

TEST(ParrotTest, SpeedNorwegianBlueParrot_not_nailed_high_voltage) {
    std::unique_ptr<Parrot> parrot(new Parrot(NORWEGIAN_BLUE, 0, 4, false));
    EXPECT_NEAR(24.0, parrot->getSpeed(), 0.0);
}
