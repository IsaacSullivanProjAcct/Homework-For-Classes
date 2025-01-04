"""
Question 1
"""
count = [1,2,3,4,5,6,7,8,9,10]
for x in count:
    print(x)

"""
Question 2
"""
l = ["toenail", "papaya", "starfruit"]

for i in l:
    print(i)


"""
Question 3
"""
n = 15

if n > 1:
  
    for i in range(2, (n//2)+1):
      
        if (n % i) == 0:
            print(n, "is not prime")
            break
    else:
        print(n, "is prime")
else:
    print(n, "is not prime")
