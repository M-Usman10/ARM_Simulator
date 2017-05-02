#ifndef OBJECTS_H
#define OBJECTS_H
#include "s1.h"
#include "s2.h"
#include "s3.h"
#include "s4.h"
#include "s5.h"
#include <list>
#include <fstream>
#include<vector>
using namespace std;
int read_text = 0;
bool started = false;
vector<string> str;
char get_dest(const string & str)
{
	if (str == "r0")
		return '0';
	if (str == "r1")
		return '1';
	if (str == "r2")
		return '2';
	if (str == "r3")
		return '3';
	if (str == "r4")
		return '4';
	if (str == "r5")
		return '5';
	if (str == "r6")
		return '6';
	if (str == "r7")
		return '7';
	if (str == "r8")
		return '8';
	if (str == "r9")
		return '9';
	if (str == "r10")
		return 'A';
	if (str == "r11")
		return 'B';
	if (str == "r12")
		return 'C';
	if (str == "sp")
		return 'D';
	if (str == "lr")
		return 'E';
	if (str == "pc")
		return 'F';
	return 'i';
}
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
	Mem(int x, int y, int col, int size = 4194304 - 1024)
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
	~Mem()
	{
		delete[] arr;
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
	vector<string> generate_ct(string & str)
	{
		string r1;
		string r2;
		string r3;
		if (str.substr(0, 3) == "E28")
		{
			r1 = "1";
			r2 = "00110100001";
			r3 = "000";
		}
		else if (str.substr(0, 3) == "E08")
		{
			r1 = "1";
			r2 = "00010100001";
			r3 = "000";
		}
		else if (str.substr(0, 3) == "E24")
		{
			r1 = "1";
			r2 = "00111100001";
			r3 = "000";
		}
		else if (str.substr(0, 3) == "E04")
		{
			r1 = "1";
			r2 = "00011100001";
			r3 = "000";
		}
		else if (str.substr(0, 3) == "E3A")
		{
			r1 = "1";
			r2 = "00100100001";
			if (str[3] == 'F')
				r3 = "001";
			else
				r3 = "000";
		}
		else if (str.substr(0, 3) == "E1A")
		{
			r1 = "1";
			r2 = "00000100001";
			if (str[3] == 'F')
				r3 = "001";
			else
				r3 = "000";
		}
		else if (str.substr(0, 3) == "CA0")
		{
			r1 = "1";
			r2 = "00010100001";
			r3 = "000";
		}
		else if (str.substr(0, 3) == "A10" || str.substr(0, 3) == "D10")
		{
			r1 = "1";
			r2 = "00110100001";
			r3 = "000";
		}
		else if (str.substr(0, 3) == "A00" || str.substr(0, 3) == "D00")
		{
			r1 = "1";
			r2 = "00010100001";
			r3 = "000";
		}
		else if (str.substr(0, 3) == "E58")
		{
			r1 = "1";
			r2 = "00110101011";
			r3 = "000";
		}
		else if (str.substr(0, 3) == "E59")
		{
			r1 = "0";
			r2 = "001101001x0";
			r3 = "000";
		}
		else if (str.substr(0, 2) == "BE")
		{
			r1 = "0";
			r2 = "00000000000";
			r3 = "100";
		}
		else if (str.substr(0, 2) == "BA")
		{
			r1 = "0";
			r2 = "11000100001";
			r3 = "010";
		}
		vector<string> res;
		res.push_back(r1);
		res.push_back(r2);
		res.push_back(r3);
		return res;
	}
	string get(const string & str)
	{
		string res = "";
		if (str.substr(0, 3) == "ADD")
		{
			if (str[10] > 47 && str[10] < 59)
				res = "E28";
			else
				res = "E08";
			res.push_back(get_dest(str.substr(4, 2)));
		}
		else if (str.substr(0, 3) == "SUB")
		{
			if (str[10] > 47 && str[10] < 59)
				res = "E24";
			else
				res = "E04";
			res.push_back(get_dest(str.substr(4, 2)));
		}
		else if (str.substr(0, 3) == "MOV")
		{
			if (str[10] > 47 && str[10] < 59)
				res = "E3A";
			else
				res = "E1A";
			res.push_back(get_dest(str.substr(4, 2)));
		}
		else if (str.substr(0, 3) == "CMP")
		{
			res = "CA00";
		}
		else if (str.substr(0, 3) == "AND")
		{
			if (str[10] > 47 && str[10] < 59)
				res = "A100";
			else
				"A000";
		}
		else if (str.substr(0, 2) == "OR")
		{
			if (str[10] > 47 && str[10] < 59)
				res = "D100";
			else
				"D000";
		}
		else if (str.substr(0, 3) == "LDR")
		{
			res = "E58";
			res.push_back(get_dest(str.substr(4, 2)));
		}
		else if (str.substr(0, 3) == "STR")
		{
			res = "E59";
			res.push_back(get_dest(str.substr(4, 2)));
		}
		else if (str.substr(0, 3) == "BEQ")
		{
			res = "BE00";
		}
		else if (str.substr(0, 2) == "BL")
		{
			res = "BA00";
		}
		return res;
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
	string get(const string & r_no)
	{
		if (r_no == "r0")
			return to_string(r0);
		if (r_no == "r1")
			return to_string(r1);
		if (r_no == "r2")
			return to_string(r2);
		if (r_no == "r3")
			return to_string(r3);
		if (r_no == "r4")
			return to_string(r4);
		if (r_no == "r5")
			return to_string(r5);
		if (r_no == "r6")
			return to_string(r6);
		if (r_no == "r7")
			return to_string(r7);
		if (r_no == "r8")
			return to_string(r8);
		if (r_no == "r9")
			return to_string(r9);
		if (r_no == "r10")
			return to_string(r10);
		if (r_no == "r11")
			return to_string(r11);
		if (r_no == "r12")
			return to_string(r12);
		if (r_no == "sp")
			return to_string(sp);
		if (r_no == "lr")
			return to_string(lr);
		return "Inv";

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
		if (size > 100)
			DrawString(x + 9, y + 90, "2", colors[WHITE]);
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
		DrawString(x, y + 20, "EXT", colors[WHITE]);
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
		DrawString(x + 5, y + 4, "S", colors[WHITE]);
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
		DrawString(x + 1, y + 10, "      ING", colors[WHITE]);
	}
};
class PC
{
public:
	int x, y, color, index;
	PC(int x, int y, int color)
	{
		index = 0;
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
	int counter;
	vector<string> instructoins;
	Pipeline_reg P1, P2, P3, P4;
	Stage1 Sta1;
	Stage2 Sta2;
	Stage4 Sta4;
	Stage5 Sta5;
	Stage3 Sta3;
	Mem I_Mem, Data_Mem;
	ALU A1, A2, A3;
	MUX m1, m2, m3, m4, m5, m6, m7;
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
					250, 35, 420, 216), I_Mem(120, 105, 110, 1024), Data_Mem(
					950, 105, 73), A3(800, 225, 70), A2(400, 420, 231), A1(200,
					420, 216), m1(690, 275, 70, 80), m2(690, 140, 70, 120), m3(
					630, 315, 216, 120), m4(630, 100, 216, 120), m6(460, 475,
					70, 81), m7(35, 130, 81, 120), A3_to_p3(800, 245, 850, 245,
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
					160, 70, 80), s(310, 65, 110), s1(410, 15, 110), sh(300,
					400, 81), counter(0)
	{

	}
	void draw_board()
	{
		if (started)
		{
			ins_s1();
			ins_s2();
			ins_s3();
		}
		m7.draw_unit();
		m6.draw_unit();
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
		DrawLine(1132, 215, 1150, 215, 1, colors[BLACK]);
		DrawLine(1132, 65, 1150, 65, 1, colors[PURPLE]);
		DrawLine(1150, 65, 1150, 20, 1, colors[PURPLE]);
		DrawLine(1150, 20, 781, 20, 1, colors[PURPLE]);
		DrawLine(883, 55, 1102, 55, 1, colors[BLACK]);
		DrawLine(900, 55, 900, 30, 1, colors[PURPLE]);
		DrawLine(900, 30, 781, 30, 1, colors[PURPLE]);
		DrawLine(630, 330, 600, 330, 1, colors[216]);
		DrawLine(600, 330, 600, 12, 1, colors[216]);
		DrawLine(600, 12, 940, 12, 1, colors[216]);
		DrawLine(940, 12, 940, 244, 1, colors[216]);
		DrawLine(940, 92, 1100, 92, 1, colors[216]);
		DrawLine(1132, 92, 1148, 92, 1, colors[BLACK]);
		DrawLine(1148, 92, 1148, 180, 1, colors[BLACK]);
		DrawLine(1148, 180, 1151, 180, 1, colors[BLACK]);
		DrawLine(1181, 200, 1197, 200, 1, colors[BLACK]);
		DrawLine(1197, 200, 1197, 8, 1, colors[BLACK]);
		DrawLine(1197, 8, 300, 8, 1, colors[BLACK]);
		DrawLine(596, 7, 596, 370, 1, colors[BLACK]);
		DrawLine(596, 370, 631, 370, 1, colors[BLACK]);
		DrawLine(552, 58, 660, 58, 1, colors[PURPLE]);
		DrawLine(552, 48, 660, 48, 1, colors[PURPLE]);
		DrawLine(552, 414, 631, 414, 1, colors[216]);
		DrawLine(553, 170, 624, 170, 1, colors[216]);
		DrawLine(624, 170, 624, 195, 1, colors[216]);
		DrawLine(624, 195, 631, 195, 1, colors[216]);
		DrawLine(600, 117, 631, 117, 1, colors[216]);
		DrawLine(596, 156, 630, 156, 1, colors[BLACK]);
		DrawRoundRect(566, 76, 20, 80, colors[216], 15);
		DrawString(570, 85, "0", colors[WHITE]);
		DrawString(570, 120, "1", colors[WHITE]);
		DrawLine(552, 127, 566, 127, 1, colors[216]);
		DrawLine(552, 107, 566, 107, 1, colors[216]);
		DrawLine(560, 126, 560, 607, 1, colors[216]);
		DrawLine(560, 607, 421, 607, 1, colors[216]);
		DrawLine(552, 460, 850, 460, 1, colors[BLACK]);
		DrawLine(884, 422, 1100, 422, 1, colors[BLACK]);
		DrawLine(705, 460, 705, 355, 1, colors[BLACK]);
		DrawLine(670, 460, 670, 260, 1, colors[BLACK]);
		DrawLine(670, 260, 705, 260, 1, colors[BLACK]);
		DrawLine(760, 460, 760, 300, 1, colors[216]);
		DrawLine(104, 185, 120, 185, 1, colors[216]);
		DrawLine(104, 185, 104, 400, 1, colors[216]);
		DrawLine(104, 400, 160, 400, 1, colors[216]);
		DrawLine(104, 185, 100, 185, 1, colors[216]);
		DrawLine(130, 460, 160, 460, 1, colors[216]);
		DrawLine(200, 430, 250, 430, 1, colors[216]);
		DrawLine(280, 450, 360, 450, 1, colors[216]);
		DrawLine(300, 610, 265, 610, 1, colors[216]);
		DrawLine(265, 610, 265, 450, 1, colors[216]);
		DrawLine(86, 615, 300, 615, 1, colors[216]);
		DrawLine(86, 615, 86, 220, 1, colors[216]);
		DrawLine(475, 615, 420, 615, 1, colors[216]);
		DrawLine(475, 615, 475, 555, 1, colors[216]);
		DrawLine(490, 500, 520, 500, 1, colors[216]);
		DrawLine(320, 400, 320, 115, 1, colors[110]);
		DrawLine(325, 410, 360, 410, 1, colors[231]);
		DrawLine(400, 435, 435, 435, 1, colors[231]);
		DrawLine(435, 435, 435, 655, 1, colors[231]);
		DrawLine(10, 655, 435, 655, 1, colors[231]);
		DrawLine(10, 655, 10, 220, 1, colors[231]);
		DrawLine(10, 220, 35, 220, 1, colors[231]);
		DrawLine(320, 518, 460, 518, 1, colors[70]);
		DrawLine(425, 500, 460, 500, 1, colors[70]);
		DrawLine(445, 230, 445, 670, 1, colors[81]);
		DrawLine(25, 670, 445, 670, 1, colors[81]);
		DrawLine(25, 670, 25, 180, 1, colors[81]);
		DrawLine(215, 430, 215, 505, 1, colors[216]);
		DrawLine(18, 505, 215, 505, 1, colors[216]);
		DrawLine(18, 505, 18, 150, 1, colors[216]);
		DrawLine(18, 150, 35, 150, 1, colors[216]);
		DrawLine(25, 180, 35, 180, 1, colors[81]);
		DrawLine(460, 35, 480, 35, 1, colors[216]);
		DrawLine(480, 200, 480, 35, 1, colors[216]);
		DrawLine(480, 200, 520, 200, 1, colors[216]);
		DrawLine(340, 365, 340, 450, 1, colors[216]);
		DrawLine(340, 365, 520, 365, 1, colors[216]);
		DrawLine(575, 458, 575, 154, 1, colors[216]);
		DrawLine(972, 422, 972, 284, 1, colors[216]);
		DrawLine(992, 422, 992, 284, 1, colors[216]);
		DrawLine(1132, 420, 1162, 420, 1, colors[216]);
		DrawLine(1162, 420, 1162, 240, 1, colors[216]);
		DrawLine(892, 422, 892, 25, 1, colors[216]);
		DrawLine(892, 25, 781, 25, 1, colors[216]);
		DrawLine(1140, 420, 1140, 15, 1, colors[BLUE]);
		DrawLine(1140, 15, 781, 15, 1, colors[BLUE]);
		DrawRoundRect(840, 595, 60, 30, colors[216], 0);
		DrawRoundRect(566, 76, 20, 80, colors[216], 15);
		DrawCircle(760, 600, 30, colors[81]);
		DrawLine(865, 594, 865, 500, 1, colors[216]);
		DrawLine(865, 500, 771, 500, 1, colors[216]);
		DrawLine(771, 500, 771, 290, 1, colors[216]);
		DrawLine(771, 500, 771, 573, 1, colors[216]);
		DrawLine(738, 460, 738, 579, 1, colors[216]);
		DrawLine(750, 460, 750, 570, 1, colors[216]);
		DrawLine(762, 460, 762, 570, 1, colors[216]);
		DrawLine(551, 195, 620, 195, 1, colors[216]);
		DrawLine(580, 100, 850, 100, 1, colors[216]);
		DrawLine(295, 180, 282, 180, 1, colors[250]);
		DrawLine(295, 500, 295, 35, 1, colors[250]);
		DrawLine(295, 85, 310, 85, 1, colors[250]);
		DrawLine(295, 35, 411, 35, 1, colors[250]);
		DrawLine(295, 500, 300, 500, 1, colors[250]);
		DrawRoundRect(1065, 160, 15, 70, colors[RED]);
		DrawRoundRect(910, 90, 15, 70, colors[RED]);
		DrawString(111, 450, "4", colors[216]);
		DrawString(410, 485, "0", colors[216]);
		DrawLine(65, 186, 75, 186, 1, colors[216]);
		DrawLine(757, 628, 757, 664, 1, colors[216]);
		DrawLine(757, 664, 51, 664, 1, colors[216]);
		DrawLine(51, 664, 51, 250, 1, colors[216]);
		DrawLine(553, 365, 585, 365, 1, colors[216]);
		DrawLine(585, 365, 585, 240, 1, colors[216]);
		DrawLine(585, 240, 690, 240, 1, colors[216]);
		DrawLine(620, 194, 620, 230, 1, colors[216]);
		DrawLine(620, 230, 675, 230, 1, colors[216]);
		DrawLine(675, 230, 675, 195, 1, colors[216]);
		DrawLine(675, 195, 690, 195, 1, colors[216]);
		DrawLine(295, 270, 335, 270, 1, colors[250]);
		DrawLine(300, 7, 300, 140, 1, colors[BLACK]);
		DrawLine(300, 140, 335, 140, 1, colors[BLACK]);
		DrawString(703, 640, "PC_SELECTOR", colors[BLACK]);
		DrawRoundRect(300, 198, 15, 70, colors[216], 10);
		DrawLine(315, 233, 335, 233, 1, colors[216]);
		DrawLine(295, 245, 300, 245, 1, colors[LIGHT_BLUE]);
		DrawLine(297, 180, 335, 180, 1, colors[LIGHT_BLUE]);
		DrawLine(297, 180, 297, 210, 1, colors[BLACK]);
		DrawLine(297, 210, 300, 210, 1, colors[BLACK]);
		DrawString(920, 600, "FLAG", colors[BLACK]);
		DrawLine(340, 519, 340, 535, 1, colors[BLACK]);
		DrawLine(340, 535, 238, 535, 1, colors[BLACK]);
		DrawLine(238, 535, 238, 55, 1, colors[BLACK]);
		DrawLine(237, 55, 252, 55, 1, colors[BLACK]);
		DrawLine(320, 496, 325, 496, 1, colors[PURPLE]);
		DrawLine(325, 496, 325, 466, 1, colors[PURPLE]);
		DrawLine(325, 466, 300, 466, 1, colors[PURPLE]);
		DrawLine(300, 466, 300, 388, 1, colors[PURPLE]);
		DrawLine(300, 388, 308, 388, 1, colors[PURPLE]);
		DrawLine(308, 388, 308, 267, 1, colors[PURPLE]);
		DrawLine(320, 510, 450, 510, 1, colors[PURPLE]);
		DrawLine(450, 510, 450, 600, 1, colors[PURPLE]);
		DrawLine(450, 600, 733, 600, 1, colors[PURPLE]);

		Sta1.Draw();
		Sta2.Draw();
		Sta3.Draw();
		Sta4.Draw();
		Sta5.Draw();
		if (started)
		{
			Sta1.move();
			Sta2.move();
			Sta3.move();
			Sta4.move();
			Sta5.move();
		}
	}
	void ins_s1()
	{
		counter++;
		counter %= 781;
		switch (counter)
		{
		case 1:
			Sta1.pc_mem.first = to_string(p.index);
			Sta1._4_alu.first = "4";
			Sta1.pc_alu.first = to_string(p.index);
			break;
		case 130:
			Sta1.mem_p1.first = instructoins[p.index / 4];
			break;
		case 190:
			Sta1.alu_mux.first = to_string(p.index + 4);
			Sta1.alu_p1.first = to_string(p.index + 4);
			break;
		case 780:
			p.index += 4;
			p.index %= instructoins.size() * 4;
			Sta1.ReInit();
		}
	}
	void ins_s2()
	{
		switch (counter)
		{
		case 779:
			Sta2.ReInit();
			Sta2.p1_ctrl.first = c.get(Sta1.mem_p1.first);
			Sta2.p1_alu.first = Sta1.alu_p1.first;
			if (Sta1.mem_p1.first.substr(0, 3) == "AND"
					|| Sta1.mem_p1.first.substr(0, 2) == "OR"
					|| Sta1.mem_p1.first.substr(0, 3) == "ADD"
					|| Sta1.mem_p1.first.substr(0, 3) == "SUB")
			{
				Sta2.p1_reg.first = Sta1.mem_p1.first.substr(
						Sta1.mem_p1.first.find(",") + 1,
						Sta1.mem_p1.first.find(",",
								Sta1.mem_p1.first.find(",") + 2)
								- Sta1.mem_p1.first.find(",") - 1);
				Sta2.p1_mux.first = Sta1.mem_p1.first.substr(
						Sta1.mem_p1.first.find(" ") + 1,
						Sta1.mem_p1.first.find(",")
								- Sta1.mem_p1.first.find(" ") - 1);
				Sta2.p1_mux2.first = Sta1.mem_p1.first.substr(
						Sta1.mem_p1.first.find(",",
								Sta1.mem_p1.first.find(",") + 1) + 1,
						Sta1.mem_p1.first.length() - 10);
			}
			else if (Sta1.mem_p1.first.substr(0, 3) == "MOV"
					|| Sta1.mem_p1.first.substr(0, 3) == "CMP")
			{
				Sta2.p1_reg.first = Sta1.mem_p1.first.substr(
						Sta1.mem_p1.first.find(",") + 1,
						Sta1.mem_p1.first.length() - 7);
				Sta2.p1_mux.first = Sta1.mem_p1.first.substr(
						Sta1.mem_p1.first.find(" ") + 1,
						Sta1.mem_p1.first.find(",")
								- Sta1.mem_p1.first.find(" ") - 1);
			}
			else if (Sta1.mem_p1.first.substr(0, 1) == "B"
					|| Sta1.mem_p1.first.substr(0, 2) == "BL")
			{
				if (Sta1.mem_p1.first.substr(0, 2) == "BL")
				{
					Sta2.p1_mux.first = "lr";
					Sta2.p1_ext.first = Sta1.mem_p1.first.substr(
							Sta1.mem_p1.first.find(" ") + 1,
							Sta1.mem_p1.first.length() - 3);
				}
				else
					Sta2.p1_ext.first = Sta1.mem_p1.first.substr(
							Sta1.mem_p1.first.find(" ") + 1,
							Sta1.mem_p1.first.length() - 2);
			}
			else
			{
				Sta2.p1_reg.first = Sta1.mem_p1.first.substr(
						Sta1.mem_p1.first.find(",") + 2,
						Sta1.mem_p1.first.find(",",
								Sta1.mem_p1.first.find(",") + 2)
								- Sta1.mem_p1.first.find(",") - 2);
				Sta2.p1_mux.first = Sta1.mem_p1.first.substr(
						Sta1.mem_p1.first.find(" ") + 1,
						Sta1.mem_p1.first.find(",")
								- Sta1.mem_p1.first.find(" ") - 1);
				Sta2.p1_ext1.first = Sta1.mem_p1.first.substr(12,
						Sta1.mem_p1.first.length() - 13);
			}

			break;
		case 140:
			Sta2.p1_p2.first = Sta2.p1_alu.first;
			Sta2.ext1_sh.first = Sta2.p1_ext.first;
			if (Sta2.p1_reg.first.length())
			{
				Sta2.reg_p2_s1.first = r.get(Sta2.p1_reg.first);
				Sta2.reg_pc.first = r.get(Sta2.p1_reg.first);
			}
			break;
		case 280:
			if (Sta2.p1_ext.first.length())
				Sta2.sh_alu.first = to_string(stoi(Sta2.p1_ext.first) * 4);
			else if (Sta2.p1_ext1.first.length())
				Sta2.ext2_p2.first = Sta2.p1_ext1.first;
			break;
		case 320:
			if (Sta2.p1_ext.first.length())
				Sta2.alu_pc_mux.first = to_string(
						stoi(Sta2.p1_ext.first) * 4 + stoi(Sta2.p1_alu.first));
			Sta2.ctrl_mux.first = c.generate_ct(Sta2.p1_ctrl.first)[1];
			Sta2.ctrl_mux1.first = c.generate_ct(Sta2.p1_ctrl.first)[0];
			if (Sta2.ctrl_mux.first.length())
				Sta2._0_mux.first = "0";
			break;
		case 430:
			Sta2.mux_p2.first = Sta2.ctrl_mux.first;
			if (c.generate_ct(Sta2.p1_ctrl.first)[0] == "0")
				Sta2.reg_p2_s2.first = r.get(Sta2.p1_mux.first);
			else if(c.generate_ct(Sta2.p1_ctrl.first)[0] == "1")
				Sta2.reg_p2_s2.first = r.get(Sta2.p1_mux2.first);
		}

	}
	void ins_s3()
	{
		static bool _1st=false;
        switch(counter)
        {
           case 778:
        	   if(_1st)
        	   {
                  Sta3.alu_op.first=Sta2.mux_p2.first.substr(4,3);
                  Sta3.p3_p4.first=Sta2.mux_p2.first;
                  Sta3.p3_selector1.first=Sta2.mux_p2.first.substr(1,2);
        	   }
              _1st=true;
        }
	}
};
#endif
