import pytest
from parrot import Parrot, ParrotType

@pytest.mark.parametrize("parrot, speed", [
    (Parrot(ParrotType.EUROPEAN, 0, 0, False), 12.0),
    (Parrot(ParrotType.AFRICAN, 1, 0, False), 3.0),
    (Parrot(ParrotType.AFRICAN, 2, 0, False), 0.0),
    (Parrot(ParrotType.AFRICAN, 0, 0, False), 12.0),
    (Parrot(ParrotType.NORWEGIAN_BLUE, 0, 1.5, True), 0.0),
    (Parrot(ParrotType.NORWEGIAN_BLUE, 0, 1.5, False), 18.0),
    (Parrot(ParrotType.NORWEGIAN_BLUE, 0, 4, False), 24.0)

])
def test_speedParrot(parrot, speed):
    assert parrot.speed() == speed
