from flask import Blueprint, render_template

Search = Blueprint('Search',__name__)

@Search.route('/recherche')
def search():
    return render_template('search.html')