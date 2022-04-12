from flask import Flask, session

def App():
    app = Flask(__name__)

    app.config["SESSION_PERMANENT"]=False
    app.config["SESSION_TYPE"]="file_system"

    from python.pages.home import home
    from python.pages.Jeu import game
    from python.pages.Search import search
    from python.pages.authentification import authentification
    from python.pages.login import login
    app.register_blueprint(home)
    app.register_blueprint(game)
    app.register_blueprint(search)
    app.register_blueprint(authentification)
    app.register_blueprint(login)
    return app

if __name__ == "__main__":
    app = App()
    app.run(debug=1)