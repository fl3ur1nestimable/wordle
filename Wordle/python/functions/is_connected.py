from flask import session

def test_login():
     if session.get("user_mail")!=None:
          return True
     else:
          return False
