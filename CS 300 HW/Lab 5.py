"""
Takehome Question
"""
n = 11

if n > 1:
  
    for i in range(2, (n//2)+1):
      
        if (n % i) == 0:
            print(n, "is not prime")
            break
    else:
        print(n, "is prime")
else:
    print(n, "is not prime")

"""
Question 1
"""
count = 1
while count <= 10:
    print(count)
    count +=1

"""
Question 2
"""
count = 5
while True:
    print(count)
    count -=1
    if count ==0:
        break