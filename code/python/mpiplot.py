from matplotlib import pyplot as plt
import numpy as np


def main():
    mpis = ["intel", "mpich"]
    maths = ["atlas", "goto", "open", "mkl"]
    f = open("intel_mkl.txt")
    x = []
    y = []
    for mpi in mpis:
        for math in maths:
            filename = mpi + "_" + math + ".txt"
            with open(filename, "r") as f:
                for line in f:
                    l = line.strip('\n').split(" ")
                    x.append(l[0])
                    y.append(l[1])
                    plt.plot(x, y, label=filename)
    plt.legend(loc=left)
    plt.show()


main()
