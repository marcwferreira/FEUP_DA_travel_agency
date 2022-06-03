# Travel Agency - DA 2nd Project

## Install

No root do projecto, executar o comando:

```bash
$ . ./setup.sh
```

## Run

```
./proj2 --help

Usage: /proj2 <CASE> <OPTION> <GRAPH> <ORIGIN> <DESTINATION> [GROUP SIZE]

       <CASE>
          1: Não há separação do grupo
          2: Pode haver separação do grupo
       <OPTION>
          [1] 1: Max size of a group traveling
          [1] 2: Minimization number of bus changes vs. maximization of group size
          [2] 1: Find travel routes for a group of a determined size
          [2] 2: Correct travel routes in case group size increases (number of bus changes can go up)
          [2] 3: Calculate the max group size and travel routes between origin and destination
          [2] 4: Minimum amount of time for the whole group to arrive at destination
          [2] 5: Max amount of time a subset of the group may wait between connections (bus changes)       
       <GRAPH>
          Nome do ficheiro da pasta input que descreve o grafo
```

## Elementos:

- Fábio Sá, up202007658
- Marcos Pinto, up201800177
