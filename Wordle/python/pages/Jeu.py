from crypt import methods
from flask import Flask,Blueprint,render_template

game = Blueprint('game',__name__)

@game.route('/Jeu',methods=["GET","POST"])
def Motus():
       # if methods=="POST":
        #    return render_template('games.html')
        #elif methods=="GET":
        #    return render_template("game.html")
    return render_template("games.html")