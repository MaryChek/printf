SELECT title, summary FROM film
WHERE LOWER(summary) like '%Vincent%'
ORDER BY id_film ASC;