-- # Write your MySQL query statement below darkesh duresh
select a.student_id ,a.student_name ,a.subject_name,count(e.subject_name) as attended_exams 
from (select * from Students cross join Subjects) as a left join Examinations as e
on a.student_id =e.student_id and a.subject_name =e.subject_name
group by a.student_id ,a.student_name ,a.subject_name
order by a.student_id ,a.subject_name;
-- select * from Students cross join Subjects;