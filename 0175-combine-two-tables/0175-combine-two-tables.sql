# Write your MySQL query statement below
select firstName, lastname, city, state 
from Person LEFT OUTER JOIN Address on Person.personId = Address.personId;