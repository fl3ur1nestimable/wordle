import sqlite3
from flask import Blueprint, request, render_template, redirect, url_for

save = Blueprint('save',__name__)

@save.route('/save',methods=["POST"])
def saveGame():
    data=request.form
    #data=data.decode('utf-8')
    #data=data.split(',')
    print(data.get("state"))
    print(data)
    #recupérer id_user
    #saveData() 
    return redirect(url_for('home.wordle'))

def saveData(gameData):
    user_id=gameData[0]
    tries=gameData[1]
    state=gameData[2]
    query='''INSERT INTO Game (id_user,tries,state) VALUES (?,?,?)'''
    db=sqlite3.connect("../database.db")
    db, cursor=db.cursor()
    cursor.executescript(query,(user_id,tries,state))
    db.commit() 
    db.close()