from atexit import register
from flask import Flask
def App():
    app = Flask(__name__)

    from python.pages.home import home
    from python.pages.Jeu import game
    from python.pages.Search import Search
    app.register_blueprint(home)
    app.register_blueprint(game)
    app.register_blueprint(Search)
    return app

if __name__ == "__main__":
    app = App()
    app.run(debug=1)
