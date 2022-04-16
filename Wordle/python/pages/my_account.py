from flask import Flask, Blueprint, render_template, redirect
from python.functions.is_connected import test_login

login = Blueprint('my_account',__name__)

@login.route('/my_account')
def my_account():
    if not test_login():
        return redirect('/login')
    else :
        return render_template('my_account.html')