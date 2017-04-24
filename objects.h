#ifndef OBJECTS_H
#define OBJECTS_H
#include <list>
using namespace std;
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
class Mem
{
public:
	int * arr;
	int size;
	int x, y;
	int col;
	Mem(int x, int y, int col, int size = 4194304)
	{
		this->size = size;
		arr = new int[size];
		for (int i = 0; i < size; ++i)
		{
			arr[i] = i * 4;
		}
		this->x = x;
		this->y = y;
		this->col = col;
	}
	void draw_Mem()
	{
		DrawRoundRect(x, y, 90, 180, colors[col]);
		DrawString(x + 3, y + 80, "Memory", colors[WHITE]);
	}
};
class Pipeline_reg
{
public:
	string data;
	int x, y, height, col;
	Pipeline_reg(int x = 0, int y = 0, int height = 0, int col1 = 0)
	{
		this->x = x;
		this->y = y;
		this->height = height;
		col = col1;
	}
	void draw()
	{
		DrawRoundRect(x, y, 32, height, colors[col]);
	}
};
class control_unit
{
public:
	int x, y, color;
	control_unit(int x, int y, int color)
	{
		this->x = x;
		this->y = y;
		this->color = color;
	}
	void draw_unit()
	{
		DrawLine(x, y, x + 20, y, 2, colors[this->color]);
		DrawLine(x, y + 5, x + 20, y + 5, 2, colors[this->color]);
		DrawLine(x, y + 10, x + 20, y + 10, 2, colors[this->color]);
		DrawLine(x, y + 15, x + 20, y + 15, 2, colors[BLACK]);
		DrawLine(x, y + 20, x + 20, y + 20, 2, colors[this->color]);
		DrawLine(x, y + 25, x + 20, y + 25, 2, colors[BLACK]);
		DrawLine(x, y + 30, x + 20, y + 30, 2, colors[BLACK]);
		DrawLine(x, y + 35, x + 20, y + 35, 2, colors[this->color]);
		DrawLine(x, y + 40, x + 20, y + 40, 2, colors[this->color]);
		DrawLine(x, y + 45, x + 20, y + 45, 2, colors[this->color]);
		DrawString(x, y + 60, "CONTROL", colors[BLACK]);
	}
};

class flag
{
public:
	int x, y, color;
	flag(int x, int y, int color)
	{
		this->x = x;
		this->y = y;
		this->color = color;
	}
	void draw_unit()
	{
		DrawRoundRect(x, y, 50, 25, colors[this->color], 0);
	}
};
class Reg_File
{
public:
	int x;
	int y;
	int color;
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
	Reg_File(int x, int y, int color)
	{
		this->x = x;
		this->y = y;
		this->color = color;
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
	void draw_unit()
	{
		DrawRoundRect(x, y, 100, 150, colors[this->color], 0);
		DrawString(x + 3, y + 80, "REGFILE", colors[WHITE]);
	}
};

class MUX
{
public:
	int x, y, color, size;
	MUX(int x, int y, int color, int size)
	{
		this->x = x;
		this->y = y;
		this->color = color;
		this->size = size;
	}
	void draw_unit()
	{
		DrawRoundRect(x, y, 30, size, colors[this->color], 15);
		DrawString(x + 9, y + 10, "0", colors[WHITE]);
		DrawString(x + 9, y + 50, "1", colors[WHITE]);
	}
};
class sign_extender
{
public:
	int x, y, color;
	sign_extender(int x, int y, int color)
	{
		this->x = x;
		this->y = y;
		this->color = color;
	}
	void draw_unit()
	{
		DrawRoundRect(x, y, 50, 50, colors[this->color], 10);
		DrawString(x , y + 20, "EXT", colors[WHITE]);
	}
};
class shift_left
{
public:
	int x, y, color;
	shift_left(int x, int y, int color)
	{
		this->x = x;
		this->y = y;
		this->color = color;
	}
	void draw_unit()
	{
		DrawRoundRect(x, y, 25, 25, colors[this->color], 5);
		DrawString(x+5 , y + 4, "S", colors[WHITE]);
	}
};
class Hazard_detection
{
public:
	int x, y, color;
	Hazard_detection(int x, int y, int color)
	{
		this->x = x;
		this->y = y;
		this->color = color;
	}
	void draw_unit()
	{
		DrawRoundRect(x, y, 120, 60, colors[this->color], 10);
		DrawString(x + 4, y + 20, "HAZARD", colors[WHITE]);
	}
};
class ALU
{
public:
	int color; // Size of ALU to be rendered during simulation
	int x; //X_Coor on screen
	int y; //Y_Coor on screen
	ALU(int x = 10, int y = 10, int color = 5)
	{
		this->x = x;
		this->y = y;
		this->color = color;
	}
	ALU_OUTPUT operate(const ALU_INPUT & inp)
	{
		ALU_OUTPUT out;
		return out;
	}
	void draw_largeALU()
	{
		DrawLine(x, y, x, y + 50, 2, colors[color]);
		DrawLine(x, y, x - 60, y - 40, 2, colors[color]);
		DrawLine(x - 60, y - 40, x - 60, y + 10, 2, colors[color]);
		DrawLine(x - 60, y + 10, x - 50, y + 25, 2, colors[color]);
		DrawLine(x, y + 50, x - 60, y + 90, 2, colors[color]);
		DrawLine(x - 60, y + 90, x - 60, y + 40, 2, colors[color]);
		DrawLine(x - 60, y + 40, x - 50, y + 25, 2, colors[color]);
		DrawString(x - 50, y + 16, "ALU", colors[BLACK]);
	}

