#include<iostream>
#define infini INT_MAX/2// El valor m�ximo no selecciona INT_MAX para evitar el desbordamiento
#define maxSize 6// N�mero de v�rtices
#define MAX 8// N�mero de aristas
//Matriz de adyacencia
typedef struct
{
	int vexnum, arcnum;// N�mero de v�rtices y aristas
	char vex[maxSize];// Informaci�n de v�rtice (car�cter)
	int arc[maxSize][maxSize];// Matriz bidimensional (almacena informaci�n en el lateral)
}mGraph;

bool final[maxSize];// Indica la colecci�n s
bool p[maxSize][maxSize];// Indica la ruta
int D[maxSize];// Indica la longitud de ruta m�s corta desde el punto de origen hasta cada v�rtice

void dijkstra(mGraph& G, int v0);// Encuentra el camino m�s corto
int main()
{
	using namespace std;
	mGraph G;// La matriz de adyacencia almacena el gr�fico y lo inicializa
	G.vexnum = maxSize;
	G.arcnum = MAX;
	char vexData[maxSize] = { 'a', 'b', 'c', 'd', 'e','f' };// Informaci�n de v�rtice
	int arcData[MAX][3] = { { 0, 2 ,10}, { 0, 5,100 }, { 0, 4 ,30}, { 1, 2,5 }, { 2, 3 ,50},
					{ 3, 5, 10 }, { 4, 3, 20 }, { 4, 5, 60 } };// Borde conectado
	int i, j;
	for (i = 0; i < G.vexnum; ++i)
	{
		G.vex[i] = vexData[i];
		for (j = 0; j < G.vexnum; j++)
			G.arc[i][j] = infini;
	}
	for (i = 0; i < G.arcnum; i++)
		G.arc[arcData[i][0]][arcData[i][1]] = arcData[i][2];
	// Inicializaci�n completada

	cout << "Encuentra la ruta mas corta a partir del vertice v0: ";
	cout << endl;
	dijkstra(G, 0);
	for (i = 1; i < G.vexnum; ++i)
	{
		if (D[i] == infini)
		{
			cout << "No existe para v " << i
				<< "camino de " << endl;
			continue;
		}
		cout << "To v" << i << ": La longitud es " << D[i] << ' '
			<< "El vertice del camino mas corto es ";
		for (j = 0; j < G.vexnum; ++j)
			if (p[i][j] == true)
				cout << 'v' << j << ' ';
		cout << endl;
	}
	cout << endl;
	return 0;
}
void dijkstra(mGraph& G, int v0)
{
	int i, j, minValue, min;
	// inicializaci�n
	for (i = 0; i < G.vexnum; ++i)
	{
		final[i] = false;
		D[i] = G.arc[v0][i];
		for (j = 0; j < G.vexnum; ++j)
			p[v0][j] = false;
		if (G.arc[v0][i] < infini)
		{
			p[i][v0] = true;
			p[i][i] = true;
		}
	}
	
	final[v0] = true;// v0 en la colecci�n
	D[v0] = 0;
	for (i = 1; i < G.vexnum; ++i)// Bucle G.vexnum-1 veces
	{
		// Encuentra el D [i] m�s peque�o
		minValue = infini;
		for (j = 0; j < G.vexnum; ++j)
		{
			if (final[j]==false)
				if (minValue>D[j])
				{
					minValue = D[j];
					min = j;
				}
		}
		final[min] = true;
		//Actualizar
		for (j = 0; j < G.vexnum; ++j)
		{
			if (final[j] == false && minValue + G.arc[min][j] < D[j])
				// Si G.arc [min] [j] es INT_MAX, la adici�n de la izquierda se desbordar�, por lo que INT_MAX no se puede usar
			{
				//Actualizado
				D[j] = minValue + G.arc[min][j];
				// Actualizar p
				for (int temp = 0; temp < G.vexnum; ++temp)
					p[j][temp] = p[min][temp];
				p[j][j] = true;
			}
		}
	}
}
