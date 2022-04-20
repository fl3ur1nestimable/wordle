import sqlite3

def demandes(user):
    db = sqlite3.connect('Wordle/database.db')
    cursor = db.cursor()
    cursor.execute(""" SELECT user2 FROM Amis WHERE demands=not_accepted AND user1=?""",(user,))
    l=cursor.fetchall()
    db.close()
    return l
