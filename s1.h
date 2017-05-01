#ifndef S1_H
#define S1_H
#include "Basic_Objects.h"
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
	void ReInit()
	{

		pc_mem.first = "";
		pc_mem.first = "";
		mem_p1.first = "";
		mem_p1.first = "";
		pc_alu.first = "";
		pc_alu.first = "";
		_4_alu.first = "";
		_4_alu.first = "";
		alu_p1.first = "";
		alu_p1.first = "";
		alu_mux.first = "";
		alu_mux.first = "";

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
		DrawRoundRect(pc_mem.second.x, pc_mem.second.y,
				pc_mem.first.length() * 13, 23, colors[LIGHT_BLUE], 5);
		DrawRoundRect(mem_p1.second.x, mem_p1.second.y,
				mem_p1.first.length() * 5, 23, colors[LIGHT_BLUE], 5);
		DrawRoundRect(pc_alu.second.x, pc_alu.second.y,
				pc_alu.first.length() * 13, 23, colors[LIGHT_BLUE], 5);
		DrawRoundRect(_4_alu.second.x, _4_alu.second.y,
				_4_alu.first.length() * 13, 23, colors[LIGHT_BLUE], 5);
		DrawRoundRect(alu_p1.second.x, alu_p1.second.y,
				alu_p1.first.length() * 13, 23, colors[LIGHT_BLUE], 5);
		DrawRoundRect(alu_mux.second.x, alu_mux.second.y,
				alu_mux.first.length() * 13, 23, colors[LIGHT_BLUE], 5);

		DrawString(pc_mem.second.x + 1.5, pc_mem.second.y + 4,
				pc_mem.first, colors[BLACK]);
		DrawStringsmall(mem_p1.second.x + 1.5, mem_p1.second.y + 4,
				mem_p1.first, colors[BLACK]);
		DrawString(pc_alu.second.x + 1.5, pc_alu.second.y + 4,
				pc_alu.first, colors[BLACK]);
		DrawString(_4_alu.second.x + 1.5, _4_alu.second.y + 4,
				_4_alu.first, colors[BLACK]);
		DrawString(alu_p1.second.x + 1.5, alu_p1.second.y + 4,
				alu_p1.first, colors[BLACK]);
		DrawString(alu_mux.second.x + 1.5, alu_mux.second.y + 4,
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
#endif