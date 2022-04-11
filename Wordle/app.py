from atexit import register
from flask import Flask
from flask_sqlalchemy import SQLAlchemy

db = SQLAlchemy() #sert pour l'authentification

def App():
    app = Flask(__name__)

    app.config['SECRET_KEY'] = 'secret_key'
    app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///db.sqlite'

    db.init_app(app)

    from python.pages.home import home
    from python.pages.Jeu import game
    from python.pages.Search import search
    from python.pages.authentification import authentification
    from python.pages.connexion import connexion
    app.register_blueprint(home)
    app.register_blueprint(game)
    app.register_blueprint(search)
    app.register_blueprint(authentification)
    app.register_blueprint(connexion)
    return app

if __name__ == "__main__":
    app = App()
    app.run(debug=1)
