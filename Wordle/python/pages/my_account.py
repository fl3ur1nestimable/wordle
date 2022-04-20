from flask import Flask, Blueprint, render_template, redirect
from python.functions.is_connected import test_login

my_account = Blueprint('my_account',__name__)

@my_account.route('/my_account')
def account():
    if (test_login()):
        return render_template('my_account.html')
    return redirect('/login')