from flask import Blueprint, request, render_template, redirect, url_for, session
from python.functions.GameData import saveData,getUserId

save = Blueprint('save',__name__)

@save.route('/save',methods=["POST"])
def saveGame():
    data=request.form
    user_id = getUserId()
    gameData=[user_id,data.get("state"),data.get("try")]
    saveData(gameData)
    return redirect(url_for('home.wordle'))

