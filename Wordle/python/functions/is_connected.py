from flask import session

def test_login():
     if session.get("name")!=None:
          return True
     else:
          return False
