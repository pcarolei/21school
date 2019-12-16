SELECT
	COUNT(`duration`) as `nb_short-films`
FROM
	film
WHERE
	`duration` <= 42;
