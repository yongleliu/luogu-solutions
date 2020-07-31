def func(x):
    sum=1
    for i in range(x):
        sum=sum*x
    return sum
#if __name__ == "__main__":
n=int(input())
print(func(n))