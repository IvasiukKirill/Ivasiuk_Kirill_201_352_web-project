from string import digits
from unicodedata import digit
from flask import Flask, render_template, request, make_response

app = Flask(__name__)
application = app

url = request

@app.route('/')
def index():
    return render_template('/index.html')

@app.route('/args')
def args():
    return render_template("/args.html")

@app.route('/headers')
def headers():
    return render_template("/headers.html")

@app.route('/cookies')
def cookies():
    response=make_response(render_template('cookies.html'))
    if request.cookies.get('name') is None:
        response.set_cookie('name','qq')
    else:
        response.set_cookie('name','qq', expires=0)
    return response

@app.route('/form', methods=['GET','POST'])
def form():
    return render_template("form.html")

@app.route('/calc', methods=["GET","POST"])
def calc():
    result = None
    error_msg = None
    if request.method == "POST":
        try:
            operand1=float(request.form.get('operand1'))
            operand2=float(request.form.get('operand2'))
            operation=request.form.get('operation')
            if operation == '+':
                result = operand1 + operand2
        except ValueError:
            error_msg = "Пожалуйста, вводите только числа."
        except ZeroDivisionError:
            error_msg = "На ноль делить нельзя."
    response= make_response(render_template("calc.html", result=result))
    return response

@app.route('/phone', methods=['GET','POST'])
def phone():
    input_class=''
    result = None
    error_msg = None
    if request.method == 'POST':
        phones=str(request.form.get('phones'))
        digits_check=None
        for i in phones:
            if i.isdigit()==0 and i!="-" and i!=" " and i!="(" and i!=")" and i!="+" and i!=".":
                error_msg='Недопустимый ввод. В номере телефона встречаются недопустимые символы.'
                input_class = 'is-invalid'
                response= make_response(render_template("phone.html", result=result,error_msg=error_msg,input_class=input_class))
                return response
                

        digits_check=phones
        digits_check=digits_check.replace("-", "").replace(" ",'').replace("+", "").replace("(", "").replace(")", "").replace(".", "")
        if len(digits_check)!=10 and len(digits_check)!=11:
            error_msg="Недопустимый ввод. Неверное количество цифр."
            input_class = 'is-invalid'
            response= make_response(render_template("phone.html", result=result,error_msg=error_msg,input_class=input_class))
            return response
        if len(digits_check)==11:
            input_class='is-valid'
            result=f"8-{digits_check[1:4]}-{digits_check[4:7]}-{digits_check[7:9]}-{digits_check[9:11]}"        
        elif len(digits_check)==10:
            input_class='is-valid'
            result=f"8-{digits_check[0:3]}-{digits_check[3:6]}-{digits_check[6:8]}-{digits_check[8:10]}"
        

    response= make_response(render_template("phone.html", result=result,error_msg=error_msg,input_class=input_class))
    return response
