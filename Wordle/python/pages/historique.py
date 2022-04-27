from flask import Flask,Blueprint,render_template,redirect,session
from python.functions.game import getDataGame

historique = Blueprint('historique',__name__)

@historique.route('/historique')
def show_histo():
    id_user = session.get('id')
    data = getDataGame(id_user)
    empty = False
    if data == None:
        empty = True
    print(empty)
    return render_template('historique.html',data=data,empty=empty)