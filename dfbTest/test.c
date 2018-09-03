/*************************************************************************
	> File Name: draw_line.c
	> Author: 徐进
	> Mail: xujinchn@163.com 
	> Created Time: Tue 14 Aug 2018 10:27:03 PM CST
 ************************************************************************/

#include<stdio.h>
#include <unistd.h>
#include "directfb.h"

static IDirectFB *dfb = NULL;

static IDirectFBSurface *primary = NULL;

static int screen_width = 0;
static int screen_height = 0;

#define DRAW_LINE

#define DFBCHECK(x...) \
{ \
	DFBResult err = x; \
	if (err != DFB_OK) \
	{ \
		fprintf(stderr, "%s<%d>:\n\t", __FILE__, __LINE__); \
		DirectFBErrorFatal(#x, err); \
	} \
}

int main(int argc, char *argv[])
{
	DFBSurfaceDescription dsc;

	DirectFBInit(&argc, &argv);

	DirectFBCreate(&dfb);

	dsc.flags = DSDESC_CAPS;
	dsc.caps = DSCAPS_PRIMARY | DSCAPS_FLIPPING;

	dfb->CreateSurface(dfb, &dsc, &primary);

	primary->GetSize(primary, &screen_width, &screen_height);

	primary->FillRectangle(primary, 0, 0, screen_width, screen_height);

#ifdef DRAW_LINE
	primary->SetColor(primary, 0x80, 0xff, 0xff, 0xff);

	primary->DrawLine(primary, 0, screen_height/2, screen_width - 1,
			screen_height/2);

	primary->Flip(primary, NULL, 0);
#endif

#ifdef DRAW_FONT
	DFBFontDescription font_dsc; // 创建字体font时需要的描述符
	IDirectFBFont *font = NULL; // 字体
	primary->SetColor(primary, 0x80, 0x80, 0xff, 0xff); //设置画笔颜色
	primary->DrawRectangle(primary, 0, 0, screen_width/3, screen_height/3);

	font_dsc.flags = DFDESC_HEIGHT;
	font_dsc.height = 50;
	dfb->CreateFont(dfb, "");	

	primary->SetFont(primary, font);
#endif

	sleep(5);

	primary->Release(primary);

	dfb->Release(dfb);

	return 0;
}
