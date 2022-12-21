import pytest

from parrot import parrot_factory, ParrotType


def test_factoryThrows():
    with pytest.raises(ValueError):
        parrot_factory("bababouei", 0, 0, False)
    

def test_speedOfEuropeanParrot():
    parrot = parrot_factory(ParrotType.EUROPEAN, 0, 0, False)
    assert parrot.speed() == 12.0


def test_speedOfAfricanParrot_With_One_Coconut():
    parrot = parrot_factory(ParrotType.AFRICAN, 1, 0, False)
    assert parrot.speed() == 3.0


def test_speedOfAfricanParrot_With_Two_Coconuts():
    parrot = parrot_factory(ParrotType.AFRICAN, 2, 0, False)
    assert parrot.speed() == 0.0


def test_speedOfAfricanParrot_With_No_Coconuts():
    parrot = parrot_factory(ParrotType.AFRICAN, 0, 0, False)
    assert parrot.speed() == 12.0


def test_speedNorwegianBlueParrot_nailed():
    parrot = parrot_factory(ParrotType.NORWEGIAN_BLUE, 0, 1.5, True)
    assert parrot.speed() == 0.0


def test_speedNorwegianBlueParrot_not_nailed():
    parrot = parrot_factory(ParrotType.NORWEGIAN_BLUE, 0, 1.5, False)
    assert parrot.speed() == 18.0


def test_speedNorwegianBlueParrot_not_nailed_high_voltage():
    parrot = parrot_factory(ParrotType.NORWEGIAN_BLUE, 0, 4, False)
    assert parrot.speed() == 24.0
