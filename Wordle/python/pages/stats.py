from unicodedata import name
from webbrowser import get
from flask import Blueprint, render_template,session,redirect,url_for,flash
from python.database.GameData import getData
from python.database.stats import *
from python.functions.is_connected import test_login
from python.functions.classement import get_id
from python.functions.friends import is_amis
stats = Blueprint('stats',__name__)


@stats.route('/stats/')
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
        flash('Veuillez vous connecter pour profiter de toutes les fonctionnalités ')
        return redirect("/login")

@stats.route('/stats/<user>')
def stats_friend(user):
    if test_login():
        id=session["id"]
        user_id=get_id(user)
        if id==user_id:
            return redirect("/stats")
        me=session["name"]
        if is_amis(user,me) == True:
            user_id=get_id(user)
            data=getData(user_id)
            username=user
            games_nb=len(data)
            win_percentage=getWin(data)
            series=getSeries(data)
            perfs=getPerfs(data)
            return render_template('stats.html',username=username,games_nb=games_nb,win_percentage=win_percentage,series=series,perfs=perfs)
        return redirect('/home')
    else:
        flash('Veuillez vous connecter pour profiter de toutes les fonctionnalités')
        return redirect('/login')


