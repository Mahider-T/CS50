SELECT movies.title FROM movies, ratings, people, stars WHERE movies.id = ratings.movie_id AND ratings.movie_id = stars.movie_id AND stars.person_id = people.id AND people.name = "Chadwick Boseman" ORDER BY rating DESC LIMIT 5;