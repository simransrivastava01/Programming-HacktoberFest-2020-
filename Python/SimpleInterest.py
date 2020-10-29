Balance = float(input("Enter the principal amount: "))
time = int(input("Enter the number of years in years: "))
rate = int(input("Enter the rate as a % : "))

rate = rate/100

Interest = 0.0

print("%4s%18s%10s%16s" % \
      ("Year", "Starting balance",
       "Interest", "Ending balance"))#prints in tabular form

for year in range(1, time +1):
    interest_of_one_year = Balance * rate #yearly interest
    endBalance = Balance +interest_of_one_year
    print("%4s%18.2f%10.2f%16.2f" % \
          (year, Balance, interest_of_one_year ,endBalance))
    Balance = endBalance #amount at end of each  year
    Interest += interest_of_one_year #total interest earned in time years

print("Ending balance: $%0.2f" % endBalance) #final amount
print("Total interest earned: $%0.2f" % Interest) #prints total interest earned