from flask import Blueprint, render_template,session,redirect
from python.database.GameData import getData
from python.database.stats import *
from python.functions.is_connected import test_login
stats = Blueprint('stats',__name__)


@stats.route('/stats')
def wordle_stats():
    if test_login() == True:
        user_id=session['id']
        data=getData(user_id)
        username=session['name']
        games_nb=len(data)
        win_percentage=getWin(data)
        series=getSeries(data)
        perfs=getPerfs(data)
        return render_template('stats.html',username=username,games_nb=games_nb,win_percentage=win_percentage,series=series,perfs=perfs)
    else :
        return render_template('stats.html',username='username',games_nb=0,win_percentage=0,series=(0,0),perfs=[0,0,0,0,0,0,0,0])
