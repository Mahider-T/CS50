import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    return apology("TODO")


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        shares = request.form.get("shares")
        username = db.execute("SELECT username FROM users WHERE id = ?", session["user_id"])

        if not symbol or (lookup(symbol) == None):
            return apology("Invalid symbol", 403)
        if not is_integer(int(shares)) or (int(shares) < 1):
            return apology("Invalid number of shares", 403)

        if (float(symbol["price"] * int(shares)) > db.execute("SELECT cash FROM users where username = ?", username)):
            return apology("You are broke bro, can't afford it!", 403)

        today = date.today()
        now = datetime.now()
        
        #get the username from the session id
        #if the user enters amount > balance => aychalm
        #else let him buy. reduct his/her balance
    if request.method == "GET":
        return render_template("buy.html")
    return apology("TODO")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/quote") #change this route back to index or "/"

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        symbol = request.form.get("symbol")
        if not symbol:
            return apology("Field can't be empty", 403)
        result = lookup(symbol)
        return render_template("quoted.html", result = result)
        # return "What is this garbage?"
    else:
        return render_template("quote.html")

    # return apology("TODO")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    if request.method == "POST":
        username = request.form.get("username")
        password = request.form.get("password")
        hashedPassword = generate_password_hash(password, method = 'pbkdf2', salt_length = 16)

        if not (request.form.get("username") and request.form.get("password") and request.form.get("confirmation")):
            return apology("No slot can be empty!", 403)
        entries = db.execute("SELECT * FROM users WHERE username = ?", username)
        if entries:
            return apology("Username already exists", 403)
        db.execute("INSERT INTO users (username, hash) VALUES (?,?)", username, hashedPassword)
        return redirect("/login")

    else:
        return render_template("register.html")
    # return apology("TODO")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
