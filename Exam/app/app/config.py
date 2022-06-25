import os

SECRET_KEY = '89775851147'

SQLALCHEMY_DATABASE_URI = f'mysql+mysqlconnector://std_1694_exam:89775851147@std-mysql.ist.mospolytech.ru/std_1694_exam'
SQLALCHEMY_TRACK_MODIFICATIONS = False
SQLALCHEMY_ECHO = True

UPLOAD_FOLDER = os.path.join(os.path.dirname(os.path.abspath(__file__)), 'media', 'images')

ADMIN_ROLE_ID = 1
MODERATOR_ROLE_ID = 2
USER_ROLE_ID = 3