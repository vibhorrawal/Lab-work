from stegano import lsb

secret = lsb.hide("im.jpg", "I am hidden text!")
secret.save("img-secret.png")

secret_message = lsb.reveal("img-secret.png")
print(secret_message)
