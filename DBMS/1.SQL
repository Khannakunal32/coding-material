CREATE DATABASE IF NOT EXISTS ORG;
SHOW databases;
USE ORG;

CREATE TABLE Worker (
WORKER_ID INT NOT NULL PRIMARY KEY auto_increment,
FIRST_NAME CHAR(25),
LAST_NAME CHAR(25),
SALARY INT(15),
JOINING_DATE datetime,
DEPARTMENT CHAR(25)
);

INSERT INTO Worker 
(WORKER_ID, FIRST_NAME, LAST_NAME, SALARY, JOINING_DATE, DEPARTMENT) 
VALUES
(001, 'Monika', 'Arora', 100000, '14-02-20 09.00.00', 'HR'),
(002, 'Niharika', 'Verma', 80000, '14-06-11 09.00.00', 'Admin'),
(003, 'Vishal', 'Singhal', 300000, '14-02-20 09.00.00', 'HR'),
(004, 'Amitabh', 'Singh', 500000, '14-02-20 09.00.00', 'Admin'),
(005, 'Vivek', 'Bati', 500000, '14-06-11 09.00.00', 'Admin'),
(006, 'Vipul', 'Diwan', 200000, '14-06-11 09.00.00', 'Account'),
(007, 'Satish', 'Kumar', 75000, '14-01-20 09.00.00', 'Account'),
(008, 'Geetika', 'Chauhan', 90000, '14-04-11 09.00.00', 'Admin');

select * from worker;

CREATE TABLE Bonus (
WORKER_REF_ID INT,
BONUS_AMOUNT INT(10),
BONUS_DATE datetime,
foreign key (WORKER_REF_ID)
	references Worker(Worker_ID)
    on delete cascade
);

INSERT INTO Bonus
(WORKER_REF_ID, BONUS_AMOUNT, BONUS_DATE) 
VALUES
(001, 5000, '16-02-20'),
(002, 3000, '16-06-11'),
(003, 4000, '16-02-20'),
(001, 4500, '16-02-20'),
(002, 3500, '16-06-11');

select * from Bonus;

CREATE TABLE Title (
WORKER_REF_ID INT,
WORKER_TITLE CHAR(25),
AFFECTED_FROM datetime,
foreign key (WORKER_REF_ID)
	references Worker(Worker_ID)
    on delete cascade
);

INSERT INTO Title
(WORKER_REF_ID, WORKER_TITLE, AFFECTED_FROM) 
VALUES
(001, 'Manager', '2016-02-20 00:00:00'),
(002, 'Executive', '2016-06-11 00:00:00'),
(008, 'Executive', '2016-06-11 00:00:00'),
(005, 'Manager', '2016-06-11 00:00:00'),
(004, 'Asst. Manager', '2016-06-11 00:00:00'),
(007, 'Executive', '2016-06-11 00:00:00'),
(006, 'Lead', '2016-06-11 00:00:00'),
(003, 'Lead', '2016-06-11 00:00:00');



show databases;
use org;

-- dual table operations 
select 5+11;
-- datetime from dual table
select now();
select lcase('KUnaL'), ucase('KhAnNa');

select * from worker where SALARY > 100000;

-- between says [a,b] that is a and b are inclusive
select FIRST_NAME, LAST_NAME, SALARY FROM worker where SALARY BETWEEN 100000 AND 300000;

-- TWO WAYS FOR OR STATEMENT
select * from worker where DEPARTMENT = 'HR' OR DEPARTMENT ='Account' or DEPARTMENT = 'ADMIN';
select * from worker where DEPARTMENT IN ('HR','ADMIN', 'Account');

-- we can use not in 
select * from worker where DEPARTMENT NOT IN ('HR','ADMIN');


-- trying is NULL 
-- PRIMARY KEY CAN BE DESCRIBED SEPERATELY
create table temp (
ID INT,
CNAME VARCHAR(255),
AGE INT(10),
PRIMARY KEY (ID)
);

INSERT INTO temp 
(ID, CNAME, AGE)
values 
(1, 'kunal', 21),
(2, 'chhavi', NULL);
-- main statement to check null
select * from temp where AGE is NULL;
-- deleting the table
drop table temp;

-- WILD CARD % _ using LIKE or NOT LIKE
-- % show any number of character , _ show fixed number that is one character 
select * from worker where FIRST_NAME LIKE  "%i%";
select * from worker where FIRST_NAME LIKE "%i__";

-- SORTING USING ORDER BY ASC (DEFAULT)
select * from worker 
order by SALARY DESC;
select * from worker 
order by FIRST_NAME DESC;

-- DISTINCT or group by for distict characters (GROUP BY WITHOUT AGGREGATE FUNCITON LIKE COUNT MAX ETC IS DISTINCT)
SELECT DISTINCT DEPARTMENT from worker;
Select DEPARTMENT from worker 
group by DEPARTMENT;

-- GROUP BY (THE COLUMNS MUST BE SAME AFTER SELECT AND GROUP BY KEYWORD)
Select DEPARTMENT, SALARY from worker 
group by DEPARTMENT, SALARY;

