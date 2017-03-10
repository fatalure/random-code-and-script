def jacobi(a,n):
    """
    Jacobi algorithm to find if a is Quadratic Residues of n
    """
    if a<=1:
        print "Jacobi({0},{1})".format(a,n)
        return a
    elif a%2==1:
        if (a%4==3) and (n%4==3):
            print "-Jacobi({0},{1})".format(a,n)
            return -1 * jacobi(n%a, a)
        else:
            print "Jacobi({0},{1})".format(a,n)
            return jacobi(n%a, a)
    else:
        if (n%8==1) or (n%8==7):
            return jacobi(a/2, n)
            print "Jacobi({0},{1})".format(a,n)
        else:
            print "-Jacobi({0},{1})".format(a,n)
            return -1 * jacobi(a/2, n)

def findQR(a,n):
    """
    Naive way to find smallest X fulfilled X^2 Congruent with a (mod n)
    """
    for i in range(1,37907/2+2):
        if (i**2)%n==a:
            return i


print "input a : "
x = input()
print "input n : "
y = input()

if x<=0:
    x = x%y

jacobian = jacobi(x,y)

print "Jacobi({0},{1}) = {2}".format(x, y, jacobian)

if jacobian == 1:
    print "X which fulfilled X^2 Congruent with {0} (mod {1}) is {2}".format(x, y, findQR(x,y))
