from flask import Flask, Blueprint, render_template, request, flash, redirect
import sqlite3
from python.functions.auth import input_user_db, name_already_exist, mail_already_exist, input_user_db
from werkzeug.security import generate_password_hash, check_password_hash


authentification = Blueprint('authentification',__name__)

@authentification.route('/register')
def register():
    return render_template('register.html')

@authentification.route('/register', methods=['POST'])
def register_user():
    form=request.form.to_dict()
    name_exist = name_already_exist(form['name'])
    email_exist = mail_already_exist(form['email'])

    if name_exist :
        flash("Ce nom d'utilisateur est déjà utilisé, veuillez en choisir un autre")
        return redirect('/register')

    if email_exist :
        flash("Cette adresse mail est déjà utilisée par un compte existant")
        return redirect('/register')

    mdp = generate_password_hash(form['password'], method='sha256')
    print(mdp)
    input_user_db(form['name'],form['email'],mdp)
    return redirect('/home')
    
