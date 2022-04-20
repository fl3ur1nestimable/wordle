from flask import Flask, Blueprint, render_template, request, redirect, session
import sqlite3
from python.functions.friends import demandes

demands = Blueprint('demands',__name__)

@demands.route('/demands')
def show():
    user = session.get('name')
    data = demandes(user)


