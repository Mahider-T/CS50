# TODO
from cs50 import get_int
def main():
    height = get_int("Height: ")

    while(height < 1 or height > 8):
        height = get_int("Height: ")

    for i in range(height):
        for j in range(height,-1,-1):
            if(i >= j):
                print("#", end = "")
        print()

    for i in range(height, 0, -1):
        for j in range(height, 0, -1):
            if(i <= j):
                print("#", end = "")
        print()

if __name__ == "__main__":
    main()