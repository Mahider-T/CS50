# TODO
from cs50 import get_int
def main():
    height = get_int("Height: ")

    while(height < 1 or height > 8):
        height = get_int("Height: ")

    for i in range(height):
        for j in range(height-1,-1,-1):
            if(i >= j):
                print("#", end = "")
            else:
                print(" ", end = "")
            # print(f"{i}, {j}")

        for j in range(height):
            if(i >= j and j == 0):
                print("  #", end = "")
            elif(i > j):
                print("#", end = "")
            elif(i == j):
                print("#")
        print()



if __name__ == "__main__":
    main()