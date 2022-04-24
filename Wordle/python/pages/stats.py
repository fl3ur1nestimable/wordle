from flask import Blueprint, render_template,session
from python.functions.GameData import getData,getUserId
stats = Blueprint('stats',__name__)


@stats.route('/stats')
def wordle_stats():
    ex=[
        ('13','5','loss'),
        ('12','5','win'),
        ('11','2','win'),
        ('10','8','loss'),
        ('9','6','win'),
        ('8','3','loss'),
        ('7','4','win'),
        ('6','6','loss'),
        ('5','1','win'),
        ('4','2','win'),
        ('3','8','win'),
        ('2','4','win'),
        ('1','5','loss'),
        ('0','8','loss'),
    ]
    print(len(ex))
    print(getWin(ex))
    print(getSeries(ex))
    print(getPerfs(ex))
    nb=len(ex)
    w=getWin(ex)
    s=getSeries(ex)
    p=getPerfs(ex)
    if session:
        user_id=getUserId()
        username=''
        data=getData(user_id)
        games_nb=len(data)
        win_percentage=getWin(data)
        series=getSeries(data)
        perfs=getPerfs(data)
        return render_template('stats.html',user_id=user_id,username=username,games_nb=games_nb,win_percentage=win_percentage,series=series,perfs=perfs)
    else:
        return render_template('stats.html',user_id=None,username=None,)


def getWin(data):
    total = len(data)
    part=0
    for game in data:
        if game[2]=='win':
            part+=1
    percent=(part/total)*100
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
    
    seriesList=[x for x in seriesList if x != 0]
    print(seriesList)
    actual=seriesList[-1]
    best=max(seriesList)
    return (actual,best)








