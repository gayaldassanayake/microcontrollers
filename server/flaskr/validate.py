from capparselib.parsers import CAPParser


def validateRequest(body):
    try:
        alert_list = CAPParser(body).as_dict()
        alert = alert_list[0]
        # if('cap_info' in alert.keys()):
        #     if('cap_parameter' in alert['cap_info']):

        parameters = alert['cap_info'][0]['cap_parameter']

        for parameter in parameters:
            if(parameter['valueName'] == 'temperature'):
                temperature = float(parameter['value'])
            elif(parameter['valueName'] == 'humidity'):
                humidity = float(parameter['value'])
            elif(parameter['valueName'] == 'pressure'):
                pressure = float(parameter['value'])
            elif(parameter['valueName'] == 'light'):
                light = float(parameter['value'])
            elif(parameter['valueName'] == 'update_time'):
                update_time = str(parameter['value'])

        if(not temperature or not humidity or not pressure or not light or not update_time):
            raise ValueError()

        return (temperature, humidity, pressure, light, update_time)

    except:
        return ValueError()
