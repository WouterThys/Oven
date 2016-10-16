/* 
 * File:   panda.h
 * Author: wouter
 *
 * Created on 20 mei 2015, 18:22
 */

#ifndef GLCD_BITMAPS_H
#define	GLCD_BITMAPS_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#define BMP_TINKER  0x00    
#define BMP_EMMA    0x01    
#define BMP_PANDA   0x02    
    
//0x45, 0x00, 0x40, 0x00,
const unsigned char SmallPanda [] = {
0x45, 0x40, 
0xC0, 0xF0, 0xF8, 0xFC, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0x01, 0x39, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03,
0x33, 0x71, 0x39, 0x39, 0x01, 0x03, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x1F, 0x1F, 0x0F, 0x0F, 0x0F,
0x0F, 0x0F, 0x1F, 0x1F, 0x3F, 0xFF, 0xFF, 0x07, 0x01, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00,
0x00, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x01, 0x07, 0x1F, 0x3F,
0x7F, 0x7F, 0xFF, 0x7F, 0x7F, 0x3F, 0x1F, 0x03, 0x81, 0x80, 0x80, 0xE0, 0xE0, 0x80, 0x80, 0x81,
0x03, 0x0F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE0,
0x80, 0x00, 0x38, 0x7E, 0xFE, 0xF8, 0xF8, 0xFC, 0xFC, 0xF8, 0xF1, 0xF1, 0xF0, 0xF8, 0xF0, 0xE0,
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x81, 0x81, 0x80, 0xC0, 0xE0, 0xF0, 0xF0, 0xFC, 0xFF, 0xFF,
0xFF, 0xFE, 0xFE, 0xFF, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0x7F,
0x7F, 0x3F, 0x1F, 0x07, 0x80, 0xF0, 0xFC, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xFC, 0xF8, 0xE1, 0xE3, 0xC3, 0xC7, 0x8F, 0x8F,
0x1F, 0x1F, 0x3F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x3F, 0x3F, 0x3F, 0x7F, 0xFF, 0x3F, 0x1F, 0x0F, 0x87, 0xC3, 0xE3,
0xF1, 0xF1, 0xF9, 0xF8, 0xF8, 0xFC, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0x38, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x03, 0x01,
0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x0F, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x00, 0x80, 0x80, 0x80, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x03, 0x01, 0x00,
0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xFE, 0xFC, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0xE0, 0xE0, 0xF0, 0xF8, 0xF8, 0xFC, 0xFF, 0xFF, 0xFF, 0xC0, 0x00, 0x3F,
0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0x03, 0x0F, 0x1F, 0x3F, 0x7F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xE0, 0xC0, 0x87, 0x8F, 0x9F, 0x9F, 0x9F, 0x1F, 0x9F, 0x9F, 0x88, 0x80, 0xC0,
0xFE, 0xFE, 0xFE, 0xFE, 0xFF, 0xFF, 0xFF, 0xFC, 0xF0, 0xF0, 0xF3, 0xE3, 0xC3, 0xC7, 0xC7, 0xCF,
0xC7, 0xC7, 0xC7, 0xC2, 0xE0, 0xE0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
};

const unsigned char emma [] = {
0x45, 0x40, 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xE0, 0xE0, 0xF0, 0xF8, 0xF8, 0x7C,
0x3C, 0xFA, 0xFE, 0xFE, 0xFB, 0xFF, 0xFE, 0xFE, 0xFA, 0xFE, 0xFC, 0xBC, 0xBC, 0xF8, 0xF8, 0xF0,
0xE0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xFC, 0xFF, 0xFF, 0xFF,
0xFF, 0xF7, 0xFF, 0xFF, 0xEE, 0x77, 0x37, 0x3B, 0x0D, 0x07, 0x03, 0x11, 0x03, 0x05, 0x81, 0x05,
0x50, 0x09, 0xA7, 0x7F, 0xFE, 0xFF, 0xFF, 0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x1F, 0xFF, 0xFF, 0xFF, 0x7F, 0x9F, 0x1F, 0x2F, 0x3E, 0x0E, 0x1E, 0xA8, 0x08, 0x04, 0x10,
0x44, 0x1E, 0x07, 0x2E, 0x1E, 0x8E, 0x0E, 0x41, 0x96, 0x91, 0xAB, 0x7F, 0x3F, 0x4F, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x0F, 0x7F, 0x40, 0x06, 0x08, 0x60, 0x8A, 0x00,
0x95, 0x30, 0x76, 0x36, 0x7A, 0x32, 0x38, 0x10, 0x14, 0x88, 0x09, 0xC0, 0x9A, 0xE6, 0x40, 0x80,
0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x66,
0x10, 0xCC, 0x04, 0x13, 0x13, 0x0E, 0x16, 0x58, 0x58, 0xAE, 0x34, 0x5C, 0xBC, 0x45, 0x5E, 0x9B,
0x58, 0x07, 0x5F, 0x3F, 0x24, 0x00, 0x44, 0x10, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xA0, 0xFD, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC,
0xF0, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x02, 0x00, 0x04, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
0x02, 0x00, 0x11, 0x02, 0x00, 0x09, 0x00, 0x80, 0x01, 0x00, 0x08, 0x01, 0xA0, 0xFC, 0xFE, 0xFE,
0xFC, 0xFC, 0xF8, 0xF8, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x20, 0x00, 0x54, 0x02, 0x04, 0x80, 0x00, 0x00, 0x00, 0xC0, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0xC0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC0, 0xF8,
0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xA0, 0x00, 0x40, 0x08, 0x20,
0xA2, 0x04, 0x00, 0x00, 0x00, 0xA5, 0x00, 0x48, 0x11, 0x04, 0x00, 0x80, 0x14, 0x80, 0xE9, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE,
0xE0, 0x80, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0xC0,
0xE0, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xBC, 0x41, 0x18, 0xC2, 0x15, 0x01, 0x00,
};


const unsigned char tinkerbell [] = {
0x3A, 0x40,    
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x3C, 0x7D, 0x7F, 0x7F, 0xFC, 0xFE, 0xF2, 0xF8, 0xF0,
0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0xFC, 0xFA, 0x60, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
0xC0, 0xE0, 0x70, 0x18, 0x0E, 0x07, 0x13, 0x33, 0xEC, 0xE0, 0x80, 0x80, 0x30, 0xF0, 0xC0, 0x80,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x01, 0x00, 0x07, 0x1F, 0x1F, 0x3F,
0x6F, 0x3E, 0x00, 0x00, 0x01, 0x3F, 0xFE, 0xFC, 0xFF, 0xFF, 0xFE, 0xFC, 0x7E, 0x3E, 0x60, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x1C, 0x38, 0xF0, 0xFC, 0xF4, 0xF0, 0xF0,
0xE1, 0xE1, 0x81, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x06, 0xC7, 0xE7, 0xEF, 0xFF, 0xFF, 0xFF, 0xDF, 0x8F, 0xFF, 0xFE, 0xFE,
0xF8, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x70, 0xF8, 0x00, 0xF8, 0xFC, 0xF8, 0xF0,
0xF8, 0xF1, 0xFB, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF, 0xE0, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0xBF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0x80, 0x00, 0x01, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
#ifdef	__cplusplus
}
#endif

#endif	/* GLCD_BITMAPS_H */

