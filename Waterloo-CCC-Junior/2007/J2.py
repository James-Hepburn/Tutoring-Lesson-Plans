translation = {
  'CU':'see you',
  ':-)':"I'm happy",
  ':-(': "I'm unhappy", 
  ';-)': 'wink', 
  ':-P': 'stick out my tongue', 
  '(~.~)': 'sleepy', 
  'TA': 'totally awesome', 
  'CCC': 'Canadian Computing Competition', 
  'CUZ': 'because', 
  'TY': 'thank-you', 
  'YW': "you're welcome", 
  'TTYL': 'talk to you later'
}

while True:
    short_form = input()
    if short_form in translation:
        print(translation[short_form])
        if short_form == 'TTYL':
            break
    else:
        print(short_form)
        
