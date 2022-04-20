import sqlite3

def demande(user):
    db = sqlite3.connect('Wordle/database.db')
    cursor = db.cursor()
    cursor.execute(""" SELECT user2 FROM Amis WHERE demands=not_accepted AND user1=?""",(user,))
    l=cursor.fetchall()
    db.close()
    return l

def accepte(user1,user2):
    db = sqlite3.connect('Wordle/database.db')
    cursor = db.cursor()
    cursor.execute(""" UPDATE Amis SET demands=accepted WHERE user1=? AND user2=?;""",(user1,user2))
    db.commit()
    db.close()

def refuse(user1,user2):
    db = sqlite3.connect('Wordle/database.db')
    cursor = db.cursor()
    cursor.execute(""" DELETE FROM Amis WHERE user1=? AND user2=?;""",(user1,user2))
    db.commit()
    db.close()
