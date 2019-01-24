'''wap for creating editting and printing polynomial eqn. 
your program shall create for poly eqn by asking one term at a time which shall consist of coefficient and degree of term. 
The editing of poly eqn means providing insert and delete function. 
When insert func called should insert a new term and delete func means delete the desired term from poly eqn.
Printing of poly eqn shall involve sorting the terms on the basis of their degrees.'''

#Author: Vibhor Rawal
x = input('Do you want to create a polynomial equation in X? (y/n) ')

if x == 'y':
	coeff = []
	for i in range(100):
		#print (i)
		coeff.append(0.0)

	while True:
			menu = input('\n\n**** Menu ****\n 1) Insert\n 2) Delete\n 3) Display\n 4) Exit\n')	
			if menu == '1':
				e = int(input('Enter the exponent : '))
				coeff[e] = float(input('Now enter its coefficient : '))

			elif menu == '2':
				e = int(input('Enter the exponent : '))
				coeff[e] = 0

			elif menu == '3':
				print (' f(x) = ', end='')
				for i in range(100):
					#print (i)
					if coeff[99-i]	!= 0:
						if coeff[99-i] > 0:
							print ('+', end='')

						print (str(coeff[99-i]) + 'x^' + str(99-i), end=' ')

			elif menu == '4':
					break;			