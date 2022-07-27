import csv
import sys
import os


def main():
    print(os.getcwd())
    f = open(sys.argv[1], "r")
    reader = csv.DictReader(f)
    header = reader.fieldnames[1:]
    return

main()