from wsgiref.util import request_uri
from flask import Blueprint, render_template, request, flash, redirect, url_for
from app import db
from models import Course, Category, User, Review
from tools import CoursesFilter, ImageSaver
from flask_login import current_user

bp = Blueprint('courses', __name__, url_prefix='/courses')

PER_PAGE = 3

COURSE_PARAMS = [
    'author_id', 'name', 'category_id', 'short_desc', 'full_desc'
]

def params():
    return { p: request.form.get(p) for p in COURSE_PARAMS }

def search_params():
    return {
        'name': request.args.get('name'),
        'category_ids': request.args.getlist('category_ids'),
    }

@bp.route('/')
def index():
    page = request.args.get('page', 1, type=int)
    courses = CoursesFilter(**search_params()).perform()
    pagination = courses.paginate(page, PER_PAGE)
    courses = pagination.items
    categories = Category.query.all()
    return render_template('courses/index.html',
                           courses=courses,
                           categories=categories,
                           pagination=pagination,
                           search_params=search_params())

@bp.route('/new')
def new():
    categories = Category.query.all()
    users = User.query.all()
    return render_template('courses/new.html',
                           categories=categories,
                           users=users)

@bp.route('/create', methods=['POST'])
def create():

    f = request.files.get('background_img')
    if f and f.filename:
        img = ImageSaver(f).save()

    course = Course(**params(), background_image_id=img.id)
    db.session.add(course)
    db.session.commit()

    flash(f'Курс {course.name} был успешно добавлен!', 'success')

    return redirect(url_for('courses.index'))

@bp.route('/<int:course_id>')
def show(course_id):
    course = Course.query.get(course_id)
    reviews=Review.query.filter(Review.course_id == course_id).order_by(Review.created_at.desc()).limit(5).all()
    cur_review = Review.query.filter(Review.course_id == course_id).filter(Review.user_id == current_user.id).first()
    return render_template('courses/show.html', course=course,reviews=reviews,cur_review=cur_review)

@bp.route('/<int:course_id>/rewiew/create', methods=['POST'])
def create_review(course_id):
    review=Review()
    review.user_id=current_user.id
    review.text=request.form.get("text-review")
    review.rating=request.form.get("rating")
    review.course_id=course_id
    try:
        db.session.add(review)
        db.session.commit()
    except:
        db.session.rollback()
        flash(review.course_id, category='danger')
        return redirect(url_for('courses.show', course_id=course_id))
    return redirect(url_for('courses.show', course_id=course_id))

@bp.route('/<int:course_id>/reviews')   
def reviews(course_id):
    page = request.args.get('page', 1, type=int)
    reviews=Review.query.filter(Review.course_id == course_id).order_by(Review.created_at.desc())
    pagination = reviews.paginate(page, PER_PAGE)
    reviews= pagination.items
    cur_review = Review.query.filter(Review.course_id == course_id).filter(Review.user_id == current_user.id).first()   
    return render_template('courses/reviews.html',reviews=reviews,course_id=course_id,cur_review=cur_review,pagination=pagination)


  