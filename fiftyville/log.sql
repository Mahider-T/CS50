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


--Suspect license plate at the given time
SELECT license_plate, activity, minute FROM bakery_security_logs WHERE year = 2021 AND month = 07 AND day = 28 AND hour = 10;
-- license_plate | activity | minute |

--| 5P2BI95       | exit     | 16     |
--| 94KL13X       | exit     | 18     |
--| 6P58WS2       | exit     | 18     |
--| 4328GD8       | exit     | 19     |
--| G412CB7       | exit     | 20     |
--| L93JTIZ       | exit     | 21     | => 1
--| 322W7JE       | exit     | 23     | => 2
--| 0NTHK55       | exit     | 23     | => 3


