import sqlite3

def createDBusers():
    db = sqlite3.connect('database.db')
    cursor = db.cursor()
    cursor.execute("CREATE TABLE users(id_user INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT,mail TEXT, mdp TEXT) ")
    db.commit()
    db.close()


createDBusers()

