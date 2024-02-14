# -*- coding: utf-8 -*-
"""
Created on Sat Jan 14 10:52:19 2023

@author: Swaroop
"""

import mysql.connector
mycon=mysql.connector.connect(host='localhost',user='root',passwd='manager')           
cursor=mycon.cursor()
mycon.autocommit=True
s1="create database railway"
cursor.execute(s1)
s2="create table railway(name varchar(100),phno varchar(15)  primary key,age int(4),gender (50),from_f varchar(100),to_t varchar(100),date_d varchar(20))"
cursor.execute(s2)
s3="create table user_accounts(fname varchar(100),lname varchar(100),user_name varchar(100) ,password varchar(100) primary key, phno varchar(15),gender varchar(50),dob varchar(50),age varchar(4))"
cursor.execute(s3)
