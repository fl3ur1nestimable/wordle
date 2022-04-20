from flask import Flask, Blueprint, render_template, session
import sqlite3

invitations = Blueprint('invitations',__name__)
accept_invitation = Blueprint('accept_invitation',__name__)
delay_invitation = Blueprint('delay_invitation',__name__)

@invitations.route('/invitations')
def add_friends():
    user = str(session.get("name"))
    db = sqlite3.connect("Wordle/database.db")
    cursor= db.cursor()
    cursor2= db.cursor()
    cursor.execute('''SELECT user1 FROM Amis WHERE user2=? AND demand = "non_accepted" ''',(user,))
    cursor2.execute('''SELECT user2 FROM Amis WHERE user1 =? AND demand = "non_accepted" ''',(user,))
    L=cursor.fetchall()
    L2=cursor2.fetchall()
    db.close()
    return render_template('invitations.html',data1=L,data2=L2,user=user)

@accept_invitation.route('/accept_invitation/<user1>/<user2>')
def accept(user1, user2):
    user = str(session.get("name"))
    db = sqlite3.connect("Wordle/database.db")
    curs= db.cursor()
    curs.execute('''UPDATE Amis SET demand = "accepted" WHERE user1 =? AND user2 =? ''',(user1,user2,))
    cursor= db.cursor()
    cursor2= db.cursor()
    cursor.execute('''SELECT user1 FROM Amis WHERE user2=? AND demand = "non_accepted" ''',(user,))
    cursor2.execute('''SELECT user2 FROM Amis WHERE user1 =? AND demand = "non_accepted" ''',(user,))
    L=cursor.fetchall()
    L2=cursor2.fetchall()
    db.close()
    return render_template('invitations.html',data1=L,data2=L2)

@delay_invitation.route('/delay_invitation/<user1>/<user2>')
def delay(user1, user2):
    user = str(session.get("name"))
    db = sqlite3.connect("Wordle/database.db")
    curs= db.cursor()
    curs.execute(''' DELETE FROM Amis WHEREuser1 =? AND user2 =? ''',(user1,user2,))
    cursor= db.cursor()
    cursor2= db.cursor()
    cursor.execute('''SELECT user1 FROM Amis WHERE user2=? AND demand = "non_accepted" ''',(user,))
    cursor2.execute('''SELECT user2 FROM Amis WHERE user1 =? AND demand = "non_accepted" ''',(user,))
    L=cursor.fetchall()
    L2=cursor2.fetchall()
    db.close()
    return render_template('invitations.html',data1=L,data2=L2)