-- sqlite 

DROP TABLE IF EXISTS status;

CREATE TABLE status(
    id INTEGER PRIMARY KEY AUTOINCREMENT,
    update_time TIME NOT NULL,
    created TIMESTAMP NOT NULL DEFAULT CURRENT_TIMESTAMP,
    temperature_mean FLOAT NOT NULL,
    humidity_mean FLOAT NOT NULL,
    pressure_mean FLOAT NOT NULL,
    light_mean FLOAT NOT NULL,
    temperature_std FLOAT NOT NULL,
    humidity_std FLOAT NOT NULL,
    pressure_std FLOAT NOT NULL,
    light_std FLOAT NOT NULL
);