import  sqlite3
def nb_partie(user):
    db=sqlite3.connect("../database.db")
    cursor=db.cursor()
    query="""SELECT count(*) from Game where  id_user=?"""
    nb=cursor.execute(query,(user,))
    db.close()
    return nb

def nb_partie_gagné(user):
    db=sqlite3.connect("../database.db")
    cursor=db.cursor()
    query="""SELECT count(*) from Game where  id_user=? and state=win"""
    nbv=cursor.execute(query,(user,))
    nb=nb_partie(user)
    db.close()
    return nbv/nb

def nb_tries(user,round):
    db=sqlite3.connect("../database.db")
    cursor=db.cursor()
    query="""SELECT count(*) from Game where  id_user=?and tries=?"""
    nbr=cursor.execute(query,(user,round,))
    nb=nb_partie(user)
    
    db.close()
    return nbr/nb

