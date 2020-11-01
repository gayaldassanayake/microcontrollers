from capparselib.parsers import CAPParser


def validateRequest(body):
    try:
        alert_list = CAPParser(body).as_dict()
        alert = alert_list[0]

        parameters = alert['cap_info'][0]['cap_parameter']

        for parameter in parameters:
            if(parameter['valueName'] == 'temperature_mean'):
                temperature_mean = float(parameter['value'])
            elif(parameter['valueName'] == 'temperature_std'):
                temperature_std = float(parameter['value'])
            elif(parameter['valueName'] == 'humidity_mean'):
                humidity_mean = float(parameter['value'])
            elif(parameter['valueName'] == 'humidity_std'):
                humidity_std = float(parameter['value'])
            elif(parameter['valueName'] == 'pressure_mean'):
                pressure_mean = float(parameter['value'])
            elif(parameter['valueName'] == 'pressure_std'):
                pressure_std = float(parameter['value'])
            elif(parameter['valueName'] == 'light_mean'):
                light_mean = float(parameter['value'])
            elif(parameter['valueName'] == 'light_std'):
                light_std = float(parameter['value'])
            elif(parameter['valueName'] == 'update_time'):
                update_time = str(parameter['value'])

        if(not temperature_mean or not humidity_mean or not pressure_mean or not light_mean
           or not temperature_std or not humidity_std or not pressure_std or not light_std or not update_time):
            raise ValueError()

        return (temperature_mean, humidity_mean, pressure_mean, light_mean, temperature_std, humidity_std, pressure_std, light_std, update_time)

    except:
        return ValueError()
