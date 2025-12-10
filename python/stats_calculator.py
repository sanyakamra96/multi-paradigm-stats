from collections import Counter
from typing import List, Optional, Tuple


class StatisticsCalculator:
    def __init__(self, data: List[int]) -> None:
        self.data = data

    def mean(self) -> float:
        if not self.data:
            return 0.0
        return sum(self.data) / len(self.data)

    def median(self) -> float:
        if not self.data:
            return 0.0

        sorted_data = sorted(self.data)
        n = len(sorted_data)
        mid = n // 2

        if n % 2 == 1:
            return float(sorted_data[mid])
        else:
            return (sorted_data[mid - 1] + sorted_data[mid]) / 2.0

    def mode(self) -> Optional[Tuple[int, int]]:
        """
        Returns (mode_value, frequency) or None if data is empty.
        If multiple values share the same max frequency, returns one of them.
        """
        if not self.data:
            return None

        counts = Counter(self.data)
        mode_val, freq = counts.most_common(1)[0]
        return mode_val, freq


def main():
    data = [1, 2, 2, 3, 4, 4, 4, 5]
    calc = StatisticsCalculator(data)

    print(f"Input data: {data}")
    print(f"Mean:   {calc.mean():.2f}")
    print(f"Median: {calc.median():.2f}")

    mode_result = calc.mode()
    if mode_result is None:
        print("Mode:   none")
    else:
        mode_val, freq = mode_result
        print(f"Mode:   {mode_val} (frequency {freq})")


if __name__ == "__main__":
    main()
