#ifndef S3_H
#define S3_H
#include "Basic_Objects.h"
class Stage3
{
public:
	int counter;
	my_pair<string, Coor> p3_p4;
	my_pair<string, Coor> mux1_ctrl;
	my_pair<string, Coor> mux2_ctrl;
	my_pair<string, Coor> mux3_ctrl;
	my_pair<string, Coor> mux4_data;
	my_pair<string, Coor> mux3_data;
	my_pair<string, Coor> mux3_data2;
	my_pair<string, Coor> mux5_data;
	my_pair<string, Coor> mux1_data;
	my_pair<string, Coor> mux1_data2;
	my_pair<string, Coor> p3_fwd;
	my_pair<string, Coor> p3_fwd2;
	my_pair<string, Coor> fwd_mux5;
	my_pair<string, Coor> fwd_mux4;
	my_pair<string, Coor> mux1_p4;
	my_pair<string, Coor> mux5_p4;
	my_pair<string, Coor> mux5_mux3;
	my_pair<string, Coor> mux3_alu;
	my_pair<string, Coor> mux2_alu;
	my_pair<string, Coor> alu_p4;
	my_pair<string, Coor> mux4_mux2;
	my_pair<string, Coor> p3_selector1;
	my_pair<string, Coor> p3_selector2;
	my_pair<string, Coor> p3_selector3;
	my_pair<string, Coor> alu_op;
	my_pair<string, Coor> alu_selector4;
	my_pair<string, Coor> flag;
	my_pair<string, Coor> selector_mux;
	Stage3()
	{
		counter = 0;
		p3_p4.second.x = 550;
		p3_p4.second.y = 455;
		mux1_ctrl.second.x = 570;
		mux1_ctrl.second.y = 455;
		mux2_ctrl.second.x = 660;
		mux2_ctrl.second.y = 455;
		mux3_ctrl.second.x = 702;
		mux3_ctrl.second.y = 455;
		mux4_data.second.x = 550;
		mux4_data.second.y = 413;
		mux3_data.second.x = 550;
		mux3_data.second.y = 363;
		mux3_data2.second.x = 550;
		mux3_data2.second.y = 196;
		mux5_data.second.x = 550;
		mux5_data.second.y = 160;

		mux1_data.second.x = 550;
		mux1_data.second.y = 127;
		mux1_data2.second.x = 550;
		mux1_data2.second.y = 105;

		p3_fwd.second.x = 550;
		p3_fwd.second.y = 37;
		p3_fwd2.second.x = 550;
		p3_fwd2.second.y = 45;
		fwd_mux5.second.x = 662;
		fwd_mux5.second.y = 27;
		fwd_mux4.second.x = 662;
		fwd_mux4.second.y = 16;
		mux1_p4.second.x = 587;
		mux1_p4.second.y = 90;
		mux5_p4.second.x = 655;
		mux5_p4.second.y = 124;
		mux5_mux3.second.x = 675;
		mux5_mux3.second.y = 126;
		mux3_alu.second.x = 720;
		mux3_alu.second.y = 200;
		mux2_alu.second.x = 720;
		mux2_alu.second.y = 300;
		alu_p4.second.x = 800;
		alu_p4.second.y = 245;
		mux4_mux2.second.x = 655;
		mux4_mux2.second.y = 327;
		p3_selector1.second.x = 720;
		p3_selector1.second.y = 460;
		p3_selector2.second.x = 735;
		p3_selector2.second.y = 460;
		p3_selector3.second.x = 750;
		p3_selector3.second.y = 460;
		alu_selector4.second.x = 765;
		alu_selector4.second.y = 294;
		flag.second.x = 773;
		flag.second.y = 500;
		alu_op.second.x = 745;
		alu_op.second.y = 460;
		selector_mux.second.x = 754;
		selector_mux.second.y = 630;
	}
	void Draw()
	{
		DrawRoundRect(p3_p4.second.x, p3_p4.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(mux1_ctrl.second.x, mux1_ctrl.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(mux2_ctrl.second.x, mux2_ctrl.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(mux3_ctrl.second.x, mux3_ctrl.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(mux4_data.second.x, mux4_data.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(mux3_data.second.x, mux3_data.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(mux3_data2.second.x, mux3_data2.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(mux5_data.second.x, mux5_data.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(mux1_data.second.x, mux1_data.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(p3_fwd.second.x, p3_fwd.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(p3_fwd2.second.x, p3_fwd2.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(fwd_mux5.second.x, fwd_mux5.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(fwd_mux4.second.x, fwd_mux4.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(mux1_p4.second.x, mux1_p4.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(mux5_p4.second.x, mux5_p4.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(mux5_mux3.second.x, mux5_mux3.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(mux3_alu.second.x, mux3_alu.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(mux2_alu.second.x, mux2_alu.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(alu_p4.second.x, alu_p4.second.y, 22, 16,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(mux4_mux2.second.x, mux4_mux2.second.y, 16, 8,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(p3_selector1.second.x, p3_selector1.second.y, 16, 8,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(p3_selector2.second.x, p3_selector2.second.y, 16, 8,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(p3_selector3.second.x, p3_selector3.second.y, 16, 8,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(alu_op.second.x, alu_op.second.y, 16, 8,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(alu_selector4.second.x, alu_selector4.second.y, 16, 8,
				colors[LIGHT_BLUE], 5);
		DrawRoundRect(flag.second.x, flag.second.y, 16, 8, colors[LIGHT_BLUE],
				5);
		DrawRoundRect(selector_mux.second.x, selector_mux.second.y, 16, 8,
				colors[LIGHT_BLUE], 5);
	}
	void move()
	{
		counter++;
		if (p3_p4.second.x < 850)
			p3_p4.second.x += 2;
		if (p3_p4.second.x > 720 && p3_selector1.second.y < 580)
			p3_selector1.second.y += 2;
		if (p3_p4.second.x > 735 && p3_selector2.second.y < 565)
			p3_selector2.second.y += 2;
		if (p3_p4.second.x > 750 && p3_selector3.second.y < 570)
			p3_selector3.second.y += 2;
		if (p3_p4.second.x > 745 && alu_op.second.y > 300)
			alu_op.second.y -= 2;
		if (p3_p4.second.x > 560 && mux1_ctrl.second.y > 151)
			mux1_ctrl.second.y -= 2;
		if (p3_p4.second.x > 660 && mux2_ctrl.second.y > 260)
			mux2_ctrl.second.y -= 2;
		if (mux2_ctrl.second.x < 697 && mux2_ctrl.second.y < 262)
			mux2_ctrl.second.x += 2;
		if (p3_p4.second.x > 706 && mux3_ctrl.second.y > 355)
			mux3_ctrl.second.y -= 2;

		if (mux4_data.second.x < 632)
			mux4_data.second.x += 2;
		if (mux3_data.second.x < 573)
			mux3_data.second.x += 2;
		if (mux3_data.second.y > 230 && mux3_data.second.x > 570)
			mux3_data.second.y -= 2;
		if (mux3_data.second.x < 691 && mux3_data.second.y < 235)
			mux3_data.second.x += 2;

		if (mux3_data2.second.x < 609)
			mux3_data2.second.x += 2;
		if (mux3_data2.second.y < 220 && mux3_data2.second.x > 605
				&& mux3_data2.second.x < 630)
			mux3_data2.second.y += 2;
		if (mux3_data2.second.x < 665 && mux3_data2.second.y > 218)
			mux3_data2.second.x += 2;
		if (mux3_data2.second.x > 660 && mux3_data2.second.y > 193)
			mux3_data2.second.y -= 2;
		if (mux3_data2.second.x < 691 && mux3_data2.second.x > 660
				&& mux3_data2.second.y < 196)
			mux3_data2.second.x += 2;

		if (mux5_data.second.x < 620)
			mux5_data.second.x += 2;
		if (mux5_data.second.y < 193 && mux5_data.second.x > 618)
			mux5_data.second.y += 2;
		if (mux5_data.second.x < 630 && mux5_data.second.y > 190)
			mux5_data.second.x += 2;

		if (mux1_data.second.x < 565)
			mux1_data.second.x += 2;
		if (mux1_data2.second.x < 565)
			mux1_data2.second.x += 2;

		if (mux1_data2.second.x > 563 && mux1_p4.second.x < 850)
			mux1_p4.second.x += 2;

		if (counter > 340 && mux5_p4.second.x < 850)
			mux5_p4.second.x += 2;

		if (mux5_p4.second.x > 673 && mux5_mux3.second.y < 155)
			mux5_mux3.second.y += 2;
		if (mux5_mux3.second.y > 153 && mux5_mux3.second.x < 693)
			mux5_mux3.second.x += 2;
		if (mux5_mux3.second.x > 691 && mux3_alu.second.x < 743)
			mux3_alu.second.x += 2;

		if (p3_fwd.second.x < 660)
			p3_fwd.second.x += 2;
		if (p3_fwd2.second.x < 660)
			p3_fwd2.second.x += 2;

		if (counter > 440 && mux4_mux2.second.x < 691)
			mux4_mux2.second.x += 2;
		if (mux4_mux2.second.x > 689 && mux2_alu.second.x < 740)
			mux2_alu.second.x += 2;
		if (mux2_alu.second.x > 738 && alu_p4.second.x < 850)
			alu_p4.second.x += 2;
		if (counter > 200 && fwd_mux5.second.x > 635)
			fwd_mux5.second.x -= 2;
		if (fwd_mux5.second.x < 637 && fwd_mux5.second.y < 100)
			fwd_mux5.second.y += 2;
		if (counter > 200 && fwd_mux4.second.x > 600 && fwd_mux4.second.y < 270)
			fwd_mux4.second.x -= 2;

		if (fwd_mux4.second.x < 602 && fwd_mux4.second.y < 288)
			fwd_mux4.second.y += 2;
		if (fwd_mux4.second.x < 655 && fwd_mux4.second.y < 304
				&& fwd_mux4.second.y > 284)
		{
			fwd_mux4.second.x += 2;
			fwd_mux4.second.y += 2;
		}
		if (mux2_alu.second.x > 738 && alu_selector4.second.y < 570)
			alu_selector4.second.y += 4.5;
		if (alu_selector4.second.y > 498 && flag.second.x < 864)
			flag.second.x += 4.5;
		if (flag.second.x > 860 && flag.second.y < 592)
			flag.second.y += 2;
		if (alu_selector4.second.y > 568 && selector_mux.second.y < 660
				&& selector_mux.second.x > 740)
			selector_mux.second.y = selector_mux.second.y + 5;
		if (selector_mux.second.y > 658 && selector_mux.second.x > 52)
			selector_mux.second.x = selector_mux.second.x - 5;
		if (selector_mux.second.y > 250 && selector_mux.second.x < 56)
			selector_mux.second.y = selector_mux.second.y - 5;
	}
};

#endif