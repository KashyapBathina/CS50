import os
from datetime import datetime, timezone
from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash
from helpers import apology, login_required
import re
from trycourier import Courier
import string
import random
import logging







# automatically inputs students into classes
# sends email to students once gradebook is updated
# forgot password email confirmation
# sends email with code once registered
# hmsdjsdrkcwxfwaw









user = {}

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True


# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///darkmoon.db")

@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET"])
def homepage():
    return render_template("homepage.html")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure email was submitted
        if not request.form.get("email"):
            return apology("must provide email adress", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for email
        rows = db.execute("SELECT * FROM users WHERE email = ?", request.form.get("email"))

        # Ensure email exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid email and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("index.html")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/login.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""

    if request.method == "POST":
        email = request.form.get("email")
        password = request.form.get("password")
        confirmation = request.form.get("confirmation")
        first = request.form.get("first")
        last = request.form.get("last")
        variety = request.form.get("type")
        school = request.form.get("school")
        role = request.form.get("role")
        organization = request.form.get("organization")
        number = request.form.get("number")

        if str(variety) == "none":
            return apology("must choose your account type", 400)


        if str(variety) == "teacher":
            if not email or not password or not confirmation or not first or not last or not school or not role or not number or str(organization) == "none":
                return apology("must fill in all fields", 400)

            if not re.match("^[\dA-Z]{3}-[\dA-Z]{3}-[\dA-Z]{4}$", number):
                return apology("must be a valid phone number", 400)


        if str(variety) == "student" or str(variety) == "gaurdian":
            if not email or not password or not confirmation or not first or not last or str(organization) == "none":
                return apology("must fill in all fields", 400)


        if not re.match(r"^[A-Za-z0-9\.\+_-]+@[A-Za-z0-9\._-]+\.[a-zA-Z]*$", email):
            return apology("must be a valid email address", 400)

        elif password != confirmation:
            return apology("passwords must match", 400)

        if len(db.execute('SELECT email FROM users WHERE email = ?', email)) > 0:
            return apology("email already in use", 400)

        client = Courier(auth_token="dk_prod_MAPAZZ24RRMQ7CGQ5VR7MX6051R8")

        code = ''.join(random.choice(string.ascii_uppercase + string.digits) for _ in range(6))

        resp = client.send_message(
        message={
            "to": {
            "email": (email),
            },
            "data": {
                "name": (first),
                "code": (code),
            },
            "template": "2VC65XG43QM5K5PJEV05YC46NCM9"
        }
        )

        #global gcode
        #gcode = code

        user["code"] = code
        user["email"] = email
        user["password"] = password
        user["name"] = first + ' ' + last
        user["type"] = variety

        return render_template("verification.html", first=first, last=last, password=password, variety=variety, role=role, organization=organization, school=school, email=email, number=number)

    else:
        return render_template("register.html")


@app.route("/verification", methods=["GET", "POST"])
def verification():
    if request.method == "POST":
        usercode = request.form.get("usercode")

        if user["code"] == str(usercode):
            result = db.execute("INSERT INTO users (email, hash, name, type) VALUES(?, ?)", user["name"], generate_password_hash(user["password"]), user["name"], user["type"])
            session["user_id"] = result
            return redirect("/index")

        else:
            return apology("code is incorrect", 400)

    else:
        return render_template("verification.html")


@app.route("/index")
@login_required
def index():
    """Show portfolio of stocks"""

    owns = own_shares()
    total = 0
    for symbol, shares in owns.items():
        result = lookup(symbol)
        name, price = result["name"], result["price"]
        stock_value = shares * price
        total += stock_value
        owns[symbol] = (name, shares, usd(price), usd(stock_value))
    cash = db.execute("SELECT cash FROM users WHERE id = ? ", session["user_id"])[0]['cash']
    return render_template("index.html", owns=owns, cash=usd(cash), total=usd(total))



@app.route("/grades", methods=["GET", "POST"])
@login_required
def blank():
    if request.method == "POST":
        # send message in email once updated
        return apology("hello, world")
    else:
        return apology("hello, kashyap")


def time_now():
    # Get current time
    now_utc = datetime.now(timezone.utc)
    return str(now_utc.date()) + ' @time ' + now_utc.time().strftime("%H:%M:%S")