#ifndef S5_H
#define S5_H
#include "Basic_Objects.h"
class Stage5
{
public:
	int counter;
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
		counter = 0;
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
		counter++;
		if (mem_mux.second.x < 1145)
			mem_mux.second.x = mem_mux.second.x + 0.2;
		if (alu_mux.second.x > 1145 && alu_mux.second.y == 207)
			alu_mux.second.x++;
		if (alu_mux.second.x < 1138 && alu_mux.second.y < 180)
			alu_mux.second.y++;
		if (alu_mux.second.x < 1150 && alu_mux.second.y > 178)
			alu_mux.second.x++;
		if (data_fwd.second.x < 1140 && data_fwd.second.y > 20)
			data_fwd.second.x += 2;
		if (data_fwd.second.y > 10)
			data_fwd.second.y -= 2;
		if (data_fwd.second.x > 760 && data_fwd.second.y < 15)
			data_fwd.second.x -= 2;
		if (ctrl_mux.second.x < 1160 && ctrl_mux.second.y > 400)
			ctrl_mux.second.x += 3;
		if (ctrl_mux.second.y > 235 && ctrl_mux.second.x > 1155)
			ctrl_mux.second.y -= 3;
		if (ctrl_mux.second.x > 1140 && ctrl_fwd.second.y > 12)
			ctrl_fwd.second.y = ctrl_fwd.second.y - 2;
		if (ctrl_fwd.second.x > 760 && ctrl_fwd.second.y < 15)
			ctrl_fwd.second.x = ctrl_fwd.second.x - 2;
		if (counter > 80 && mux_mux.second.x < 1190 && mux_mux.second.y > 190)
			mux_mux.second.x += 4;
		if (mux_mux.second.x > 1188 && mux_mux.second.y > 6)
			mux_mux.second.y = mux_mux.second.y - 5;

		if (mux_mux.second.x > 580 && mux_mux.second.y < 8)
			mux_mux.second.x = mux_mux.second.x - 5;

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

#endif
