from flask import Blueprint, render_template
from python.functions.GameData import getData
stats = Blueprint('stats',__name__)


@stats.route('/stats')
def wordle_stats():
    return render_template('stats.html')

#fonctions pour les autres stats