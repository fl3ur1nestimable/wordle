from flask import Blueprint, request,jsonify
from python.functions.comparaison import *
from python.functions.game import input_guess
import json

check = Blueprint('check',__name__)

@check.route('/check')
def check_word():
    guess=request.args.get('guess')
    response=getWord()
    states=compare(guess,response)
<<<<<<< HEAD
    if (states[1]=='incorrect') or (states[1]=='found'):
        input_guess(response,guess)
=======
>>>>>>> 3d0730f (MAJ sécurité js)
    jsonres=json.dumps({"s":states[0],"guess_state":states[1]})
    return jsonres

@check.route('/response')
def get_Res():
    response=getWord()
    return response