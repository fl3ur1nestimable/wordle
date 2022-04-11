from flask import Blueprint, render_template

search = Blueprint('search',__name__)

@search.route('/recherche')
def search1():
    return render_template('search.html')