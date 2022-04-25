from flask import Blueprint, request, render_template, redirect, url_for, session
from python.functions.GameData import saveData,getUserId

check = Blueprint('check',__name__)

@check.route('/check',methods=["POST"])
def check_word():
    test=[]
    return test
