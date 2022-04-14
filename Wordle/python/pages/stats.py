from flask import Blueprint, render_template

stats = Blueprint('stats',__name__)


@stats.route('/Stats')
def wordle_stats():
    return render_template('stats.html')