
from crypt import methods
from flask import Flask,Blueprint,render_template

game = Blueprint('game',__name__)

@game.route('/Jeu',methods=["GET","POST"])
def Motus():
    
        return render_template("game.html")


@game.route('/JeuPL',methods=["GET","POST"])

def MotusPL():
    return render_template("gamePL.html")