-- GROUP BY COUNT (USE AGGREGATE FUNCITON ONLY WITH GROUP BY
select DEPARTMENT, count(DEPARTMENT) from worker 
group by DEPARTMENT;

-- GROUP BY SUM (BELOW WILL SHOW THE TOTAL SALARY DISTRIBUTED FOR EACH DEPARTMENT)
select DEPARTMENT, sum(SALARY) from worker 
group by DEPARTMENT;

-- GROUP BY AVG
select DEPARTMENT, avg(SALARY) from worker 
group by DEPARTMENT;

-- GROUP BY MIN
select DEPARTMENT, min(SALARY) from worker 
group by DEPARTMENT;

-- GROUP BY MAX
select DEPARTMENT, max(SALARY) from worker 
group by DEPARTMENT;

-- HAVING TO BE USED WITH GROUP BY ONLY AND WHERE SHOULD BE WRITTEN BEFORE GROUP BY 
SELECT * FROM WORKER;
select DEPARTMENT, COUNT(DEPARTMENT) from worker 
group by DEPARTMENT HAVING count(DEPARTMENT) > 2;

-- HAVING AND WHERE USED SIMULTANIUOUSLY WITH GROUP BY , THE BELOW SHOWS ADMIN 3 AS ONLY 3 ADMINS ARE THERE WITH COUNT > 2 AND SALARY >= 90000
select DEPARTMENT, COUNT(DEPARTMENT) FROM WORKER 
WHERE SALARY >= 90000  
GROUP BY DEPARTMENT HAVING COUNT(DEPARTMENT) > 2;


-- UNIQUE & -- CONTSTRAINT CHECK
create table customer (
NAME VARCHAR(255) UNIQUE,
age int,
constraint AGE_CHK CHECK(age>20)
);

-- name is unique so below won't work
insert into customer values
('chhavi', 50),
('chhavi', 23);

insert into customer values
('kunalkk', 10);

-- Default constraint
drop table customer;

create table if not exists customer (
NAME VARCHAR(255) UNIQUE,
age int NOT NULL DEFAULT 18
);

insert into customer
(NAME)
values
('kunal');

-- age not specified so takes default age value
select * from customer;

-- alter table adding a column
alter table customer add gender varchar(10);
desc customer;

-- alter table modify a column
alter table customer modify gender char(20) default 'male';

-- alter table change a column name
alter table customer CHANGE COLUMN gender sex varchar(20) default 'female';

-- alter table drop a column
alter table customer DROP COLUMN sex;
desc customer;

-- alter table rename table - name
alter table Customer RENAME TO Customer_new;

-- DML UPDATE FUNCTION TO UPDATE DATA OF ROWS
alter table customer_new rename to customer;
 insert into customer values ('chhavi', 23);
 
 UPDATE customer SET NAME = 'chhavi Khanna' where Name = 'chhavi';
 
 -- UPDATE MULIPLE ROWS FOR THIS WE TEMPRARILY HAVE TO DISABLE SAFE MODE
 -- AS SQL DONT ALLOW US TO UPATE ALL COLUMNS SIMULTANIIOUSLY
 SET SQL_SAFE_UPDATES = 0;
 UPDATE customer SET AGE = AGE + 10;
 SELECT * FROM CUSTOMER;
 
 -- ENABLING SAFE UPDATES AGAIN
 SET SQL_SAFE_UPDATES = 1;


-- ( ON DELETE CASCADE AND ON DELETE SET NULL )  to update the child table when changes occur in primary table
ALTER TABLE CUSTOMER add ID INT NOT NULL PRIMARY KEY auto_increment;

select * from customer;

create table Customer_child(
order_id int primary key,
child_id int,
delivery date,
foreign key(child_id) references customer(id)
);

-- below dont execute as we are adding child_id that does not exist in customer id as it is refrencing
insert into customer_child
(order_id, child_id, delivery)
values
(10, 1, '2019-01-23' ),
(11, 2, '2020-01-23' ),
(12, 3, '2009-05-23' );

-- remove the child_id 3 
insert into customer_child
(order_id, child_id, delivery)
values
(10, 1, '2019-01-23' ),
(11, 2, '2020-01-23' );

select * from customer_child;

-- THE BELOW DO NOT WORK AS A FOREIGN KEY IS REFERENCED SO WE NEED TO REMOVE IT AS WELL SO WE USE (DELETE CASCADE OR ON DELETE NULL)
DELETE from customer where id = 2;


-- UPDATING CUSTOMER ID FOR DELETE CASCADE OPTION 1 OR OPTION 2
-- OPTION 1 (UPDATE THE PREVIOUS)
ALTER TABLE customer_child drop foreign key customer_child_ibfk_1;
ALTER TABLE customer_child ADD foreign key(child_id) references customer(id) ON DELETE CASCADE;

-- OPTION 2 TO RECREATE CUSTOMER ID
DROP TABLE customer_child;
create table Customer_child(
order_id int primary key,
child_id int,
delivery date,
foreign key(child_id) references customer(id) ON DELETE CASCADE
);
insert into customer_child
(order_id, child_id, delivery)
values
(10, 1, '2019-01-23' ),
(11, 2, '2020-01-23' );


-- NOW TRYING TO DELETE ID-2 IN CUSTOMER THIS SHOULD AUTOMATICALLY DELETE IN CUSOMTER_CHILD
DELETE FROM CUSTOMER WHERE ID = 2;

SELECT * FROM CUSTOMER_CHILD;

-- SAME WE CAN USE ON DELETE SET NULL, INSETEAD OF DELTING THE ID IN FOREIGN TABLE IT SETS THE ID TO NULL
INSERT INTO CUSTOMER (Name, age, id) VALUES ('chhavi' , 20, 2);
insert into customer_child values(11, 2, '2019-10-10');

-- this shows all the inormation and given names of table , we can drop foreign key using it
show create Table customer_child; 
alter table customer_child drop foreign key customer_child_ibfk_1;

-- now adding foreing key with on delte set NULL constraint
alter table customer_child add FOREIGN KEY(child_id) references customer(id) ON DELETE SET NULL;

select * from customer_child;
show create table customer_child;
DELETE FROM customer where id = 2;
select * from customer_child;






















