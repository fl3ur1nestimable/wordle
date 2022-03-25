from flask import Flask

app = Flask(__name__)

from python.pages.home import home
app.register_blueprint(home)
