import sqlite3

def ajoute(user1,user2):
    db = sqlite3.connect('Wordle/database.db')
    cursor = db.cursor()
    cursor.execute(""" INSERT INTO Amis(user1,user2,demand) VALUES (?,?,'not_accepted') ;""",(user1,user2))
    db.commit()
    db.close()

def liste_amis(user):
    db = sqlite3.connect("Wordle/database.db")
    cursor= db.cursor()
    cursor.execute('''SELECT user1 FROM Amis WHERE user2=? AND demand = "accepted" ''',(user,))
    l1=cursor.fetchall()
    cursor.execute('''SELECT user2 FROM Amis WHERE user1 =? AND demand = "accepted" ''',(user,))
    l2=cursor.fetchall()
    db.close()
    return l1+l2

def liste_demandes(user):
    db = sqlite3.connect('Wordle/database.db')
    cursor = db.cursor()
    cursor.execute(""" SELECT user2 FROM Amis WHERE demand='not_accepted' AND user1=?""",(user,))
    l1=cursor.fetchall()
    cursor.execute(""" SELECT user1 FROM Amis WHERE demand='not_accepted' AND user2=?""",(user,))
    l2=cursor.fetchall()
    db.close()
    return l1+l2

def accept_invit(user1,user2):
    db = sqlite3.connect('Wordle/database.db')
    cursor = db.cursor()
    cursor.execute(""" UPDATE Amis SET demand='accepted' WHERE user1=? AND user2=?;""",(user1,user2))
    cursor.execute("DELETE FROM Amis WHERE user1=? AND user2=?",(user2,user1))
    db.commit()
    db.close()

def refuse_invit(user1,user2):
    db = sqlite3.connect('Wordle/database.db')
    cursor = db.cursor()
    cursor.execute(""" DELETE FROM Amis WHERE user1=? AND user2=?;""",(user1,user2))
    db.commit()
    db.close()
