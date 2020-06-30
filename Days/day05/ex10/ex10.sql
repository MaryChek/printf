SELECT film.title AS 'Title', film.summary AS 'Summary', film.prod_year
FROM film JOIN genre
ON film.id_genre = genre.id_genre
WHERE `name` like 'erotic'
ORDER BY prod_year DESC;