#include <Arduino.h>

#include "parameters.h"

void XMLPreprocessor(char *body, Parameters params)
{
    String id = (String)params.id;

    String temperature_mean = (String)params.temperature_mean;
    String temperature_std = (String)params.temperature_std;

    String humidity_mean = (String)params.humidity_mean;
    String humidity_std = (String)params.humidity_std;

    String pressure_mean = (String)params.pressure_mean;
    String pressure_std = (String)params.pressure_std;

    String light_mean = (String)params.light_mean;
    String light_std = (String)params.light_std;

    String update_time = (String)params.update_time;

    sprintf(
        body,
        "<?xml version = '1.0' encoding = 'UTF-8' standalone = 'yes'?>"
        "< alert xmlns = 'urn:oasis:names:tc:emergency:cap:1.1' >"
            "<identifier>%s</identifier>"
            "<sender>iotdevice</sender>"
            "<sent>%s</sent>"
            "<status>Actual</status>"
            "<msgType>Alert</msgType>"
            "<scope>Public</scope>"
            "<info>"
                "<category>Env</category>"
                "<event>Update</event>"
                "<urgency>Expected</urgency>"
                "<severity>Minor</severity>"
                "<certainty>Likely</certainty>"
                "<parameter>"
                    "<valueName>%s</valueName>"
                    "<value>%s</value>"
                "</parameter>"
                "<parameter>"
                    "<valueName>%s</valueName>"
                    "<value>%s< / value >"
                "</parameter>"
                "<parameter>"
                    "<valueName>%s</valueName>"
                    "<value>%s</value>"
                "</parameter>"
                "<parameter>"
                    "<valueName>%s</valueName>"
                    "<value>%s</value >"
                "</parameter>"
                "<parameter>"
                    "<valueName>%s</valueName>"
                    "<value>%s</value>"
                "</parameter>"
                 "<parameter>"
                    "<valueName>%s</valueName>"
                    "<value>%s</value>"
                "</parameter>"
                "<parameter>"
                    "<valueName>%s</valueName>"
                    "<value>%s< / value >"
                "</parameter>"
                "<parameter>"
                    "<valueName>%s</valueName>"
                    "<value>%s</value>"
                "</parameter>"
                "<parameter>"
                    "<valueName>%s</valueName>"
                    "<value>%s</value >"
                "</parameter>"
            "</info>"
        "</alert>",
        id.c_str(), 
        update_time.c_str(), 

        "update_time", update_time.c_str(),

        "temperature_mean",temperature_mean.c_str(),
        "temperature_std", temperature_std.c_str(),

        "pressure_mean",pressure_mean.c_str(),
        "pressure_std", pressure_std.c_str(),

        "humidity_mean",humidity_mean.c_str(),
        "humidity_std", humidity_std.c_str(),

        "light_mean",light_mean.c_str(),
        "light_std", light_std.c_str()

    );
}