import random
import subprocess
import sys

executable = sys.argv[1] if len(sys.argv) > 1 else "./code"


def check(data, expected):
    result = subprocess.run([executable], input=data.encode(), capture_output=True,
                            check=True)
    assert result.stdout == expected.encode(), (data, result.stdout, expected)


check("1\n", "a" * 100 + "\n")
random.seed(44)
pairs = [("a", "aa"), ("aa", "a"), ("same", "same"), ("aaaa", "b"),
         ("a" * 200, "z" * 200)]
for _ in range(100):
    pairs.append(tuple("".join(random.choices("abcXYZ09", k=random.randint(1, 200)))
                       for _ in range(2)))
for first, second in pairs:
    positions = [-1, 0, len(second) - 1, len(second), len(second) + 1]
    queries = str(len(positions)) + "\n" + "\n".join(map(str, positions)) + "\n"
    chars = "".join((second[i] if 0 <= i < len(second) else "\0") + "\n"
                    for i in positions)
    comparison = str(int(first < second)) + "\n"
    check("2\n" + second + "\n" + queries, chars)
    check(f"3\n{first} {second}\n", comparison)
    check(f"4\n{first} {second}\n", first + second + "\n")
    check(f"0\n{first} {second}\n" + queries,
          chars + f"{len(first)} {len(second)}\n" + comparison +
          first + second + f"\n{len(first) + len(second)}\n")
print("Passed 421 checks across all operation modes.")
