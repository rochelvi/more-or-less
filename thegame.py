import random

def more_or_less(guess, target):
    if guess == target:
        print("Ты угадал!!!")
        return 0
    elif guess > target:
        print("Меньше")
    else:
        print("Больше")
    return 1


number = random.randint(1, 100)
tries = 1
try:
    guess = int(input("Введите число от 1 до 100: "))
    while more_or_less(guess, number):
        tries += 1
        guess = int(input("Введите число от 1 до 100: "))
    print(f"Количество попыток: {tries}")
except:
    print("ОШИБКА...")