# Visualización de grafos:
Se necesita Graphviz:
`sudo apt install graphviz`

Graphviz toma un fichero.dot de la forma:
`
graph {
	nodo1 -- nodo2;
	nodo2 -- nodo3;
	nodo3 -> nodo4;
	nodo4 -> nodo4;
}
`

Y luego genera el grafo con:
`dot fichero.dot -Tpdf > fichero.pdf`

