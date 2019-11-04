import cv2 as cv
def encode():
    fname = input('Enter image file name: ')
    img = cv.imread(fname,0)
    with open(input('Enter text file to encode: '),'r') as file:
        text = file.read()


    # print(img)

while(1):
    print('****** MENU ******\n1) ENCODE\n2) DECODE\n3) EXIT')
    choice = input()
    if(choice == '1'):
        encode()
    if choice == '2':
        decode()
    if choice == '3':
        exit()
