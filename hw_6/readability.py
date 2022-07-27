def main():
    sentence = input("Text: ")
    letter_num = 0
    word_num = 1
    sentence_num = 0
    
    for i in range(len(sentence)):
        if sentence[i].isalpha():
            letter_num += 1
        
        elif sentence[i] == " ":
            word_num += 1
        
        elif sentence[i] == "." or sentence[i] == "!" or sentence[i] == "?":
            sentence_num += 1
    
    L = letter_num / word_num * 100
    S = sentence_num / word_num * 100
    score = round(0.0588 * L - 0.296 * S - 15.8)
    
    if score > 16:
        print("Grade 16+")
    
    elif score < 1:
        print("Before Grade 1")
    
    else:
        print(f"Grade {score}")

    return

if __name__ == "__main__":
    main()