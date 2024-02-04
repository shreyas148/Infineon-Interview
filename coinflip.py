import random

# Function to read bias from file
def read_bias():
    bias = 50
    try:
        with open("bias.txt", "r") as file:
            bias = int(file.read())
    except FileNotFoundError:
        pass
    return bias

# Function to simulate a biased coin flip
def coin_flip(bias):
    random_val = random.randint(0, 100)
    if random_val > bias:
        print("tails")
    else:
        print("heads")
    return random_val > bias

def main():
    bias = read_bias()

    while True:
        first_flip = coin_flip(bias)
        second_flip = coin_flip(bias)
        if first_flip and not second_flip:
            print("\nPerson 1 wins!")
            break
        elif not first_flip and second_flip:
            print("\nPerson 2 wins!")
            break
        else:
            print("Toss discarded, flipping again.\n")

main()
