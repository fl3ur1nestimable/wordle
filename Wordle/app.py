from audioop import add
from flask import Flask


def App():
    app = Flask(__name__)
    app.config['SECRET_KEY'] = '044655fff565dgaaz52dd5'
    from python.pages.home import home
    from python.pages.Jeu import game
    from python.pages.Search import search
    from python.pages.authentification import authentification
    from python.pages.login import login
    from python.pages.stats import stats
    from python.pages.play import games
    from python.pages.saveGame import save
    from python.pages.my_account import my_account
    from python.pages.my_friends import my_friends
    from python.pages.demands import demands

    app.register_blueprint(games)
    app.register_blueprint(home)
    app.register_blueprint(game)
    app.register_blueprint(search)
    app.register_blueprint(authentification)
    app.register_blueprint(login)
    app.register_blueprint(stats)
    app.register_blueprint(save)
    app.register_blueprint(my_account)
    app.register_blueprint(my_friends)
    app.register_blueprint(demands)

    return app

if __name__ == "__main__":
    app = App()
    app.run(debug=1)