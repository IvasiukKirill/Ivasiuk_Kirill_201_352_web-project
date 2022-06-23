import os

SECRET_KEY = 'kerel'

SQLALCHEMY_DATABASE_URI = f'mysql+mysqlconnector://std_1694_exam:kerel@std-mysql.ist.mospolytech.ru/std_1694_exam'
SQLALCHEMY_TRACK_MODIFICATIONS = False
SQLALCHEMY_ECHO = True

UPLOAD_FOLDER = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'media', 'images')