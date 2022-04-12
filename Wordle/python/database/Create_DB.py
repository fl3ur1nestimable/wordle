import sqlite3
def createDB():
    query='''DROP TABLE IF EXISTS Amis;
          CREATE TABLE Amis(id INTEGER Primary KEY);
          '''
    db=sqlite3.connect("../database.db")
    db, cursor=db.cursor()
    cursor.executescript(query)
    db.commit()
    db.close()