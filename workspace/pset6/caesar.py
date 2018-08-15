import cs50
import sys

if len(sys.argv) != 2:
    print("Please try again!")
    exit(1)
    
elif len(sys.argv) == 2:
    key = int(sys.argv[1])
    secretText = cs50.get_string()

    for char in secretText:
        if char.isalpha():
            if char.isupper():
                upperchar = chr(((ord(char) - 65 + key) % 26) + 65)
                print(upperchar, end="")
            elif char.islower():
                lowerchar = chr(((ord(char) - 97 + key) % 26) + 97)
                print(lowerchar, end="")
        else:
            print(char, end="")

print()
exit(0)    
            