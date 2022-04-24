import sqlite3
from flask import session

def getData(user_id):
    query='''SELECT id_game,tries,state, FROM Game WHERE Game.id_user = ? ORDER BY id_game DESC;'''
    db=sqlite3.connect("Wordle/database.db")
    db, cursor=db.cursor()
    cursor.executescript(query,user_id)
    games=cursor.fetchall()
    db.commit()
    db.close()
    return games

def saveData(gameData):
    user_id=gameData[0]
    tries=gameData[1]
    state=gameData[2]
    query='''INSERT INTO Game (id_user,tries,state) VALUES (?,?,?);'''
    db=sqlite3.connect("Wordle/database.db")
    db, cursor=db.cursor()
    cursor.executescript(query,(user_id,tries,state))
    db.commit() 
    db.close()

def getUserId():
    mail=session['user_mail']
    query='''SELECT id_user FROM users WHERE users.mail = ?;'''
    db=sqlite3.connect("Wordle/database.db")
    db, cursor=db.cursor()
    cursor.executescript(query,mail)
    res=cursor.fetchall()[0]
    db.commit()
    db.close()
    return res