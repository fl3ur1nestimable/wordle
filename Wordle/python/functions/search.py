import sqlite3
import unidecode 

def liste_users():
    db = sqlite3.connect('Wordle/database.db')
    cursor = db.cursor()
    cursor.execute("SELECT name FROM users ")
    l=cursor.fetchall()
    db.close()
    return l

def liste_users_minus_friends(user):
    db = sqlite3.connect('Wordle/database.db')
    cursor = db.cursor()
    cursor.execute("SELECT name FROM users EXCEPT SELECT user1 FROM Amis WHERE user2=? EXCEPT SELECT user2 FROM Amis WHERE user1=?",(user,user))
    l=cursor.fetchall()
    db.close()
    return l

def recherche(el,liste):
    l = []
    for e in liste :
        if el.casefold().strip() in e[0].casefold().strip() :
            l.append(e[0])
    return l


def demandes_en_cours(user1,user2):
    db = sqlite3.connect('Wordle/database.db')
    cursor = db.cursor()
    cursor.execute("SELECT demand FROM Amis WHERE user1=? AND user2=? ",(user1,user2))
    l=cursor.fetchall()
    for (d,) in l :
        print(d)
    db.close()