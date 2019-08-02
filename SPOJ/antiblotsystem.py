t = int(input().strip())

blot = 'machula'

for i in range(t):
    input().strip()
    equation = input().strip()
    if len(equation) !=0:
        equation = equation.split(' ')

        if blot in equation[4]:
            print( equation[0] + ' + ' + equation[2] + ' = ' + str(int(equation[0]) + int(equation[2])) )

        elif blot in equation[2]:
            print( equation[0] + ' + ' + str(int(equation[4]) - int(equation[0])) + ' = ' + equation[4] )

        elif blot in equation[0]:
            print( str(int(equation[4]) - int(equation[2])) + ' + ' + equation[2] + ' = ' + equation[4] )

        else:
            pass
