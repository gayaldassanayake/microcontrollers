from flaskr.database.db import get_db
from flask import jsonify


def insert(temperature_mean, humidity_mean, pressure_mean, light_mean,
           temperature_std, humidity_std, pressure_std, light_std,
           update_time):
    try:
        db = get_db()
        db.execute(
            'INSERT INTO status(temperature_mean, humidity_mean, pressure,light_mean,'
             'temperature_std,humidity_std,pressure_std,light_std, update_time) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?)',
            (temperature_mean, humidity_mean, pressure_mean, light_mean,
             temperature_std, humidity_std, pressure_std, light_std,
             update_time)
        )
        db.commit()
    except Exception as e:
        print(e)
        raise e


def select():
    try:
        db = get_db()
        data = db.execute(
            'SELECT update_time, temperature_mean,humidity_mean,pressure_mean,light_mean,'
            'temperature_std,humidity_std,pressure_std,light_std FROM status order by update_time').fetchall()
        response = []

        for row in data:
            entry = {}

            entry['temperature_mean'] = row[1]
            entry['humidity_mean'] = row[2]
            entry['pressure_mean'] = row[3]
            entry['light_mean'] = row[4]
            entry['temperature_mean'] = row[1]
            entry['humidity_mean'] = row[2]
            entry['pressure_mean'] = row[3]
            entry['light_mean'] = row[4]
            entry['update_time'] = row[0]

            response.append(entry)

        jsonResponse = jsonify(response)
        return jsonResponse

    except Exception as e:
        print(e)
        raise e
