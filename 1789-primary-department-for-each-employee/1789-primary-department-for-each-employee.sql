SELECT 
   DISTINCT employee_id, department_id
FROM 
    Employee 
WHERE
    employee_id IN(SELECT employee_id from Employee GROUP BY employee_id HAVING COUNT(*) = 1) or primary_flag = 'Y'
    ORDER BY employee_id
;