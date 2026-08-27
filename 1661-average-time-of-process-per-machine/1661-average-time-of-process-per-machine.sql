# Write your MySQL query statement below
select s.machine_id , ROUND(avg(e.timestamp - s.timestamp),3) 
as processing_time 
from Activity s 
JOIN Activity e 
ON s.machine_id = e.machine_id
AND e.process_id = s.process_id 
WHERE s.activity_type = 'start'
AND e.activity_type = 'end' 
group by s.machine_id;