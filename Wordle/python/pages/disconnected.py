from flask import Flask, Blueprint, render_template, session, redirect

disconnected = Blueprint('disconnected',__name__)

@disconnected.route('/disconnected')
def deco():
     session.pop('name', None)
     return redirect('/home')