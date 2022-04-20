from flask import Flask, Blueprint, render_template, request, redirect, session, url_for
from python.functions.friends import demande,accepte,refuse

demands = Blueprint('demands',__name__)

@demands.route('/demands')
def show():
    user = session.get('name')
    data = demande(user)
    return render_template('demands.html', data=data)


@demands.route('/accepter/<user>')
def accepter(user):
    user1 = session.get('name')
    user2 = user
    accepte(user1,user2)
    return url_for('show')


@demands.route('/refuser/<user>')
def refuser(user):
    user1 = session.get('name')
    user2 = user
    refuse(user1,user2)
    return url_for('show')