def valid_ISBN10(isbn): 
    sum = 0
    place = 1
    for c in isbn :
        print(f"{c}    {place}")
        if c.isdigit() or place == 10 and c == 'X' :
            if c == 'X' :
                sum += ord(c) * place
            else :
                sum += int(c) * place
            place += 1
    print(sum % 11)
    return sum % 11 == 0 and place == 11

print(valid_ISBN10("048665088X"))
