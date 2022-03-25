from flask import Flask
def App():
    app = Flask(__name__)

    from python.pages.home import home
    app.register_blueprint(home)
    return app

if __name__ == "__main__":
    app = App()
    app.run(debug=1)
