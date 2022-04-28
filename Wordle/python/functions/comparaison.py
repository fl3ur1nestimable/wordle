import sqlite3

def getWord():
    query='''SELECT mot FROM word'''
    db=sqlite3.connect("Wordle/database.db")
    cursor=db.cursor()
    cursor.execute(query)
    data=cursor.fetchall()
    word= data[0][0]
    db.commit() 
    db.close()
    return word

def compare(guess,response):
    l=len(response)
    if len(guess)!=l:
        return [],"incomplete"
    elif not isValid(guess):
        return [],"invalid"
    elif isFound(guess,response):
        return [2 for _ in range(l)],"found"
    else:
        state=getState(guess,response)
        return state,"incorrect"

def getState(guess,response):
    l=len(response)
    response=list(response)
    state=[None for _ in range(l)]
    for i in range(l):
        if guess[i]==response[i]:
            state[i]=2
            response[i]=""
    for j in range(l):
        for k in range(l):
            if guess[j] == response[k]:
                state[j]=1
                response[k]=""   
    for h in range(l):
        if state[h]==None:
            state[h]=0
    return state

def isFound(guess,word):
    return (guess==word)

def isValid(guess):
    f=open("Wordle/static/Dictionnaire/liste_mots.txt")
    words=f.read().splitlines()
    f.close
    return guess in words