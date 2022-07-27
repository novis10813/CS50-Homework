while True:
    try:
        owed = float(input("Change owed: "))
    except ValueError:
        pass
    else:
        break
    
changes = 0

cents = round(owed * 100)

div_by_25 = cents // 25
remain_cents_25 = cents % 25

changes += div_by_25

div_by_10 = remain_cents_25 // 10
remain_cents_10 = remain_cents_25 % 10

changes += div_by_10

div_by_5 = remain_cents_10 // 5
remain_cents_5 = remain_cents_10 % 5

changes += div_by_5 + remain_cents_5
print(f"{changes}")