# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000


def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    # TODO: Read teams into memory from file
    with open(sys.argv[1], 'r') as file:
        reader = csv.reader(file)
        next(reader)
        for row in reader:
            team = {
                "team": row[0],
                "rating" : row[1]
            }
            teams.append(team)
    for i in range(len(teams)):
        print(teams[i]['team'], end = " ")
        print(teams[i]['rating'])

    counts = {}
    # TODO: Simulate N tournaments and keep track of win counts
    with open(sys.argv[1], 'r') as file:
        reader = csv.reader(file)
        next(reader)
        for row in reader:
            counts[row[0]] = 0
            print(counts)
    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # TODO
    #read the teams from the csv
    #put the teams in a dictionary
    #put the dictionary in teams

    winner = simulate_round(teams)
    while(len(winner) > 1):
       winner = simulate_round(winner)

    return winner[0]


    #call the simulate_round function on winners of each round
    #until the number of team reduces to 1

    #When the remaining number of teams is 1,
    #increment the count of that team(the number of times that team has won a tournament)




if __name__ == "__main__":
    main()
