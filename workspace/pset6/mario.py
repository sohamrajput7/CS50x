import cs50

print("Height: ", end="")

while True:
    height = cs50.get_int()
    if height >= 0 or height <= 23:
        break
    print("Retry: ", end="")

for i in range(height):
    j = height - 1
    while j > i:
        print(" ", end="")
        j -= 1
    for k in range(i + 2):
        print("#", end="")
    print()