from flask import Blueprint, render_template

connexion = Blueprint('connexion',__name__)

@connexion.route('/connexion')
def wordle():
    return render_template('connexion.html')