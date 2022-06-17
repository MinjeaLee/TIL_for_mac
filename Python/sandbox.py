# vigenere cipher
def vigenere(plaintext, key):
    ciphertext = ''
    for i in range(len(plaintext)):
        ciphertext += chr(ord(plaintext[i]) + ord(key[i % len(key)]))
    return ciphertext

a = vigenere('attackatdawn', 'lemon')