from flask import Flask, Blueprint, render_template

my_friends = Blueprint('my_friends',__name__)

@my_friends.route('/my_friends')
def add_friends():
    return render_template('my_friends.html')