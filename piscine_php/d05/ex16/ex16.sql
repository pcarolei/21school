SELECT
	COUNT(DISTINCT `id_film`) as 'movies'
FROM
	`member_history`
WHERE
	EXTRACT(DAY from `date`) = 24 AND EXTRACT(MONTH from `date`) = 12
OR
	`date` BETWEEN '2006-10-30' AND '2007-07-27';
	
