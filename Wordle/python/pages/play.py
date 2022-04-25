from flask import Blueprint,render_template,request

games = Blueprint('games',__name__)

@games.route('/partie',methods=["POST"]) 
def Motus1():
    params=request.form
    longueur=params.get("longueur")
    essais=params.get("essais")
    mode = 'classique'
    return render_template("games.html",longueur=longueur,essais=essais,mode=mode)

@games.route('/partiePL',methods=["POST"])
def MotusPL1():
    params=request.form
    longueur=params.get("longueur")
    essais=params.get("essais")
    mode='pl'
    return render_template("games.html",longueur=longueur,essais=essais,mode=mode)


def generate_word(longueur):
    pass

def save_word(word):
    pass