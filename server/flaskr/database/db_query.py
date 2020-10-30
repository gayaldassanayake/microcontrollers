from flaskr.database.db import get_db
from flask import jsonify

def insert(temperature, humidity, pressure, light, update_time):
    try:
        db = get_db()
        db.execute(
            'INSERT INTO status(temperature,humidity,pressure,light, update_time) VALUES (?, ?, ?, ?, ?)',
            (temperature, humidity, pressure, light, update_time)
        )
        db.commit()
    except Exception as e:
        print(e)
        raise e


def select():
    try:
        db = get_db()
        data = db.execute(
            'SELECT update_time, temperature,humidity,pressure,light FROM status order by update_time').fetchall()
        response = []

        for row in data:
            entry = {}

            entry['temperature'] = row[1]
            entry['humidity'] = row[2]
            entry['pressure'] = row[3]
            entry['light'] = row[4]
            entry['update_time'] = row[0]

            response.append(entry)

        jsonResponse = jsonify(response)
        return jsonResponse

    except Exception as e:
        print(e)
        raise e

