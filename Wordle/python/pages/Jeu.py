from flask import Flask,Blueprint,render_template

game = Blueprint('game',__name__)

@game.route('/Jeu')
def Motus():
    return render_template('game.html')