from flask import Blueprint, request, render_template, redirect, url_for, session
from python.functions.GameData import saveData,getUserId

save = Blueprint('save',__name__)

@save.route('/save',methods=["POST"])
def saveGame():
    if session:
        data=request.data
        data=data.decode('utf-8')
        user_id = getUserId()
        gameData=[user_id,data[0],data[1]]
        saveData(gameData)
    return ""

