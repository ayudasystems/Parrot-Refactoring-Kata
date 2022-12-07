from enum import Enum  # Enum is introduced in Python 3.4.


class ParrotType(Enum):  # If it is not available, just remove it.
    EUROPEAN = 1
    AFRICAN = 2
    NORWEGIAN_BLUE = 3


class Parrot:

    LOAD_FACTOR = 9.0
    BASE_SPEED = 12.0

    def __init__(self, type_of_parrot: ParrotType, number_of_coconuts: int, voltage: int, nailed: bool):
        self._type = type_of_parrot
        self._number_of_coconuts = number_of_coconuts
        self._voltage = voltage
        self._nailed = nailed

    def speed(self):
        if self._type == ParrotType.EUROPEAN:
            return self.BASE_SPEED
        if self._type == ParrotType.AFRICAN:
            return max(0, self.BASE_SPEED - self.LOAD_FACTOR * self._number_of_coconuts)
        if self._type == ParrotType.NORWEGIAN_BLUE:
            if self._nailed:
                return 0
            else:
                return self._compute_base_speed_for_voltage(self._voltage)

        raise ValueError("should be unreachable")

    def _compute_base_speed_for_voltage(self, voltage):
        return min([24.0, voltage * self.BASE_SPEED])
 