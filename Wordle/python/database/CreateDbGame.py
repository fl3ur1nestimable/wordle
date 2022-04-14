import sqlite3
def createDbGame():
    query='''DROP TABLE IF EXISTS Game;
          CREATE TABLE Game(id INTEGER Primary KEY);
          '''
    db=sqlite3.connect("../database.db")
    db, cursor=db.cursor()
    cursor.executescript(query)
    db.commit()
    db.close()

def saveData(gameData):
    #save les données de la game
    pass