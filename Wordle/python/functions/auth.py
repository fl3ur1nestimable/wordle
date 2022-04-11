import sqlite3

def name_already_exist(name):
    db = sqlite3.connect('database.db')
    cursor = db.cursor()
    cursor.execute(""" SELECT mail FROM users WHERE name=?""",(name,))
    l=cursor.fetchall()
    db.close()
    return (l!=[])

def mail_already_exist(mail):
    db = sqlite3.connect('database.db')
    cursor = db.cursor()
    cursor.execute(""" SELECT name FROM users WHERE mail=?""",(mail,))
    l=cursor.fetchall()
    db.close()
    return (l!=[])


def input_user_db(name,mail,mdp):
    db = sqlite3.connect('database.db')
    cursor = db.cursor()
    cursor.execute(""" INSERT INTO users(name,mail,mdp) values(?,?,?)""",(name,mail,mdp))
    db.commit()
    db.close()
    return 