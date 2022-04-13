from flask import Flask,Blueprint,render_template

games = Blueprint('games',__name__)

@games.route('/partie',methods=["GET","POST"])
def Motus1():
    
        return render_template("games.html")

@games.route('/partiePL')
def MotusPL1():
    return render_template("gamesPL.html")