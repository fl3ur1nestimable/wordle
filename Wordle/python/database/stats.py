import  sqlite3
def nb_partie(user):
    db=sqlite3.connect("../database.db")
    cursor=db.cursor()
    query="""SELECT count(*) from Game where  id_user=?"""
    nb=cursor.execute(query,(user,))
    db.close()
    return nb