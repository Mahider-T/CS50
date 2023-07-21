from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/", methods = ["GET", "POST"])
def index():
    if request.method == "GET":
        return render_template("index.html")
    else:
        if request.form.get("color") == "green":
            print("Why green?!")
            return "<h1 style = 'color:green'>Are you Abiy Ahmed?</h1>"
        print("Form submitted!")
        color = request.form.get("color")
        return render_template("color.html", color = color)

