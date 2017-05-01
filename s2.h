#ifndef S2_H
#define S2_H
#include "Basic_Objects.h"
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
	void ReInit()
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

		p1_alu.first = "";
		sh_alu.first = "";
		alu_pc_mux.first = "";
		p1_p2.first = "";
		p1_ext1.first = "";
		p1_ext2.first = "";
		ext1_sh.first = "";
		ext2_p2.first = "";
		reg_p2_s1.first = "";
		reg_pc.first = "";
		reg_p2_s2.first = "";
		p1_ctrl.first = "";
		ctrl_mux.first = "";
		_0_mux.first = "";
		mux_p2.first = "";
		ctrl_p1.first = "";
		p1.first = "";
		p1_mux.first = "";
		p1_mux2.first = "";
		p1_ext.first = "";
		p1_reg.first = "";

	}
	void Draw()
	{
		DrawRoundRect(p1_alu.second.x, p1_alu.second.y,
				p1_alu.first.length() *7, 16, colors[LIGHT_BLUE], 5);
		DrawRoundRect(sh_alu.second.x, sh_alu.second.y,
				sh_alu.first.length() *7, 16, colors[LIGHT_BLUE], 5);
		DrawRoundRect(alu_pc_mux.second.x, alu_pc_mux.second.y,
				alu_pc_mux.first.length() *7, 16, colors[LIGHT_BLUE], 5);

		DrawRoundRect(p1_p2.second.x, p1_p2.second.y, p1_p2.first.length() *7,
				16, colors[LIGHT_BLUE], 5);

		DrawRoundRect(p1_ext1.second.x, p1_ext1.second.y,
				p1_ext1.first.length() *7, 16, colors[LIGHT_BLUE], 5);
		DrawRoundRect(p1_ext2.second.x, p1_ext2.second.y,
				p1_ext2.first.length() *7, 16, colors[LIGHT_BLUE], 5);
		DrawRoundRect(ext1_sh.second.x, ext1_sh.second.y,
				ext1_sh.first.length() *7, 16, colors[LIGHT_BLUE], 5);
		DrawRoundRect(ext2_p2.second.x, ext2_p2.second.y,
				ext2_p2.first.length() *7, 16, colors[LIGHT_BLUE], 5);

		DrawRoundRect(reg_p2_s1.second.x, reg_p2_s1.second.y,
				reg_p2_s1.first.length() *7, 16, colors[LIGHT_BLUE], 5);

		DrawRoundRect(reg_pc.second.x, reg_pc.second.y,
				reg_pc.first.length() *7, 16, colors[LIGHT_BLUE], 5);

		DrawRoundRect(reg_p2_s2.second.x, reg_p2_s2.second.y,
				reg_p2_s2.first.length() *7, 16, colors[LIGHT_BLUE], 5);
		DrawRoundRect(p1_ctrl.second.x, p1_ctrl.second.y,
				p1_ctrl.first.length() *7, 16, colors[LIGHT_BLUE], 5);

		DrawRoundRect(ctrl_mux.second.x, ctrl_mux.second.y,
				ctrl_mux.first.length() *7, 16, colors[LIGHT_BLUE], 5);
		DrawRoundRect(_0_mux.second.x, _0_mux.second.y,
				_0_mux.first.length() *7, 16, colors[LIGHT_BLUE], 5);

		DrawRoundRect(mux_p2.second.x, mux_p2.second.y,
				mux_p2.first.length() *7, 16, colors[LIGHT_BLUE], 5);
		DrawRoundRect(ctrl_p1.second.x, ctrl_p1.second.y,
				ctrl_p1.first.length() *7, 16, colors[LIGHT_BLUE], 5);
		DrawRoundRect(p1.second.x, p1.second.y, p1.first.length() *7, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(p1_mux.second.x, p1_mux.second.y,
				p1_mux.first.length() * 7, 16, colors[LIGHT_BLUE], 5);
		DrawRoundRect(p1_mux2.second.x, p1_mux2.second.y,
				p1_mux2.first.length() * 7, 16, colors[LIGHT_BLUE], 5);
		DrawRoundRect(p1_ext.second.x, p1_ext.second.y,
				p1_ext.first.length() * 6, 16, colors[LIGHT_BLUE], 5);
		DrawRoundRect(p1_reg.second.x, p1_reg.second.y,
				p1_reg.first.length() * 7, 16, colors[LIGHT_BLUE], 5);

		DrawStringsmall(p1_alu.second.x+2, p1_alu.second.y+2, p1_alu.first,
				colors[BLACK]);
		DrawStringsmall(sh_alu.second.x+2, sh_alu.second.y+2, sh_alu.first,
				colors[BLACK]);
		DrawStringsmall(alu_pc_mux.second.x+2, alu_pc_mux.second.y+2, alu_pc_mux.first,
				colors[BLACK]);
		DrawStringsmall(p1_p2.second.x+2, p1_p2.second.y+2, p1_p2.first,
				colors[BLACK]);
		DrawStringsmall(p1_ext1.second.x+2, p1_ext1.second.y+2, p1_ext1.first,
				colors[BLACK]);
		DrawStringsmall(p1_ext2.second.x+2, p1_ext2.second.y+2, p1_ext2.first,
				colors[BLACK]);
		DrawStringsmall(ext1_sh.second.x+2, ext1_sh.second.y+2, ext1_sh.first,
				colors[BLACK]);
		DrawStringsmall(ext2_p2.second.x+2, ext2_p2.second.y+2, ext2_p2.first,
				colors[BLACK]);

		DrawStringsmall(reg_p2_s1.second.x+2, reg_p2_s1.second.y+2, reg_p2_s1.first,
				colors[BLACK]);

		DrawStringsmall(reg_pc.second.x+2, reg_pc.second.y+2, reg_pc.first,
				colors[BLACK]);

		DrawStringsmall(reg_p2_s2.second.x+2, reg_p2_s2.second.y+2, reg_p2_s2.first,
				colors[BLACK]);
		DrawStringsmall(p1_ctrl.second.x+2, p1_ctrl.second.y+2, p1_ctrl.first,
				colors[BLACK]);

		DrawStringsmall(ctrl_mux.second.x+2, ctrl_mux.second.y+2, ctrl_mux.first,
				colors[BLACK]);
		DrawStringsmall(_0_mux.second.x+2, _0_mux.second.y+2, _0_mux.first,
				colors[BLACK]);

		DrawStringsmall(mux_p2.second.x+2, mux_p2.second.y+2, mux_p2.first,
				colors[BLACK]);
		DrawStringsmall(ctrl_p1.second.x+2, ctrl_p1.second.y+2, ctrl_p1.first,
				colors[BLACK]);
		DrawStringsmall(p1.second.x+2, p1.second.y+2, p1.first, colors[BLACK]);
		DrawStringsmall(p1_mux.second.x+2, p1_mux.second.y+2, p1_mux.first,
				colors[BLACK]);
		DrawStringsmall(p1_mux2.second.x+2, p1_mux2.second.y+2, p1_mux2.first,
				colors[BLACK]);
		DrawStringsmall(p1_ext.second.x+2, p1_ext.second.y+2, p1_ext.first,
				colors[BLACK]);
		DrawStringsmall(p1_reg.second.x+2, p1_reg.second.y+2, p1_reg.first,
				colors[BLACK]);
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
#endif
