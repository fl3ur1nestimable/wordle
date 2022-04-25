import sqlite3

def createDBusers():
    db = sqlite3.connect('Wordle/database.db')
    cursor = db.cursor()
    cursor.executescript(""" DROP TABLE IF EXISTS users;
                        CREATE TABLE users(id_user INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, 
                                            name TEXT,
                                            mail TEXT, 
                                            mdp TEXT); """)
    db.commit()
    db.close()


def createDBamis():
    query="""DROP TABLE IF EXISTS Amis;
        CREATE TABLE Amis(  id INTEGER NOT NULL Primary KEY AUTOINCREMENT,
                            user1 TEXT, 
                            user2 TEXT, 
                            demand TEXT NOT NULL CHECK (demand in ('accepted','not_accepted')), 
                            FOREIGN KEY(user1) REFERENCES users(name),
                            FOREIGN KEY(user2) REFERENCES users(name)
        );
          """
    db=sqlite3.connect('Wordle/database.db')
    cursor=db.cursor()
    cursor.executescript(query)
    db.commit()
    db.close()

def createDbGame():
    query='''DROP TABLE IF EXISTS Game;
             CREATE TABLE Game(id_game INTEGER Primary KEY AUTOINCREMENT,id_user INTEGER NOT NULL, tries INTEGER NOT NULL, 
             state TEXT NOT NULL CHECK (state in ('win','loss')),
             FOREIGN KEY(id_user) REFERENCES users(id_user));
          '''
    db=sqlite3.connect("Wordle/database.db")
    cursor=db.cursor()
    cursor.executescript(query)
    db.commit()
    db.close()

def createDbWord():
    query='''DROP TABLE IF EXISTS word;
             CREATE TABLE word(mot TEXT);'''
    db=sqlite3.connect("Wordle/database.db")
    db, cursor=db.cursor()
    cursor.executescript(query)
    db.commit()
    db.close()


createDBusers()
createDBamis()
createDbGame()
createDbWord()

