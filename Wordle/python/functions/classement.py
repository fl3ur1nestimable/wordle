import sqlite3
from flask import session
from python.database.stats import nb_tries, nb_partie
from python.functions.friends import liste_amis

def get_id(user):
    db = sqlite3.connect('Wordle/database.db')
    cursor = db.cursor()
    cursor.execute(""" SELECT id_user FROM users WHERE name=?""",(user,))
    (id,)=cursor.fetchall()[0]
    db.close()
    return id

def points(user):
    id = get_id(user)
    points=0
    n = nb_partie(id)
    for k in range(7):
        nb = nb_tries(id,k)
        points+=(nb_tries(id,k)*n)*(8-k)
    return points


def classe_amis(user):
    amis = liste_amis(user)
    print(amis)
    l = []
    for e in amis :
        l.append([e[0],points(e[0])])

    l = sorted(l, key=lambda l: l[1])
    return l


