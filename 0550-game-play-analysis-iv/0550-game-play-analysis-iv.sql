# Write your MySQL query statement below
SELECT 
    ROUND(
        COUNT(DISTINCT player_id) / (SELECT COUNT(DISTINCT player_id) FROM Activity )
    ,2) 
    AS fraction
FROM 
    Activity
WHERE (player_id , DATE_SUB(event_date, INTERVAL 1 DAY )) IN  
(
SELECT
   player_id,
   MIN(event_date) as min_date
FROM 
    Activity a
GROUP BY
    a.player_id
)
;
