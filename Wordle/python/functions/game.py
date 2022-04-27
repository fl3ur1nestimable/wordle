import sqlite3

def input_guess(word,guess):
    db = sqlite3.connect('Wordle/database.db')
    cursor = db.cursor()
    cursor.execute("SELECT liste_mots FROM Word WHERE mot= ?",(word,))
    l = cursor.fetchall()[0][0]
    l= l+' '+guess+' |'
    cursor.execute(""" UPDATE Word SET liste_mots=? WHERE mot=?""",(l,word))
    db.commit()
    db.close()



def getDataGame(user_id):
    db = sqlite3.connect('Wordle/database.db')
    cursor = db.cursor()
    cursor.execute("SELECT id_game,tries,state,word,guesses FROM Game WHERE Game.id_user = ? ORDER BY id_game DESC",(user_id,))
    l = cursor.fetchall()
    print(l)
    db.close()
    return l
