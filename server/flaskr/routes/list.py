import functools

from flask import (Blueprint, request)

from flaskr.database.db import get_db


from flaskr.database.db_query import select

bp = Blueprint('list', __name__, )


@bp.route('/list', methods=['GET'])
def update():
    if request.method == 'GET':
        try:
            response = select()
            return response, 200
            
        except:
            return 'Error while listing', 404
        
    return '', 404
