import functools

from flask import (Blueprint, request)

from flaskr.validate import validateRequest

from flaskr.database.db_query import insert

bp = Blueprint('update', __name__, )


@bp.route('/update', methods=['POST'])
def update():
    if request.method == 'POST':
        try:
            body = request.get_data().decode('utf-8')

            temperature_mean, humidity_mean, pressure_mean, light_mean,
            temperature_std, humidity_std, pressure_std, light_std,
            update_time = validateRequest(body)

            insert(temperature_mean, humidity_mean, pressure_mean, light_mean,
                   temperature_std, humidity_std, pressure_std, light_std,
                   update_time)

            return '', 200

        except:
            return 'Invalid message body format', 404

    return '', 404
