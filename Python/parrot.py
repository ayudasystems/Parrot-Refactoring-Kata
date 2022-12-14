from __future__ import annotations

from abc import ABC
from enum import Enum  # Enum is introduced in Python 3.4.


class ParrotType(Enum):  # If it is not available, just remove it.
    EUROPEAN = 1
    AFRICAN = 2
    NORWEGIAN_BLUE = 3


def parrot_factory(type_of_parrot, number_of_coconuts, voltage, nailed):
    if type_of_parrot == ParrotType.EUROPEAN:
        return EuropeanParrot(type_of_parrot, number_of_coconuts, voltage, nailed)

    elif type_of_parrot == ParrotType.AFRICAN:
        return AfricanParrot(type_of_parrot, number_of_coconuts, voltage, nailed)

    elif type_of_parrot == ParrotType.NORWEGIAN_BLUE:
        return NBParrot(type_of_parrot, number_of_coconuts, voltage, nailed)

    raise ValueError(f"Invalid Parrot: {type_of_parrot}")


class AbstractParrot(ABC):

    def __init__(self, type_of_parrot, number_of_coconuts, voltage, nailed):
        self._type = type_of_parrot
        self._number_of_coconuts = number_of_coconuts
        self._voltage = voltage
        self._nailed = nailed

    def speed(self):
        if self._type == ParrotType.EUROPEAN:
            return self._base_speed()
        if self._type == ParrotType.AFRICAN:
            return max(0, self._base_speed() - self._load_factor() * self._number_of_coconuts)
        if self._type == ParrotType.NORWEGIAN_BLUE:
            if self._nailed:
                return 0
            else:
                return self._compute_base_speed_for_voltage(self._voltage)

        raise ValueError("should be unreachable")

    def _compute_base_speed_for_voltage(self, voltage):
        return min([24.0, voltage * self._base_speed()])

    def _load_factor(self):
        return 9.0

    def _base_speed(self):
        return 12.0


class EuropeanParrot(AbstractParrot):
    pass


class AfricanParrot(AbstractParrot):
    pass


class NBParrot(AbstractParrot):
    pass
