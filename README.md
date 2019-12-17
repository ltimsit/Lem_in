# Lem_in

Lem_in is an algorithm project for school 42 done in C.

GOAL of this Project:

- the goal of this project is to implement an efficient path-finding algorithm using graph theory.

You are given data that represente rooms, connections and a number of ants for a virtual anthill and
need to find the best combinaison of paths your ants can take to exit it in the shortest amont of move.
Each room can only contain 1 ant at a time.

Our algorithm and implementation :

To solve both the issue of efficiency and precision of the result we decided to implement a homemade algorithm 
that reproduce J.W. Suurballe node-disjoint path finding algorithm (http://www.macfreek.nl/memory/Disjoint_Path_Finding).

1 The program does n BFS search for n shortest paths 
2 It evaluate the efficiency in round for the paths found
3 If its more efficient than the previous iteration -> repeat the process.

Our algorithm handle ant-hill with 10s of thousand of rooms and connections in under 0.5s

Enjoy our displayer that showcase the found paths on small maps (max 42 rooms layout can be displayed)
![alt text](https://github.com/ltimsit/Lem_in/blob/master/readMeRessources/lemin.gif "lemin")
