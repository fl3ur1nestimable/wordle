from flask import Blueprint, render_template
import sqlite3

stats = Blueprint('stats',__name__)


@stats.route('/stats')
def wordle_stats():
    return render_template('stats.html')

def getData():
    #get user id
    data=[]
    query='''SELECT id_game,id_user,tries,state FROM Game WHERE Game.id_user = ? '''
    db=sqlite3.connect("../database.db")
    db, cursor=db.cursor()
    cursor.executescript(query)# + user id
    games=cursor.fetchall()
    # format then into data
    db.commit()
    db.close()

#fonctions pour les autres stats