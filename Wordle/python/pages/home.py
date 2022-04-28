from flask import Blueprint, render_template
from python.functions.is_connected import test_login

home = Blueprint('home',__name__)

@home.route('/')
def wordle():
    return render_template('home.html')

@home.route('/home')
def wordle_home():
    is_connected = test_login()
    return render_template('home.html',is_connected=is_connected)

@home.route('/guide')
def oui():
    return render_template('guide.html')