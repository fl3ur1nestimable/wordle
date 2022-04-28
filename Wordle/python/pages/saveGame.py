from flask import Blueprint, request, render_template, redirect, url_for, session
from python.database.GameData import saveData,getWordGuesses
from python.functions.is_connected import test_login
save = Blueprint('save',__name__)

@save.route('/save',methods=["POST"])
def saveGame():
    if test_login()==True :
        data=request.data
        data=data.decode('utf-8')
        user_id = session['id']
        data=data.split(',')
        mot,liste = getWordGuesses()
        gameData=[user_id,data[1],data[0],mot,liste]
        saveData(gameData)
    return ""


