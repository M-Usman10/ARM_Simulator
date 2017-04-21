#ifndef OBJECTS_H
#define OBJECTS_H
#include <list>
using namespace std;
class Vertex
{
public:
	int x, y;
	Vertex(int x1, int y1 = 0) :
			x(x1), y(y1)
	{

	}
};
class Edge
{
public:
	Vertex * V1;
	Vertex * V2;
	Edge()
	{
		V1 = 0;
		V2 = 0;
	}
	Edge(Vertex & v1, Vertex & v2) :
			V1(&v1), V2(&v2)
	{

	}
};
class Shape
{
public:
	int no_of_edges;
	int no_of_vertices;
	list<Vertex> vertices;
	list<Edge> edges;
	Shape(int v_size/* #vertices */, int e_size/* #edges*/, list<Vertex> & v,
			list<Edge> & e)
	{
		no_of_edges = e_size;
		no_of_vertices = v_size;
		vertices = v;
		edges = e;
	}
	Shape()
	{
		no_of_edges = 0;
		no_of_vertices = 0;
	}
	void AddVertex(int x, int y)
	{
		++no_of_vertices;
		Vertex V(x, y);
		vertices.push_back(V);
	}
	void AddVertex(Vertex & V)
	{
		++no_of_vertices;
		vertices.push_back(V);
	}
	void AddEdge(Edge & E)
	{
        ++no_of_edges;
        edges.push_back(E);
	}
	void ChangeVertices(list<Vertex> V)
	{
       vertices=V;
       no_of_vertices=V.size();
	}
	void ChangeEdges(list<Edge> E)
	{
        edges=E;
        no_of_edges=E.size();
	}
};
class ALU_INPUT
{
	int src1, src2;
	bool c_in;
	short operation;
};
class ALU_OUTPUT
{
	int result;
	bool overflow;
	bool zero;
};
class ALU:public Shape
{
public:
	int size; // Size of ALU to be rendered during simulation
	int x; //X_Coor on screen
	int y; //Y_Coor on screen
	ALU(int size = 1, int x, int y)
	{
		this->x = x;
		this->y = y;
		this->size = size;
	}
	ALU_OUTPUT operate(const ALU_INPUT & inp)
	{
		ALU_OUTPUT out;
		return out;
	}
};
class Reg_File:public Shape
{
public:
	int r0;
	int r1;
	int r2;
	int r3;
	int r4;
	int r5;
	int r6;
	int r7;
	int r8;
	int r9;
	int r10;
	int r11;
	int r12;
	int sp;
	int lr;
	int pc;
	Reg_File(int x, int y, int width, int height)
	{
		r0 = 0 + 10;
		r1 = 1 + 10;
		r2 = 2 + 10;
		r3 = 3 + 10;
		r4 = 4 + 10;
		r5 = 5 + 10;
		r6 = 6 + 10;
		r7 = 7 + 10;
		r8 = 8 + 10;
		r9 = 9 + 10;
		r10 = 10 + 10;
		r11 = 11 + 10;
		r12 = 12 + 10;
		sp = 13 + 10;
		lr = 14 + 10;
		pc = 15 + 10;
	}
};
class Mem:public Shape
{
public:
	int * arr;
	int size;
	Mem(int size)
	{
		this->size = size;
		arr = new int[size];
		for (int i = 0; i < size; ++i)
		{
			arr[i] = i * 4;
		}
	}
};
class Control_Unit:public Shape
{
public:
	Control_Unit()
	{

	}
	void generateControl()
	{

	}
};
template<typename T>
class Pipeline_reg:public Shape
{
	T data;
};
class MUX:public Shape
{
public:
	MUX()
{

}
	void cal_res()
	{

	}
};
#endif
