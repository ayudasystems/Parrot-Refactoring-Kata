from __future__ import annotations

from abc import ABC, abstractmethod
from enum import Enum  # Enum is introduced in Python 3.4.


class ParrotType(Enum):  # If it is not available, just remove it.
    EUROPEAN = 1
    AFRICAN = 2
    NORWEGIAN_BLUE = 3


def parrot_factory(type_of_parrot, number_of_coconuts, voltage, nailed):
    if type_of_parrot == ParrotType.EUROPEAN:
        return EuropeanParrot()

    elif type_of_parrot == ParrotType.AFRICAN:
        return AfricanParrot(number_of_coconuts)

    elif type_of_parrot == ParrotType.NORWEGIAN_BLUE:
        return NorwegianBlueParrot(voltage, nailed)

    raise ValueError(f"Invalid Parrot: {type_of_parrot}")


class AbstractParrot(ABC):
    BASE_SPEED : float = 12.0

    @abstractmethod
    def speed(self):
        pass


class EuropeanParrot(AbstractParrot):
    def speed(self):
        return self.BASE_SPEED


class AfricanParrot(AbstractParrot):
    def __init__(self, number_of_coconuts: int):
        self._number_of_coconuts = number_of_coconuts

    def speed(self):
        return max(0, self.BASE_SPEED - self._load_factor() * self._number_of_coconuts)

    def _load_factor(self):
        return 9.0


class NorwegianBlueParrot(AbstractParrot):
    def __init__(self, voltage, nailed):
        self._voltage = voltage
        self._nailed = nailed

    def speed(self):
        if self._nailed:
            return 0
        else:
            return self._compute_base_speed_for_voltage()

    def _compute_base_speed_for_voltage(self):
        return min([24.0, self._voltage * self.BASE_SPEED])