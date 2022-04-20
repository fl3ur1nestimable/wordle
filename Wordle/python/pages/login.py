from crypt import methods
from flask import Flask, Blueprint, render_template, request, redirect, flash, session
import sqlite3
from werkzeug.security import generate_password_hash, check_password_hash

login = Blueprint('login',__name__)

@login.route('/login')
def show():
    return render_template("login.html")

@login.route('/login', methods=['POST'])
def connect():

    form = request.form.to_dict()
    email_enter=form['email']
    mdp_enter=form['password']
    db = sqlite3.connect('Wordle/database.db')
    cursor = db.cursor()
    cursor.execute(""" SELECT mdp FROM users WHERE mail = ?;""",(email_enter,))
    mdp_crypt = cursor.fetchall()[0][0]
    db.commit()
    db.close()
    if not(check_password_hash(mdp_crypt,mdp_enter)) :
        flash("Oups, le mail ou mot de passe est éronné")
        return redirect('/login')
    session['user_mail']= mdp_crypt[1]
    return redirect('/home')
        
   