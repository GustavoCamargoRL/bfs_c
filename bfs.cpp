// Resolution of the second question of Fundamentals of Algorithms for Optimization
// Example of a width search algorithm for graphs
// Autor: Gustavo Lima
// Prof: Raphael Kramer

/*
	Run the width search algorithm for the attached graph, starting from node 1.


	Respond what is the color, distance and parent of each node and which nodes are in the Q queue at the end of each iteration.


	Ex:
	Start: color = [blue, white, white, white, white, white, white]; d = [0, inf, inf, inf, inf, inf, inf]; [nil, nil, nil, nil, nil, nil, nil]; Q = { 1 }
	End of Iteration 1: color = [purple, blue, blue, white, white, white, white]; d = [0, 1, 1, inf, inf, inf, inf]; [nil, 1, 1, nil, nil, nil, nil]; Q = {2,3}
	End of Iteration 2: ? ? ?
	End of Iteration 3: ? ? ?

	End of Iteration 4: ? ? ?
*/

#include <vector> 
#include <iostream>	  


void bfs(std::vector<std::string> cor, std::vector<std::pair<int, int>> pai_dist, std::vector<std::vector<int>> grafo)
{
	std::vector<int> fila = {0};  //queue initialization with source node set to 1
	int contador = 0;             //iteration counter initialization

	std::cout << "Initial values: color =[";
	for (int i = 0; i < cor.size(); i++)
	{
		for (int j = 0; j < cor[i].size(); j++)
		{
			std::cout << cor[i][j];
		}
		if (i < cor.size() - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << "], (Father,Distance) = [No 1 - Father: nil Distance: 0 ";
	for (int i = 1; i < pai_dist.size(); i++)
	{
		std::cout << "Node " << i + 1 << " - ";
		std::cout << "Father: nil Distance: inf";
		if (i < pai_dist.size() - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << "], Queue = {" << fila[0]+1 << "}" << std::endl;
	
	//start of search loop
	while (!fila.empty())
	{
		contador += 1;  //iteration counter

		for (int i = 0; i < grafo[fila[0]].size(); i++)	//neighbor search loop
		{
			int indiceX = grafo[fila[0]][i];  //index operator
			int indiceY = 0;				  //index operator
			if (cor[indiceX][indiceY] == 'w') //as it is enough to compare the first letter to differentiate, white, blue, purple, I just checked that letter
			{								 //if not white, it will be updated to blue color
				cor[indiceX] = "blue";
				pai_dist[indiceX].first = fila[0];   //update from the father of this node
				pai_dist[indiceX].second = pai_dist[fila[0]].second + 1;   //update distance to origin
				fila.push_back(indiceX);             //add the index of this node to the queue
			}
		}
		cor[fila[0]] = "purple";    //at the end of the neighbor check, it updates the node color to purple
		fila.erase(fila.begin());	//delete the queue number
		
		std::cout << "End of iteration " << contador << ": colour = [";
		for (int i = 0; i < cor.size(); i++)
		{
			for (int j = 0; j < cor[i].size(); j++)
			{
				std::cout << cor[i][j];
			}
			if (i < cor.size() - 1)
			{
				std::cout << ", ";
			}
		}
		std::cout << "], (Father,Distance) = [No 1 - Father: nil Distance: 0,";
		for (int i = 1; i < pai_dist.size(); i++)
		{
			std::cout << "Node " << i + 1 << " - ";
			std::cout << "Father: ";
			std::cout << pai_dist[i].first + 1 << " Distance : ";
			if (pai_dist[i].second > 100000) { std::cout << "inf"; }
			else{ std::cout << pai_dist[i].second; }
			if (i < pai_dist.size() - 1)
			{
				std::cout << ", ";
			}
		}
		std::cout << "], Queue = {";
		for (int i = 0; i < fila.size(); i++)
		{
			std::cout << fila[i] + 1;
			if (i < fila.size() - 1)
			{
				std::cout << ", ";
			}

		}
		std::cout << "}" << std::endl;
		
	}

}


int main(int argc, char *argv[])
{
	//variable initialization
	std::vector<std::string> cor = { {"blue"} };   //setting the first element of the node as the starting point
	std::vector<std::pair<int, int>> pai_dist = { {NULL,0} };    // setting null parent and distance 0 to start node
	std::vector<std::vector<int>> grafo = { {1,2},{4,6},{4},{},{3,5,7},{0},{3,2},{6} };  //initialization of the graph and its arcs

	for(int i=1; i < grafo.size(); i++)
	{
		cor.push_back("white");      //defining the rest as unvisited
		pai_dist.push_back({ NULL,std::numeric_limits<int>::max() });  //initializing the other parents and distances from us
	}

	std::cout << "Beginning of the search for width in a graph:" << std::endl;
	//call of the breadth search execution
	bfs(cor, pai_dist, grafo);

	return 0;
}