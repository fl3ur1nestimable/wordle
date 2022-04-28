from flask import Flask,Blueprint,render_template,redirect,session,flash
from python.functions.game import getDataGame
from python.functions.is_connected import test_login

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