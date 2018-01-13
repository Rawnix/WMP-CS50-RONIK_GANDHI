def printSpaces(n):
    for i in range(n):
        print(" ", end="");

while True:
    n = int(input("Height: "))
    if n>-1 and n<24:
        break

spaces=n-1

for i in range(n):
    printSpaces(spaces)
    spaces -= 1
    for j in range(i+1):
        print("#", end="")
    print("  ", end="")
    for j in range(i+1):
        print("#", end="")
    print("")
