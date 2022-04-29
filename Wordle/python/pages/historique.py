from flask import Flask,Blueprint,render_template,redirect,session,flash
from python.functions.game import getDataGame
from python.functions.is_connected import test_login
from python.functions.friends import is_amis
from python.functions.classement import get_id

historique = Blueprint('historique',__name__)

@historique.route('/historique')
def show_histo():
    if test_login():
        id_user = session.get('id')
        data = getDataGame(id_user)
        empty = False
        if data == None:
            empty = True
        return render_template('historique.html',data=data,empty=empty)
    else:
        flash('Veuillez vous connecter pour profiter de toutes les fonctionnalités ')
        return redirect('/login')


@historique.route('/historique/<user>')
def show_histo_friend(user):
    if test_login():
        username = session.get('name')
        if is_amis(user,username):
            id=get_id(user)
            data = getDataGame(id)
            empty = False
            if data == None:
                empty = True
            return render_template('historique.html',data=data,empty=empty,username=username)
        return redirect('/home')
    else:
        flash('Veuillez vous connecter pour profiter de toutes les fonctionnalités ')
        return redirect('/login')