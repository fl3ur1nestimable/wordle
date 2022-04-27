from flask import Blueprint, request,jsonify
from python.functions.comparaison import *
import json

check = Blueprint('check',__name__)

@check.route('/check')
def check_word():
    guess=request.args.get('guess')
    response=getWord()
    states=compare(guess,response)
    print(states[0])
    jsonres=json.dumps({"s":states[0],"guess_state":states[1]})
    return jsonres

@check.route('/response')
def get_Res():
    response=getWord()
    return response