#!/usr/bin/env python3

import turtle
import math
import sys, os, time

turtle.setup(600,300)
wn = turtle.Screen()
wn.bgcolor("lightblue")
wn.title("PS42 Navigation")

ps42 = turtle.Turtle()
ps42.color("yellow")
ps42.shape("triangle")


start = 1 #signal to start, received from RC

if start == 1:
    wn.onclick(ps42.goto)
    f = open('navigation.txt','r')
    data =f.readlines()
    dataInput = data[0].split()
    
    dist = int(dataInput[0])
    ang = int(dataInput[1])
    ang = ang * math.pi/180;
    time.sleep(2)

    ps42.setheading(math.degrees(ang))
    ps42.fd(dist)
    if ps42.xcor()>300: 
       ps42.setx(300)
    if ps42.xcor()<-300:
       ps42.setx(-300)
    if ps42.ycor()>150:
        ps42.sety(150)
    if ps42.ycor()<-150:
       ps42.sety(-150)
    ps42.setpos(ps42.position())
    
    
#pause
wn.exitonclick()
