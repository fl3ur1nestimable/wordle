from flask import Blueprint, render_template,session
from python.functions.GameData import getData,getUserId
stats = Blueprint('stats',__name__)


@stats.route('/stats')
def wordle_stats():
    ex=[
        ('13','5','loss','Fl3ur'),
        ('12','5','win','Fl3ur'),
        ('11','2','win','Fl3ur'),
        ('10','8','loss','Fl3ur'),
        ('9','6','win','Fl3ur'),
        ('8','3','loss','Fl3ur'),
        ('7','4','win','Fl3ur'),
        ('6','6','loss','Fl3ur'),
        ('5','1','win','Fl3ur'),
        ('4','2','win','Fl3ur'),
        ('3','8','win','Fl3ur'),
        ('2','4','win','Fl3ur'),
        ('1','5','loss','Fl3ur'),
        ('0','8','win','Fl3ur'),
    ]
    name=ex[0][3]
    nb=len(ex)
    w=getWin(ex)
    s=getSeries(ex)
    p=getPerfs(ex)
    if session:
        user_id=getUserId()
        data=getData(user_id)
        username=data[0][3]
        games_nb=len(data)
        win_percentage=getWin(data)
        series=getSeries(data)
        perfs=getPerfs(data)
        return render_template('stats.html',username=username,games_nb=games_nb,win_percentage=win_percentage,series=series,perfs=perfs)
    else:
        return render_template('stats.html',username=name,games_nb=nb,win_percentage=w,series=s,perfs=p)


def getWin(data):
    total = len(data)
    part=0
    for game in data:
        if game[2]=='win':
            part+=1
    percent=int((part/total)*100)
    return percent

def getPerfs(data):
    perfs=[0,0,0,0,0,0,0,0]
    for game in data:
        if game[2] == 'win':
            i = int(game[1])
            perfs[i-1]+=1
    return perfs

def getSeries(data):
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
    actual=seriesList[-1]
    best=max(seriesList)
    return (actual,best)