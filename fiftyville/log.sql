-- Keep a log of any SQL queries you execute as you solve the mystery.

--This finds the streets and id of crimes on which crimes have been commited on July 28, 2021
SELECT id, street FROM crime_scene_reports WHERE year = 2021 AND month = 07 AND day = 28;
+-----+-----------------+
--| id  |     street      |
--+-----+-----------------+
--| 293 | Axmark Road     |
--| 294 | Boyce Avenue    |
--| 295 | Humphrey Street |
--| 296 | Widenius Street |
--| 297 | Humphrey Street