#!/usr/bin/python3.x


def obtain_partitions(previous, n):
    while True:
        k = 1
        to_subtract = 1
        sign = 1
        previous.append(0)
        while (to_subtract <= n):
            previous[n] += sign * previous[n - to_subtract]
            k = -k if k >= 0 else -k + 1
            sign = -1 if k % 2 == 0 else 1
            to_subtract = int(k * (3 * k - 1) / 2)
        print(previous[n])
        if previous[n] % 1000000 == 0:
            break
        n += 1
    return n


def main():
    partitions = []
    partitions.append(1)
    print(obtain_partitions(partitions, 1))


if __name__ == "__main__":
    main()
