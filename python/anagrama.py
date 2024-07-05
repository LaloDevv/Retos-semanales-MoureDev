

def are_anagrams(word1, word2):
    if(word1 != word2):
        return sorted(word1) == sorted(word2)
    else:
        return False
    
    
print(are_anagrams("hola", "hola")) 