SELECT movies.id FROM movies, stars, people WHERE movies.id = stars.movie_id AND stars.person_id = people.id AND people.name = "Kevin Bacon" AND birth = 1958;
