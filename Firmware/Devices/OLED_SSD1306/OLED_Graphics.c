#include "OLED_Graphics.h"





void OLED_Draw_Line(int x1, int x2, int y1, int y2, int thickness)
{
	int page_start, page_end;
if(x1 <= 7){  page_start = 0;  }
else if(x1 >= 8  && x1 <= 15){  page_start = 1;  }
else if(x1 >= 16 && x1 <= 23){  page_start = 2;  }
else if(x1 >= 24 && x1 <= 31){  page_start = 3;  }
else if(x1 >= 32 && x1 <= 39){  page_start = 4;  }
else if(x1 >= 40 && x1 <= 47){  page_start = 5;  }
else if(x1 >= 48 && x1 <= 55){  page_start = 6;  }
else if(x1 >= 56 && x1 <= 63){  page_start = 7;  }
else{
break;
}

if(x2 <= 7){  page_end = 0;  }
else if(x2 >= 8  && x2 <= 15){  page_end = 1;  }
else if(x2 >= 16 && x2 <= 23){  page_end = 2;  }
else if(x2 >= 24 && x2 <= 31){  page_end = 3;  }
else if(x2 >= 32 && x2 <= 39){  page_end = 4;  }
else if(x2 >= 40 && x2 <= 47){  page_end = 5;  }
else if(x2 >= 48 && x2 <= 55){  page_end = 6;  }
else if(x2 >= 56 && x2 <= 63){  page_end = 7;  }
else{
break;
}

OLED_Set_Pixel_Address(y1,y2,page_start,page_start);







}

void OLED_Draw_Rectangle(int x1, int x2, int x3, int x4, int y1, int y2, int y3, int y4, int thickess, int fill_or_nofill)
{

}

void OLED_Draw_Circle(int x1, int y1, int radius, int thickness, int fill_or_nofill)
{

}
