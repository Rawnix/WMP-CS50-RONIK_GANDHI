def main():
    coins=0
    print("O hai!", end=" ")
    while True:
        amt = float(input("How much change I owed?\n"))
        if amt>=0:
            break
    amt *= 100
    if amt>= 25:
        temp = amt // 25
        amt -= 25*temp
        coins += temp
    if amt>=10:
        temp=amt//10
        amt -= 10*temp
        coins += temp
    if amt>=5:
        temp = amt//5
        amt -= 5*temp
        coins += temp
    if amt>=1:
        temp = amt//1
        amt -= temp
        coins += temp
    print(int(coins));
    exit(0)

main()