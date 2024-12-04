def display_menu():
    print("Vending Machine Menu:")
    for i, item in enumerate(items, start=1):
        print(f"{i}. {item['name']} - ₱{item['price']}")

def get_user_choice():
    while True:
        try:
            choice = int(input("Enter the number of the item you want to purchase (1-8): "))
            if 1 <= choice <= 8:
                return choice
            else:
                print("Invalid choice. Please enter a number between 1 and 8.")
        except ValueError:
            print("Invalid input. Please enter a valid number.")

def process_payment(price):
    while True:
        try:
            amount = float(input(f"Insert money (Current price: ₱{price}): ₱"))
            if amount >= price:
                return amount
            else:
                print("Insufficient funds. Please insert the exact amount or more.")
        except ValueError:
            print("Invalid input. Please enter a valid amount.")

def dispense_item(item):
    print(f"Dispensing {item['name']}... \nEnjoy your {item['name']}!")

# Sample items in the vending machine
items = [
    {"name": "Protein Bar: Strawberry", "price": 40.00},
    {"name": "Protein Bar: Chocolate", "price": 40.00},
    {"name": "Protein Bar: Blueberry", "price": 40.50},
    {"name": "Mineral Water: 500ml", "price": 20.00},
    {"name": "VitaMilk: Chocolate", "price": 32.00},
    {"name": "VitaMilk: Vanilla", "price": 32.00},
    {"name": "Cobra: Yellow", "price": 28.00},
    {"name": "Gatorade: Blue", "price": 36.00},
]

def vending_machine():
    display_menu()
    choice = get_user_choice()
    selected_item = items[choice - 1]
    
    amount_inserted = process_payment(selected_item['price'])
    change = amount_inserted - selected_item['price']
    
    dispense_item(selected_item)
    print(f"Thank you for your purchase! Your change: ₱{change:.2f}")

# Run the vending machine
vending_machine()