import  sqlite3
def nb_partie(user):
    db=sqlite3.connect("Wordle/database.db")
    cursor=db.cursor()
    query="""SELECT count(*) from Game where  id_user=?"""
    cursor.execute(query,(user,))
    (nb,)=cursor.fetchall()[0]
    db.close()
    return nb

def nb_partie_gagné(user):
    db=sqlite3.connect("Wordle/database.db")
    cursor=db.cursor()
    query="""SELECT count(*) from Game where  id_user=? and state=win"""
    cursor.execute(query,(user,))
    (nbv,)=cursor.fetchall()[0]
    nb=nb_partie(user)
    db.close()
    if nb==0:
        return 0
    return nbv/nb

def nb_tries(user,round):
    db=sqlite3.connect("Wordle/database.db")
    cursor=db.cursor()
    query="""SELECT count(*) from Game where  id_user=?and tries=?"""
    cursor.execute(query,(user,round,))
    (nbr,)=cursor.fetchall()[0]
    nb=nb_partie(user)
    db.close()
    if nb==0 :
        return 0
    return nbr/nb

