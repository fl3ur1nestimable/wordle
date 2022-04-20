import sqlite3

def createDBusers():
    db = sqlite3.connect('Wordle/database.db')
    cursor = db.cursor()
    cursor.executescript(""" DROP TABLE IF EXISTS users;
                    CREATE TABLE users(id_user INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT,mail TEXT, mdp TEXT); """)
    db.commit()
    db.close()


def createDBamis():
    query="""DROP TABLE IF EXISTS Amis;
        CREATE TABLE Amis(  id INTEGER Primary KEY,
                            user1 TEXT, 
                            user2 TEXT, 
                            demand TEXT NOT NULL CHECK (demand in ('accepted','non_accepted')), 
                            FOREIGN KEY(user1) REFERENCES users(name),
                            FOREIGN KEY(user2) REFERENCES users(name)
        );
          """
    db=sqlite3.connect('Wordle/database.db')
    cursor=db.cursor()
    cursor.executescript(query)
    db.commit()
    db.close()


createDBusers()
createDBamis()

