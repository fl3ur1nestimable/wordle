from flask import Flask, Blueprint, render_template, redirect

login = Blueprint('add_friend',__name__)

@login.route('/add_friend')
def add_friends():
    return render_template('add_friend.html')