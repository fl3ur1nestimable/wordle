from flask import Blueprint, render_template

home = Blueprint('home',__name__)

@home.route('/')
def wordle():
    return render_template('home.html')

@home.route('/home')
def wordle_home():
    return render_template('home.html')