from flask import Flask, Blueprint, render_template, request, redirect, session, url_for, flash
from python.functions.friends import liste_demandes, accept_invit, refuse_invit
from python.functions.is_connected import test_login

invitations = Blueprint('invitations',__name__)

@invitations.route('/my_friends/invitations')
def show_invit():
    if test_login():
        user = session.get('name')
        data = liste_demandes(user)
        return render_template('invitations.html', data=data)
    else :
        flash("Pour accéder à la page d'amis, veuillez vous connecter à votre compte (ou en créer un). ")
        return redirect('/login')


@invitations.route('/accepter/<user>')
def accepter(user):
    if test_login():
        user1 = session.get('name')
        user2 = user
        accept_invit(user1,user2)
        return redirect(url_for('invitations.show_invit'))
    else :
        flash("Pour accéder à la page d'amis, veuillez vous connecter à votre compte (ou en créer un). ")
        return redirect('/login')


@invitations.route('/refuser/<user>')
def refuser(user):
    if test_login():
        user1 = session.get('name')
        user2 = user
        refuse_invit(user1,user2)
        return redirect(url_for('invitations.show_invit'))
    else :
        flash("Pour accéder à la page d'amis, veuillez vous connecter à votre compte (ou en créer un). ")
        return redirect('/login')