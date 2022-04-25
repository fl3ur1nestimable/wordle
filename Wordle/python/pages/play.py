from flask import Blueprint,render_template,request

games = Blueprint('games',__name__)

@games.route('/partie',methods=["POST"]) 
def Motus1():
    params=request.form
    longueur=params.get("longueur")
    essais=params.get("essais")
    return render_template("games.html",longueur=longueur,essais=essais)

@games.route('/partiePL',methods=["POST"])
def MotusPL1():
    params=request.form
    longueur=params.get("len")
    essais=params.get("try")
    return render_template("gamesPL.html",longueur=longueur,essais=essais)


def generate_word(longueur):
    pass

def save_word(word):
    pass