from flask import Flask, Blueprint, render_template, request, redirect, session, url_for
from python.functions.friends import liste_demandes, accept_invit, refuse_invit

invitations = Blueprint('invitations',__name__)

@invitations.route('/my_friends/invitations')
def show_invit():
    user = session.get('name')
    data = liste_demandes(user)
    return render_template('invitations.html', data=data)


@invitations.route('/accepter/<user>')
def accepter(user):
    user1 = session.get('name')
    user2 = user
    accept_invit(user1,user2)
    return redirect(url_for('invitations.show_invit'))


@invitations.route('/refuser/<user>')
def refuser(user):
    user1 = session.get('name')
    user2 = user
    refuse_invit(user1,user2)
    return redirect(url_for('invitations.show_invit'))