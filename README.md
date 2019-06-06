# Scala-Coding-Test
This repository is intended to share solutions to a specific problem. 

# Given Problem Statement
Four people come to a river in the night. There is a narrow bridge, but it can only hold two people at a time. They have one torch and, because it's night, the torch has to be used when crossing the bridge. Person A can cross the bridge in 1 minute, B in 2 minutes, C in 5 minutes, and D in 10 minutes. When two people cross the bridge together, they must move at the slower person's pace.
<br>
Write a program in C++ that determines the fastest time they can cross the bridge. The entry to the program will be a yaml file that describes the speeds of each Person. In this situation there are 4 people but your program should assume any number of people can be passed in.

# Problem Statement Interpetation 
Let,<br>
totalPeople be the number of people trying to cross the bridge <br>
crossingSpeeds store the time required by each person to cross the bridge <br>
Time taken by 2 people (p1 and p2) to cross the bridge = max(crossingSpeeds[p1], crossingSpeeds[p2]) <br>
Determine the minimum time required for all of the totalPeople to cross the bridge <br>

# Solution Approach 1 : Brute Force


