from flask import Flask,Blueprint,render_template,request

games = Blueprint('games',__name__)

@games.route('/partie',methods=["GET","POST"]) 
def Motus1():
    params=request.args
    longueur=params.get("len")
    essais=params.get("try")
    return render_template("games.html",longueur=longueur,essais=essais)

@games.route('/partiePL',methods=["GET","POST"])
def MotusPL1():
    params=request.args
    longueur=params.get("len")
    essais=params.get("try")
    return render_template("gamesPL.html",longueur=longueur,essais=essais)