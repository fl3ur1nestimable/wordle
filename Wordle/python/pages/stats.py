from flask import Blueprint, render_template

stats = Blueprint('stats',__name__)


@stats.route('/stats')
def wordle_stats():
    return render_template('stats.html')