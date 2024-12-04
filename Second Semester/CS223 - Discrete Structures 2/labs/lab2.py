import random

Input = []
F = []
H = []
G = []
I = []
J = []
K = []
L = []
M = []
N = []
O = []

for i in range(20):
    x = random.randint(-10, 10)
    Input.append(x)

    y = (4*(pow(x,2)) - 9)
    F.append(y)

    z = ((2 * x)-3)/4
    H.append(z)

#num3 
    three = y + z
    G.append(three)
#4
    four = y - z
    I.append(four)
#5
    five = y * z
    J.append(five)
#6 
    six = y / z
    K.append(six)
#7
    seven = (4*(pow(z,2)) - 9)
    L.append(seven)
#8
    ate = ((2 * y)-3)/4
    M.append(ate)
#9
    nine = (y,x)
    N.append(nine)
#10
    ten = (z,x)
    O.append(ten)

print('\nInput: ', Input, 
      '\nOutput: ', '\n1: ','\n', F, '\n2: ','\n',H)

print('\nF+H: ', '\n', G, 
      '\nF-H: ','\n', I,
      '\nF*H: ','\n', J,
      '\nF/H: ','\n', K,
      '\nF(H): ','\n', L,
      '\nH(F): ','\n', M,
      '\nInverse of F: ','\n', N,
      '\nInverse of H: ','\n', O,)