	void draw_smallALU()
	{
		DrawLine(x, y, x, y + 30, 2, colors[color]);
		DrawLine(x, y, x - 40, y - 30, 2, colors[color]);
		DrawLine(x - 40, y - 30, x - 40, y, 2, colors[color]);
		DrawLine(x - 40, y, x - 30, y + 15, 2, colors[color]);
		DrawLine(x, y + 30, x - 40, y + 60, 2, colors[color]);
		DrawLine(x - 40, y + 60, x - 40, y + 30, 2, colors[color]);
		DrawLine(x - 40, y + 30, x - 30, y + 15, 2, colors[color]);
		DrawString(x - 25, y + 10, "+", colors[BLACK]);
	}
};
class L
{
public:
	int x1, x2, y1, y2, col;
	L(int a1 = 0, int b1 = 0, int a2 = 0, int b2 = 0, int col = 0)
	{
		x1 = a1;
		x2 = a2;
		y1 = b1;
		y2 = b2;
		this->col = col;
	}
	void draw()
	{
		DrawLine(x1, y1, x2, y2, 2, colors[col]);
	}
};
class Forwarding_unit
{
public:
	int x, y, color;
	Forwarding_unit(int x, int y, int color)
	{
		this->x = x;
		this->y = y;
		this->color = color;
	}
	void draw_unit()
	{
		DrawRoundRect(x, y, 120, 60, colors[this->color], 10);
		DrawString(x + 1, y + 35, "FORWARD", colors[WHITE]);
		DrawString(x + 1, y + 10, "ING", colors[WHITE]);
	}
};
class PC
{
public:
	int x, y, color;
	PC(int x, int y, int color)
	{
		this->x = x;
		this->y = y;
		this->color = color;
	}
	void draw_unit()
	{
		DrawRoundRect(x + 20, y, 30, 70, colors[RED], 0);
		DrawString(x + 19, y + 30, "PC", colors[WHITE]);
	}

};
class Board
{
public:
	Pipeline_reg P1, P2, P3, P4;
	Mem I_Mem, Data_Mem;
	ALU A1, A2, A3;
	MUX m1, m2, m3, m4, m5,m6;
	Reg_File r;
	Hazard_detection h;
	Forwarding_unit f;
	control_unit c;
	PC p;
	sign_extender s, s1;
	shift_left sh;
	L A3_to_p3, p3_mem, f_mux_to_p3, p3_le, mem_p4, imem_p1, m3_m1, m1_alu,
			m2_alu, f_up, f_h;
	L R_p2, R2_p2, FU_M4, FU1_M4, FU_M3, FU1_M3, FU2_M3;
	Board() :
			P4(1100, 35, 400, 70), P3(850, 35, 440, 73), P2(520, 35, 480, 81), P1(
					250, 35, 420, 216), I_Mem(120, 105, 110), Data_Mem(950, 105,
					73), A3(800, 225, 70), A2(400, 420, 231), A1(200, 420, 216), m1(
					690, 275, 70, 80), m2(690, 140, 70, 80), m3(630, 315, 216,
					80), m4(630, 100, 216, 80), A3_to_p3(800, 245, 850, 245,
					70), p3_mem(883, 245, 950, 245, 70), f_mux_to_p3(660, 125,
					850, 125, 216), p3_le(883, 125, 950, 125, 70), mem_p4(1040,
					195, 1100, 195, 70), imem_p1(210, 185, 250, 185, 110), m3_m1(
					660, 330, 690, 330, 216), m1_alu(720, 300, 740, 300, 70), r(
					335, 130, DARK_BLUE), h(300, 580, 10), f(660, 13, PURPLE), c(
					300, 480, 10), p(50, 150, 10), m2_alu(720, 200, 740, 200,
					70), f_up(670, 125, 670, 155, 216), f_h(669, 155, 690, 155,
					216), R_p2(435, 230, 520, 230, 81), R2_p2(435, 170, 520,
					170, 81), FU_M4(645, 100, 645, 35, 216), FU1_M4(645, 35,
					660, 35, 216), FU_M3(610, 25, 660, 25, 216), FU1_M3(610, 25,
					610, 290, 216), FU2_M3(645, 315, 610, 290, 216), m5(1150,
					160, 70, 80), s(310, 65, 110), s1(310, 10, 110), sh(300,
					400, 81)
	{

	}
	void draw_board()
	{
		FU2_M3.draw();
		FU1_M3.draw();
		FU_M3.draw();
		FU1_M4.draw();
		FU_M4.draw();
		R2_p2.draw();
		R_p2.draw();
		f_h.draw();
		f_up.draw();
		m2_alu.draw();
		m1_alu.draw();
		m3_m1.draw();
		imem_p1.draw();
		mem_p4.draw();
		m1.draw_unit();
		m2.draw_unit();
		m3.draw_unit();
		m4.draw_unit();
		m5.draw_unit();
		P1.draw();
		P2.draw();
		P3.draw();
		P4.draw();
		I_Mem.draw_Mem();
		Data_Mem.draw_Mem();
		A1.draw_smallALU();
		A2.draw_smallALU();
		A3.draw_largeALU();
		A3_to_p3.draw();
		p3_mem.draw();
		f_mux_to_p3.draw();
		p3_le.draw();
		r.draw_unit();
		h.draw_unit();
		f.draw_unit();
		c.draw_unit();
		p.draw_unit();
		s.draw_unit();
		s1.draw_unit();
		sh.draw_unit();
		DrawLine(100,185,120,185,2,colors[216]);
		DrawLine(111,185,111,400,2,colors[216]);
		DrawLine(111,400,160,400,2,colors[216]);
		DrawLine(130,460,160,460,2,colors[216]);
		DrawLine(200,430,250,430,2,colors[216]);
		DrawLine(280,450,360,450,2,colors[216]);
		DrawLine(300,610,265,610,2,colors[216]);
		DrawLine(265,610,265,450,2,colors[216]);
		DrawLine(86,615,300,615,2,colors[216]);
		DrawLine(86,615,86,220,2,colors[216]);
		DrawRoundRect(1065, 160, 15, 70, colors[RED]);
		DrawRoundRect(910, 90, 15, 70, colors[RED]);
		DrawString(111,450,"4",colors[216]);
	}
};
#endif
