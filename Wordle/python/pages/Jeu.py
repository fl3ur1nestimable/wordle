
from crypt import methods
from flask import Flask,Blueprint,render_template

game = Blueprint('game',__name__)

@game.route('/Jeu',methods=["GET","POST"])
def Motus():
        if methods=="POST":
            return render_template('games.html')
        if methods=="GET":
            return render_template("game.html")


@game.route('/wordle')
def wordle():
    return render_template('wordle.html',essais =6, longueur =5)
    


@game.route('/JeuPL',methods=["GET","POST"])

def MotusPL():
    return render_template("gamePL.html")
