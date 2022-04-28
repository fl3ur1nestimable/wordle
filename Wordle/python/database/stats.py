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

def getWin(data):
    total = len(data)
    if total!=0:
        part=0
        for game in data:
            if game[2]=='win':
                part+=1
        percent=int((part/total)*100)
        return percent
    return 0

def getPerfs(data):
    perfs=[0,0,0,0,0,0,0,0]
    for game in data:
        if game[2] == 'win':
            i = int(game[1])
            perfs[i-1]+=1
    return perfs

def getSeries(data):
    if len(data)!=0:
        seriesList=[]
        serie=0
        for i in range(len(data)):
            if data[i][2]=='win':
                serie+=1
            else:
                seriesList.append(serie)
                serie=0
        seriesList.append(serie)
        seriesList=[x for x in seriesList if x != 0]
        if len(seriesList)>0:
            actual=seriesList[len(seriesList)-1]
            best=max(seriesList)
            return (actual,best)
    return (0,0)

