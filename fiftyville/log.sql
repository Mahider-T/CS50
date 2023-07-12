-- Keep a log of any SQL queries you execute as you solve the mystery.

--This finds the streets and id of crimes on which crimes have been commited on July 28, 2021
SELECT id, street FROM crime_scene_reports WHERE year = 2021 AND month = 07 AND day = 28;
--result
--id = 295
--location = Humphrey street bakery
--time = 10:15am
--description = Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time
--             – each of their interview transcripts mentions the bakery.

--interviews of witnesses
SELECT transcript, id FROM interviews WHERE year = 2021 AND month = 07 AND day = 28;
--ID = 160:
    --Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away.
    --If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.
--ID = 161:
    -- I don't know the thief's name, but it was someone I recognized. Earlier this morning,
    -- before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.
--ID = 162:
    --As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow.
    --The thief then asked the person on the other end of the phone to purchase the flight ticket.

--note:
    --license plate from security camera of the bakery (within 10 minutes of the theft)
    --Theif called someone after leaving bakery(for < 1 minute, earliest flight tomorrow)
    --Accomplice purchased flight tickets

airports              crime_scene_reports   people
atm_transactions      flights               phone_calls
bakery_security_logs  interviews
bank_accounts         passengers

CREATE TABLE phone_calls (
    id INTEGER,
    caller TEXT,
    receiver TEXT,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    duration INTEGER,
    PRIMARY KEY(id)
);

CREATE TABLE people (
    id INTEGER,
    name TEXT,
    phone_number TEXT,
    passport_number INTEGER,
    license_plate TEXT,
    PRIMARY KEY(id)
);

CREATE TABLE flights (
    id INTEGER,
    origin_airport_id INTEGER,
    destination_airport_id INTEGER,
    year INTEGER,
    month INTEGER,
    day INTEGER,
    hour INTEGER,
    minute INTEGER,
    PRIMARY KEY(id),
    FOREIGN KEY(origin_airport_id) REFERENCES airports(id),
    FOREIGN KEY(destination_airport_id) REFERENCES airports(id)
);

CREATE TABLE passengers (
    flight_id INTEGER,
    passport_number INTEGER,
    seat TEXT,
    FOREIGN KEY(flight_id) REFERENCES flights(id)
);
CREATE TABLE airports (
    id INTEGER,
    abbreviation TEXT,
    full_name TEXT,
    city TEXT,
    PRIMARY KEY(id)
);

--suspects based on license plate
SELECT people.name FROM people, bakery_security_logs WHERE people.license_plate = bakery_security_logs.license_plate AND year = 2021 AND month = 07 AND day = 28 AND hour = 10 AND minute >= 15 AND minute <=25 AND activity = "exit";
--Barry, Bruce, Diana, Iman, Kelsey, Luca, Sofia, Vanessa

--suspects based on phone call less than 1 minute
SELECT people.name FROM people, phone_calls WHERE people.phone_number = phone_calls.caller AND year = 2021 AND month = 07 AND day = 28 AND duration <= 60;
--Benista, Bruce, Carina, Diana, Kathryn,Kelsey, Kenny, Sofia, Taylor

--common suspects: phone_call id = {Bruce: 233, Diana: 255, Kelsey: 224 & 251, Sofia: 221 }

--possiible accomplices
SELECT people.name FROM people, phone_calls WHERE people.phone_number = phone_calls.receiver AND year = 2021 AND month = 07 AND day = 28 AND duration <= 60 AND (phone_calls.id = 233 OR phone_calls.id = 255 OR phone_calls.id = 224 OR phone_calls.id = 251 OR phone_calls.id = 221);
--accomplices: phone_call_id = { Jack: 221, Larry:224, Robin: 233, Melissa: 251, Philip: 255}

--The possible duos (thief:accomplice) = {Bruce: Robin, Diana: Philip, Kelsey: Larry, Kelsey: Melissa, Sofia: Jack}

SELECT people.name, flights.id, passengers.passport_number, flights.hour, flights.minute FROM people, flights, passengers WHERE people.passport_number = passengers.passport_number AND flights.id = passengers.flight_id AND year = 2021 AND month = 07 AND day = 29 ORDER BY hour ASC, minute ASC;
--peope who took first flight on 29 july 2021 = {Doris, Sofia, Bruce, Edward, Kelsey, Taylor, Kenny, Luca}

--filtered duos = {}