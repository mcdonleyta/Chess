#ifndef _DEF_H_
#define _DEF_H_

#define BOARDWIDTH 8
#define BOARDHEIGHT 8

#define SCREENWIDTH 33
#define SCREENHEIGHT 17

#define _OS_MAC_

#ifndef _OS_MAC_
#define BOARDBLANK		((char)176)
#define BOARDTOPWALL	((char)205)
#define BOARDBOTWALL	((char)205) 
#define BOARDLEFTWALL	((char)186) 
#define BOARDRIGHTWALL	((char)186)
#define BOARDCORNERTL	((char)201)
#define BOARDCORNERTR	((char)187)
#define BOARDCORNERBL	((char)200)
#define BOARDCORNERBR	((char)188)
#define BOARDVDIV		((char)186)
#define BOARDHDIV		((char)205)
#else
#define BOARDBLANK		((char)':')
#define BOARDTOPWALL	((char)'=')
#define BOARDBOTWALL	((char)'=') 
#define BOARDLEFTWALL	((char)'|') 
#define BOARDRIGHTWALL	((char)'|')
#define BOARDCORNERTL	((char)'x')
#define BOARDCORNERTR	((char)'x')
#define BOARDCORNERBL	((char)'x')
#define BOARDCORNERBR	((char)'x')
#define BOARDVDIV		((char)'|')
#define BOARDHDIV		((char)'-')
#endif

#define BLACK  1		//Direction of movement as well as player id
#define WHITE  -1

#endif