import os

SECRET_KEY = '89775851147'

SQLALCHEMY_DATABASE_URI = f'mysql+mysqlconnector://std_1694_lab6:89775851147@std-mysql.ist.mospolytech.ru/std_1694_lab6'
SQLALCHEMY_TRACK_MODIFICATIONS = False
SQLALCHEMY_ECHO = True

UPLOAD_FOLDER = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'media', 'images')