SELECT title, summary FROM film
WHERE summary like '%42%' or title like '%42%'
ORDER BY duration ASC;