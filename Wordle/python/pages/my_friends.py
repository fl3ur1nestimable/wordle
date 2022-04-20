from flask import Flask, Blueprint, render_template, session
import sqlite3

my_friends = Blueprint('my_friends',__name__)

@my_friends.route('/my_friends')
def add_friends():
    user = str(session.get("name"))
    db = sqlite3.connect("Wordle/database.db")
    cursor= db.cursor()
    cursor2= db.cursor()
    query= '''SELECT user1 FROM Amis WHERE user2=? AND demand = accepted''',(user,)
    query2 = '''SELECT user2 FROM Amis WHERE user1 =? AND demand = accepted''',(user,)
    cursor.execute(query)
    cursor2.execute(query2)
    L=cursor.fetchall()
    L2=cursor2.fetchall()
    db.close()
    return render_template('my_friends.html',data1=L,data2=L2)