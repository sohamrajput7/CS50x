import cs50

coin_counter = 0
print("O hai! How much change is owed?")

while True:
    input_change = cs50.get_float()
    if input_change > 0:
        break
    print("Retry: ", end="")

change_cents = round(input_change * 100)

while change_cents >= 25:
    change_cents -= 25
    coin_counter += 1
    
while change_cents >= 10:
    change_cents -= 10
    coin_counter += 1
    
while change_cents >= 5:
    change_cents -= 5
    coin_counter += 1
    
while change_cents >= 1:
    change_cents -= 1
    coin_counter += 1
    
print(coin_counter)