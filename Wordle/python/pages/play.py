from flask import Blueprint,render_template,request
import random, sqlite3
games = Blueprint('games',__name__)

@games.route('/partie',methods=["POST"]) 
def Motus1():
    params=request.form
    longueur=params.get("longueur")
    essais=params.get("essais")
    word=generate_word(int(longueur))
    save_word(word)
    return render_template("games.html",longueur=longueur,essais=essais)

@games.route('/partiePL',methods=["POST"])
def MotusPL1():
    params=request.form
    longueur=params.get("len")
    essais=params.get("try")
    return render_template("gamesPL.html",longueur=longueur,essais=essais)


def generate_word(longueur):
    f = open('Wordle/static/Dictionnaire/liste_mots.txt', 'r')
    list_de_mots = list()
    for line in f:
        stripped_l = line.strip()
        line_list = stripped_l.split()
        list_de_mots.append(line_list)
    f.close()
    Liste_definitive_mots = []
    for liste in list_de_mots:
        for i in range(len(liste)):
            if len(liste[i]) == longueur:
                Liste_definitive_mots.append(liste[i])
    word = random.choice(Liste_definitive_mots)
    return word

def save_word(word):
    q='''DELETE FROM word;'''
    query='''
            INSERT INTO word (mot) VALUES (?);'''
    db=sqlite3.connect("Wordle/database.db")
    cursor=db.cursor()
    cursor.execute(q)
    cursor.execute(query,(word,))
    db.commit() 
    db.close()