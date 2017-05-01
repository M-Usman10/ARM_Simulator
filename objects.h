#ifndef OBJECTS_H
#define OBJECTS_H
#include <list>
#include <fstream>
#include<vector>
using namespace std;
int read_text = 0;
bool started = false;
template<class T, class T2>
class my_pair
{
public:
	T first;
	T2 second;
	my_pair()
	{

	}
	my_pair(T f, T2 s)
	{
		first = f;
		second = s;
	}
	bool operator==(const my_pair<T, T2> & p) const
	{
		return first == p.first;
	}
};
struct Coor
{
	float x, y;
	Coor(int x1 = 0, int y1 = 0)

	{
		x = x1;
		y = y1;
	}
};
vector<string> str;
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
class Stage1
{
public:
	my_pair<string, Coor> pc_mem;
	my_pair<string, Coor> mem_p1;
	my_pair<string, Coor> pc_alu;
	my_pair<string, Coor> _4_alu;
	my_pair<string, Coor> alu_p1;
	my_pair<string, Coor> alu_mux;
	Stage1()
	{
		pc_mem.second.x = 95;
		pc_mem.second.y = 180;
		mem_p1.second.x = 205;
		mem_p1.second.y = 184;
		pc_alu.second.x = 100;
		pc_alu.second.y = 185;
		_4_alu.second.x = 132;
		_4_alu.second.y = 458;
		alu_p1.second.x = 201;
		alu_p1.second.y = 420;
		alu_mux.second.x = 215;
		alu_mux.second.y = 430;
	}
	void Draw()
	{
		DrawRoundRect(pc_mem.second.x, pc_mem.second.y, pc_mem.first.length() * 8, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(mem_p1.second.x, mem_p1.second.y, mem_p1.first.length() * 5, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(pc_alu.second.x, pc_alu.second.y, pc_alu.first.length() * 8, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(_4_alu.second.x, _4_alu.second.y, _4_alu.first.length() * 8, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(alu_p1.second.x, alu_p1.second.y, alu_p1.first.length() * 8, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(alu_mux.second.x, alu_mux.second.y, alu_mux.first.length() * 8, 16,
				colors[LIGHT_BLUE], 5);

		DrawStringsmall(pc_mem.second.x + 1.5, pc_mem.second.y + 4, pc_mem.first,
				colors[BLACK]);
		DrawStringsmall(mem_p1.second.x + 1.5, mem_p1.second.y + 4, mem_p1.first,
				colors[BLACK]);
		DrawStringsmall(pc_alu.second.x + 1.5, pc_alu.second.y + 4, pc_alu.first,
				colors[BLACK]);
		DrawStringsmall(_4_alu.second.x + 1.5, _4_alu.second.y + 4, _4_alu.first,
				colors[BLACK]);
		DrawStringsmall(alu_p1.second.x + 1.5, alu_p1.second.y + 4, alu_p1.first,
				colors[BLACK]);
		DrawStringsmall(alu_mux.second.x + 1.5, alu_mux.second.y + 4,
				alu_mux.first, colors[BLACK]);

	}
	void move()
	{
		if (pc_mem.second.x < 120)
			pc_mem.second.x = pc_mem.second.x + .2;
		if (pc_mem.second.x > 119 && mem_p1.second.x < 233)
			mem_p1.second.x = mem_p1.second.x + .2;
		if (pc_alu.second.y < 390)
			pc_alu.second.y = pc_alu.second.y + 1.5;
		if (pc_alu.second.y >= 389)
		{
			if (pc_alu.second.x < 155)
				pc_alu.second.x = pc_alu.second.x + 1;
		}
		if (_4_alu.second.x < 150)
			_4_alu.second.x = _4_alu.second.x + .2;
		if (alu_p1.second.x < 245 && pc_alu.second.y >= 389
				&& pc_alu.second.x >= 150)
			alu_p1.second.x = alu_p1.second.x + .2;
		if (alu_mux.second.y < 504 && alu_mux.second.x == 215
				&& pc_alu.second.y >= 389 && pc_alu.second.x >= 150)
		{
			alu_mux.second.y = alu_mux.second.y + 1.5;
		}
		if (alu_mux.second.y >= 503 && alu_mux.second.x > 16
				&& pc_alu.second.y >= 389 && pc_alu.second.x >= 150)
			alu_mux.second.x = alu_mux.second.x - 1.5;
		if (alu_mux.second.y >= 150 && alu_mux.second.x < 17
				&& pc_alu.second.y >= 389 && pc_alu.second.x >= 150)
			alu_mux.second.y = alu_mux.second.y - 1.5;
		if (alu_mux.second.y < 151 && alu_mux.second.x < 35
				&& pc_alu.second.y >= 389 && pc_alu.second.x >= 150)
			alu_mux.second.x = alu_mux.second.x + 1.5;
	}
};
class Stage2
{
public:
	my_pair<string, Coor> p1_alu;
	my_pair<string, Coor> sh_alu;
	my_pair<string, Coor> alu_pc_mux;
	my_pair<string, Coor> p1_p2;
	my_pair<string, Coor> p1_ext1;
	my_pair<string, Coor> p1_ext2;
	my_pair<string, Coor> ext1_sh;
	my_pair<string, Coor> ext2_p2;
	my_pair<string, Coor> reg_p2_s1;
	my_pair<string, Coor> reg_pc;
	my_pair<string, Coor> reg_p2_s2;
	my_pair<string, Coor> p1_ctrl;
	my_pair<string, Coor> ctrl_mux;
	my_pair<string, Coor> _0_mux;
	my_pair<string, Coor> mux_p2;
	my_pair<string, Coor> ctrl_p1;
	int token_1;
	my_pair<string, Coor> p1;
	my_pair<string, Coor> p1_mux;
	my_pair<string, Coor> p1_mux2;
	my_pair<string, Coor> p1_ext;
	my_pair<string, Coor> p1_reg;
	Stage2()
	{
		token_1 = 0;
		p1_p2.second.x = 340;
		p1_p2.second.y = 428;
		p1_ctrl.second.x = 285;
		p1_ctrl.second.y = 270;
		ctrl_mux.second.x = 325;
		ctrl_mux.second.y = 515;
		_0_mux.second.x = 428;
		_0_mux.second.y = 496;
		ctrl_p1.second.x = 330;
		ctrl_p1.second.y = 520;
		mux_p2.second.x = 490;
		mux_p2.second.y = 500;
		alu_pc_mux.second.x = 405;
		alu_pc_mux.second.y = 435;
		sh_alu.second.x = 330;
		sh_alu.second.y = 407;
		p1_alu.second.x = 285;
		p1_alu.second.y = 453;

		reg_p2_s2.second.x = 440;
		reg_p2_s2.second.y = 170;
		reg_p2_s1.second.x = 440;
		reg_p2_s1.second.y = 230;
		reg_pc.second.x = 438;
		reg_pc.second.y = 240;

		ext2_p2.second.x = 465;
		ext2_p2.second.y = 45;
		ext1_sh.second.x = 314;
		ext1_sh.second.y = 116;
		p1_ext1.second.x = 297;
		p1_ext1.second.y = 87;
		p1_ext1.second.x = 293;
		p1_ext1.second.y = 82;
		p1.second.x = 284;
		p1.second.y = 178;
		p1_mux.second.x = 285;
		p1_mux.second.y = 178;
		p1_mux2.second.x = 285;
		p1_mux2.second.y = 178;
		p1_ext.second.x = 285;
		p1_ext.second.y = 178;
		p1_reg.second.x = 285;
		p1_reg.second.y = 271;

	}
	void Draw()
	{
		DrawRoundRect(p1_alu.second.x, p1_alu.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(sh_alu.second.x, sh_alu.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(alu_pc_mux.second.x, alu_pc_mux.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);

		DrawRoundRect(p1_p2.second.x, p1_p2.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);

		DrawRoundRect(p1_ext1.second.x, p1_ext1.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(p1_ext2.second.x, p1_ext2.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(ext1_sh.second.x, ext1_sh.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(ext2_p2.second.x, ext2_p2.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);

		DrawRoundRect(reg_p2_s1.second.x, reg_p2_s1.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);

		DrawRoundRect(reg_pc.second.x, reg_pc.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);

		DrawRoundRect(reg_p2_s2.second.x, reg_p2_s2.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(p1_ctrl.second.x, p1_ctrl.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);

		DrawRoundRect(ctrl_mux.second.x, ctrl_mux.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(_0_mux.second.x, _0_mux.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);

		DrawRoundRect(mux_p2.second.x, mux_p2.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(ctrl_p1.second.x, ctrl_p1.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(p1.second.x, p1.second.y, 22, 16, colors[LIGHT_BLUE], 5);
		DrawRoundRect(p1_mux.second.x, p1_mux.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(p1_mux2.second.x, p1_mux2.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(p1_ext.second.x, p1_ext.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(p1_reg.second.x, p1_reg.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);

	}
	void move()
	{
		if (p1_alu.second.x < 345)
			p1_alu.second.x += 0.5;
		if (p1_alu.second.x > 335 && p1_p2.second.y > 369)
			p1_p2.second.y -= 1.0;
		else if (p1_alu.second.x > 335 && p1_p2.second.x < 500)
			p1_p2.second.x += 1.0;
		if (sh_alu.second.x < 345 && ext1_sh.second.y > 398)
			sh_alu.second.x += 0.5;
		if (alu_pc_mux.second.x < 410 && p1_alu.second.x == 345
				&& alu_pc_mux.second.y < 640 && alu_pc_mux.second.x > 300
				&& sh_alu.second.x > 343)
			alu_pc_mux.second.x += 0.5;
		else if (alu_pc_mux.second.y < 640 && p1_alu.second.x == 345
				&& alu_pc_mux.second.x > 15 && token_1 == 0
				&& sh_alu.second.x > 343)
			alu_pc_mux.second.y += 2;
		else if (alu_pc_mux.second.y == 641 && alu_pc_mux.second.x > 10)
			alu_pc_mux.second.x -= 3;
		else if (alu_pc_mux.second.y > 220 && alu_pc_mux.second.x < 15)
			alu_pc_mux.second.y -= 3;
		if (alu_pc_mux.second.y < 223 && alu_pc_mux.second.x < 40)
		{
			alu_pc_mux.second.x++;
			token_1 = 1;
		}
		if (alu_pc_mux.second.y > 500 && _0_mux.second.x < 460
				&& _0_mux.second.y == 496)
			_0_mux.second.x++;
		if (_0_mux.second.x > 455 && mux_p2.second.x < 515)
			mux_p2.second.x++;
		if (ctrl_mux.second.x < 460 && ctrl_mux.second.y == 515)
			ctrl_mux.second.x++;
		if (ctrl_p1.second.y < 530 && ctrl_p1.second.x == 330)
			ctrl_p1.second.y++;
		if (ctrl_p1.second.y > 527 && ctrl_p1.second.x > 225)
			ctrl_p1.second.x = ctrl_p1.second.x - 2;
		if (ctrl_p1.second.y > 54 && ctrl_p1.second.x < 227
				&& ctrl_p1.second.x > 222)
			ctrl_p1.second.y = ctrl_p1.second.y - 2;
		if (ctrl_p1.second.y < 57 && ctrl_p1.second.x < 253
				&& ctrl_p1.second.x > 222)
			ctrl_p1.second.x = ctrl_p1.second.x + 2;
		if (p1.second.x < 330)
			p1.second.x = p1.second.x + 1;
		if (p1.second.x > 283 && p1_mux.second.y < 208)
			p1_mux.second.y = p1_mux.second.y + 1;
		if (p1_mux.second.x < 303 && p1_mux.second.y > 206)
			p1_mux.second.x = p1_mux.second.x + 1;
		if (p1.second.x > 283 && p1_mux2.second.y < 246)
			p1_mux2.second.y = p1_mux2.second.y + 1;
		if (p1_mux2.second.x < 303 && p1_mux2.second.y > 243)
			p1_mux2.second.x = p1_mux2.second.x + 1;
		if (p1_mux2.second.y > 243 && p1_ctrl.second.y < 500)
			p1_ctrl.second.y++;
		if (p1_mux2.second.y > 243 && p1_reg.second.x < 330)
			p1_reg.second.x++;
		if (p1_reg.second.x > 325 && reg_p2_s2.second.x < 520)
			reg_p2_s2.second.x++;
		if (p1_reg.second.x > 325 && reg_p2_s1.second.x < 520)
			reg_p2_s1.second.x++;
		if (p1_reg.second.x > 325 && reg_pc.second.y < 658
				&& reg_pc.second.x > 24 && reg_pc.second.y > 220)
			reg_pc.second.y += 3;
		if (reg_pc.second.x > 20 && reg_pc.second.y > 655)
			reg_pc.second.x -= 3;
		if (reg_pc.second.x < 24 && reg_pc.second.y > 180)
			reg_pc.second.y -= 3;
		if (reg_pc.second.x < 35 && reg_pc.second.y < 182)
			reg_pc.second.x += 3;
		if (p1.second.x > 286 && p1_ext.second.y > 85 && p1_ext.second.x == 285)
			p1_ext.second.y = p1_ext.second.y - 1;
		if (p1_ext.second.y < 86 && p1_ext.second.x < 310)
			p1_ext.second.x = p1_ext.second.x + 1;
		if (p1_ext.second.y < 86 && p1_ext1.second.y > 37)
			p1_ext1.second.y = p1_ext1.second.y - 1;
		if (p1_ext1.second.x < 410 && p1_ext1.second.y < 39)
			p1_ext1.second.x = p1_ext1.second.x + 1;
		if (p1_ext1.second.x > 408 && ext2_p2.second.y < 195)
			ext2_p2.second.y = ext2_p2.second.y + 1;
		if (ext2_p2.second.x < 517 && ext2_p2.second.y > 193)
			ext2_p2.second.x = ext2_p2.second.x + 1;
		if (p1_ext.second.x > 308 && ext1_sh.second.y < 400)
			ext1_sh.second.y = ext1_sh.second.y + 2;
	}
};
class Stage4
{
public:
	my_pair<string, Coor> p4_mem;
	my_pair<string, Coor> mem_conv;
	my_pair<string, Coor> conv_p5;
	my_pair<string, Coor> p4_p5up;
	my_pair<string, Coor> p4_p5down;
	my_pair<string, Coor> p4_conv;
	my_pair<string, Coor> conv_mem;
	my_pair<string, Coor> p4_mem1;
	my_pair<string, Coor> p4_mem2;
	my_pair<string, Coor> p4_mux1;
	my_pair<string, Coor> p4_mux2;
	my_pair<string, Coor> p4_p5mid;
	my_pair<string, Coor> p4_fwdctrl;
	my_pair<string, Coor> p4_fwddata;
	Stage4()
	{
		p4_mem.second.x = 882;
		p4_mem.second.y = 244;
		mem_conv.second.x = 1040;
		mem_conv.second.y = 195;
		conv_p5.second.x = 1080;
		conv_p5.second.y = 195;
		p4_p5up.second.x = 882;
		p4_p5up.second.y = 422;
		p4_p5down.second.x = 882;
		p4_p5down.second.y = 54;
		p4_conv.second.x = 882;
		p4_conv.second.y = 123;
		conv_mem.second.x = 925;
		conv_mem.second.y = 123;
		p4_mem1.second.x = 970;
		p4_mem1.second.y = 422;
		p4_mem2.second.x = 992;
		p4_mem2.second.y = 422;
		p4_p5mid.second.x = 935;
		p4_p5mid.second.y = 88;
		p4_fwdctrl.second.x = 882;
		p4_fwdctrl.second.y = 420;
		p4_fwddata.second.x = 900;
		p4_fwddata.second.y = 56;
		p4_mux1.second.x = 925;
		p4_mux1.second.y = 240;
		p4_mux2.second.x = 584.5;
		p4_mux2.second.y = 108;
	}
	void Draw()
	{
		DrawRoundRect(p4_mem.second.x, p4_mem.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(mem_conv.second.x, mem_conv.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(conv_p5.second.x, conv_p5.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(p4_p5up.second.x, p4_p5up.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(p4_p5down.second.x, p4_p5down.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(p4_conv.second.x, p4_conv.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(conv_mem.second.x, conv_mem.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(p4_mem1.second.x, p4_mem1.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(p4_mem2.second.x, p4_mem2.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(p4_p5mid.second.x, p4_p5mid.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(p4_fwdctrl.second.x, p4_fwdctrl.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(p4_fwddata.second.x, p4_fwddata.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(p4_mux1.second.x, p4_mux1.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(p4_mux2.second.x, p4_mux2.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);

	}
	void move()
	{
		if (p4_mem.second.x < 950)
			p4_mem.second.x = p4_mem.second.x + 0.4;
		if (mem_conv.second.x < 1050)
		{

			mem_conv.second.x = mem_conv.second.x + 0.2;
		}
		else if (conv_p5.second.x < 1102)
		{
			conv_p5.second.x = conv_p5.second.x + 0.2;
		}
		if (p4_conv.second.x < 895)
			p4_conv.second.x = p4_conv.second.x + 0.2;
		else if (conv_mem.second.x < 950)
			conv_mem.second.x = conv_mem.second.x + 0.2;
		if (p4_p5down.second.x < 1100)
			p4_p5down.second.x = p4_p5down.second.x + 0.5;
		if (p4_p5down.second.x > 910 && p4_fwddata.second.y > 21)
			p4_fwddata.second.y = p4_fwddata.second.y - 0.5;
		if (p4_fwddata.second.y < 23 && p4_fwddata.second.x > 765)
			p4_fwddata.second.x = p4_fwddata.second.x - 0.5;
		if (p4_mem.second.x > 920)
		{
			if (p4_mux1.second.y > 4 && p4_mux1.second.x == 925)
				p4_mux1.second.y = p4_mux1.second.y - 1.5;
			if (p4_mux1.second.y < 6 && p4_mux1.second.x > 585)
				p4_mux1.second.x = p4_mux1.second.x - 1.5;

		}
		if (p4_mux1.second.y == 108.5 && p4_mux2.second.y < 330)
			p4_mux2.second.y++;
		if (p4_mux2.second.y > 327 && p4_mux2.second.x < 630)
			p4_mux2.second.x++;
		if (p4_mux1.second.y > 108 && p4_mux1.second.x < 630)
			p4_mux1.second.x++;
		if (p4_mux1.second.y < 90 && p4_p5mid.second.x < 1100)
			p4_p5mid.second.x = p4_p5mid.second.x + 1.5;
		if (p4_p5up.second.x < 1100)
			p4_p5up.second.x = p4_p5up.second.x + 1;
		if (p4_p5up.second.x > 880 && p4_fwdctrl.second.y > 20)
			p4_fwdctrl.second.y = p4_fwdctrl.second.y - 1;
		if (p4_fwdctrl.second.x > 770 && p4_fwdctrl.second.y < 23)
			p4_fwdctrl.second.x = p4_fwdctrl.second.x - 1;
		if (p4_p5up.second.x > 960 && p4_mem1.second.y > 285)
			p4_mem1.second.y = p4_mem1.second.y - 1;
		if (p4_p5up.second.x > 980 && p4_mem2.second.y > 285)
			p4_mem2.second.y = p4_mem2.second.y - 1;
		if (p4_mux1.second.y < 118 && p4_mux1.second.x == 584.5)
			p4_mux1.second.y++;
	}

};
class Stage5
{
public:
	my_pair<string, Coor> ctrl_mux;
	my_pair<string, Coor> mux_mux;
	my_pair<string, Coor> ctrl_fwd;
	my_pair<string, Coor> mem_mux;
	my_pair<string, Coor> alu_mux;
	my_pair<string, Coor> data_fwd;
	my_pair<string, Coor> mux_mux2;
	my_pair<string, Coor> mux_reg;
	int token;
	Stage5()
	{
		ctrl_mux.second.x = 1130;
		ctrl_mux.second.y = 419;
		ctrl_fwd.second.x = 1131;
		ctrl_fwd.second.y = 419;
		mem_mux.second.x = 1130;
		mem_mux.second.y = 207;
		alu_mux.second.x = 1130;
		alu_mux.second.y = 83;
		data_fwd.second.x = 1130;
		data_fwd.second.y = 65;
		mux_mux.second.x = 1181;
		mux_mux.second.y = 199;
		mux_reg.second.x = 580;
		mux_reg.second.y = 8;
		mux_mux2.second.x = 580;
		mux_mux2.second.y = 8;
		token = 0;

	}
	void Draw()
	{
		DrawRoundRect(ctrl_mux.second.x, ctrl_mux.second.y, 18, 12,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(mux_mux.second.x, mux_mux.second.y, 18, 12,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(ctrl_fwd.second.x, ctrl_fwd.second.y, 18, 12,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(mem_mux.second.x, mem_mux.second.y, 18, 12,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(alu_mux.second.x, alu_mux.second.y, 18, 12,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(data_fwd.second.x, data_fwd.second.y, 18, 12,
				colors[LIGHT_BLUE], 5);
		if (token == 1)
		{
			DrawRoundRect(mux_mux2.second.x, mux_mux2.second.y, 18, 12,
					colors[LIGHT_BLUE], 5);
			DrawRoundRect(mux_reg.second.x, mux_reg.second.y, 18, 12,
					colors[LIGHT_BLUE], 5);
		}
	}
	void move()
	{
		if (mem_mux.second.x < 1145)
			mem_mux.second.x = mem_mux.second.x + 0.2;
		if (alu_mux.second.x > 1145 && alu_mux.second.y == 207)
			alu_mux.second.x++;
		if (alu_mux.second.x < 1138 && alu_mux.second.y < 180)
			alu_mux.second.y++;
		if (alu_mux.second.x < 1150 && alu_mux.second.y > 178)
			alu_mux.second.x++;
		if (data_fwd.second.x < 1140 && data_fwd.second.y > 20)
			data_fwd.second.x++;
		if (data_fwd.second.y > 10)
			data_fwd.second.y--;
		if (data_fwd.second.x > 760 && data_fwd.second.y < 15)
			data_fwd.second.x--;
		if (ctrl_mux.second.x < 1160 && ctrl_mux.second.y > 400)
			ctrl_mux.second.x++;
		if (ctrl_mux.second.y > 235 && ctrl_mux.second.x > 1155)
			ctrl_mux.second.y--;
		if (ctrl_mux.second.x > 1140 && ctrl_fwd.second.y > 12)
			ctrl_fwd.second.y = ctrl_fwd.second.y - 2;
		if (ctrl_fwd.second.x > 760 && ctrl_fwd.second.y < 15)
			ctrl_fwd.second.x = ctrl_fwd.second.x - 2;
		if (mux_mux.second.x < 1190 && mux_mux.second.y > 190)
			mux_mux.second.x++;
		if (mux_mux.second.x > 1188 && mux_mux.second.y > 6)
			mux_mux.second.y = mux_mux.second.y - 2;

		if (mux_mux.second.x > 580 && mux_mux.second.y < 8)
			mux_mux.second.x = mux_mux.second.x - 2;

		if (mux_mux.second.x > 580 && mux_mux.second.x < 585)
			token = 1;
		if (mux_mux.second.x < 585 && mux_mux.second.y < 150)
			mux_mux.second.y = mux_mux.second.y + 2;
		if (mux_mux.second.x < 630 && mux_mux.second.y == 151)
			mux_mux.second.x = mux_mux.second.x + 2;

		if (token == 1 && mux_mux2.second.x < 585 && mux_mux2.second.y < 370)
			mux_mux2.second.y = mux_mux2.second.y + 2;
		if (token == 1 && mux_mux2.second.x < 630 && mux_mux2.second.y > 366)
			mux_mux2.second.x = mux_mux2.second.x + 2;

		if (token == 1 && mux_reg.second.x > 290 && mux_reg.second.y < 10)
			mux_reg.second.x = mux_reg.second.x - 2;
		if (token == 1 && mux_reg.second.x < 295 && mux_reg.second.y < 137)
			mux_reg.second.y = mux_reg.second.y + 2;
		if (token == 1 && mux_reg.second.x < 335 && mux_reg.second.y > 133)
			mux_reg.second.x = mux_reg.second.x + 2;
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
	void place_instructions_s1()
	{
		counter++;
		counter %= 300;
		switch(counter )
		{
		case 1:
			Sta1.pc_mem.first = to_string(p.index);
			Sta1._4_alu.first="4";
			Sta1.pc_alu.first=to_string(p.index);
			break;
		case 130:
			Sta1.mem_p1.first = instructoins[p.index];
			break;
		case 190:
			Sta1.alu_mux.first=to_string(p.index+4);
			Sta1.alu_p1.first=to_string(p.index+4);
			break;
		}
	}
	void draw_board()
	{
		if (started)
		{
			place_instructions_s1();
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
		Sta1.Draw();
		Sta2.Draw();
		Sta4.Draw();
		Sta5.Draw();
		if (started)
		{
			Sta1.move();
			Sta2.move();
			Sta4.move();
			Sta5.move();
		}
	}
};
#endif
