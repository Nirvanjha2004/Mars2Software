MORSE_CODE_DICT = {
    '.-': 'A', '-...': 'B', '-.-.': 'C', '-..': 'D', '.': 'E', '..-.': 'F',
    '--.': 'G', '....': 'H', '..': 'I', '.---': 'J', '-.-': 'K', '.-..': 'L',
    '--': 'M', '-.': 'N', '---': 'O', '.--.': 'P', '--.-': 'Q', '.-.': 'R',
    '...': 'S', '-': 'T', '..-': 'U', '...-': 'V', '.--': 'W', '-..-': 'X',
    '-.--': 'Y', '--..': 'Z', '-----': '0', '.----': '1', '..---': '2',
    '...--': '3', '....-': '4', '.....': '5', '-....': '6', '--...': '7',
    '---..': '8', '----.': '9', '/': ' '
}

def morse_to_text(morse_code):
    words = morse_code.split(' / ')
    decoded_message = []
    
    for word in words:
        decoded_word = ''.join(MORSE_CODE_DICT[char] for char in word.split())
        decoded_message.append(decoded_word)
    
    return ' '.join(decoded_message)

morse = ".... . .-.. .-.. --- / .-- --- .-. .-.. -.."
print(morse_to_text(morse))
