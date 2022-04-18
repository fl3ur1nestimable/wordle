import sqlite3,json
def createDbGame():
    query='''DROP TABLE IF EXISTS Game;
             CREATE TABLE Game(id_game INTEGER Primary KEY AUTOINCREMENT,id_user INTEGER NOT NULL, tries INTEGER NOT NULL, state TEXT NOT NULL
                               FOREIGN KEY(id_user) REFERENCES users(id_user));
          '''
    db=sqlite3.connect("../database.db")
    db, cursor=db.cursor()
    cursor.executescript(query)
    db.commit()
    db.close()
