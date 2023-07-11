-- Keep a log of any SQL queries you execute as you solve the mystery.

--This finds the streets and id of crimes on which crimes have been commited on July 28, 2021
SELECT id, street FROM crime_scene_reports WHERE year = 2021 AND month = 07 AND day = 28;
--result
--id = 295
--location = Humphrey street bakery
--time = 10:15am
--description = Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time
--             – each of their interview transcripts mentions the bakery.

--Suspect license plate at the given time
SELECT license_plate, activity, minute FROM bakery_security_logs WHERE year = 2021 AND month = 07 AND day = 28 AND hour = 10;
-- license_plate | activity | minute |
--+---------------+----------+--------+
--| R3G7486       | entrance | 8      |
--| 13FNH73       | entrance | 14     |
--| 5P2BI95       | exit     | 16     | => primary suspect
--| 94KL13X       | exit     | 18     | => secondary suspect
--| 6P58WS2       | exit     | 18     | => Tertiary suspect
--| 4328GD8       | exit     | 19     |
--| G412CB7       | exit     | 20     |
--| L93JTIZ       | exit     | 21     |
--| 322W7JE       | exit     | 23     |
--| 0NTHK55       | exit     | 23     |
--| 1106N58       | exit     | 35