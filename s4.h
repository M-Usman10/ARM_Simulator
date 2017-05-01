#ifndef S4_H
#define S4_H
#include "Basic_Objects.h"
class Stage4
{
public:
	int counter;
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
		counter = 0;
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
		counter++;
		if (p4_mem.second.x < 950)
			p4_mem.second.x = p4_mem.second.x + 2;
		if (counter > 220 && mem_conv.second.x < 1050)
		{

			mem_conv.second.x = mem_conv.second.x + 0.2;
		}
		else if (counter > 240 && conv_p5.second.x < 1102)
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
			p4_fwddata.second.y = p4_fwddata.second.y - 4;
		if (p4_fwddata.second.y < 23 && p4_fwddata.second.x > 765)
			p4_fwddata.second.x = p4_fwddata.second.x - 4;
		if (p4_mem.second.x > 920)
		{
			if (p4_mux1.second.y > 4 && p4_mux1.second.x == 925)
				p4_mux1.second.y = p4_mux1.second.y - 4.5;
			if (p4_mux1.second.y < 6 && p4_mux1.second.x > 585)
				p4_mux1.second.x = p4_mux1.second.x - 4.5;

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
			p4_fwdctrl.second.y = p4_fwdctrl.second.y - 4;
		if (p4_fwdctrl.second.x > 770 && p4_fwdctrl.second.y < 23)
			p4_fwdctrl.second.x = p4_fwdctrl.second.x - 4;
		if (p4_p5up.second.x > 960 && p4_mem1.second.y > 285)
			p4_mem1.second.y = p4_mem1.second.y - 1;
		if (p4_p5up.second.x > 980 && p4_mem2.second.y > 285)
			p4_mem2.second.y = p4_mem2.second.y - 1;
		if (p4_mux1.second.y < 118 && p4_mux1.second.x == 584.5)
			p4_mux1.second.y++;
	}

};

#endif
