#include <lvgl.h>

/*******************************************************************************
 * Size: 18 px
 * Bpp: 1
 * Opts: 
 ******************************************************************************/

#ifndef ROBOTO_CONDENSED_BOLD_18
#define ROBOTO_CONDENSED_BOLD_18 1
#endif

#if ROBOTO_CONDENSED_BOLD_18

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t gylph_bitmap[] = {
    /* U+20 " " */
    0x0,

    /* U+21 "!" */
    0xff, 0xff, 0xff, 0xe3, 0xfe,

    /* U+22 "\"" */
    0xde, 0xf7, 0xbd, 0x80,

    /* U+23 "#" */
    0x12, 0x36, 0x36, 0xff, 0xff, 0x36, 0x24, 0x64,
    0xff, 0xff, 0x6c, 0x6c, 0x48,

    /* U+24 "$" */
    0x8, 0x8, 0x3c, 0x7e, 0xe7, 0xe7, 0xe0, 0x78,
    0x3c, 0x1e, 0x7, 0xe7, 0xe7, 0x7f, 0x3e, 0x8,
    0x8,

    /* U+25 "%" */
    0x70, 0x3e, 0xd, 0x93, 0x68, 0xfa, 0x1d, 0x0,
    0xc0, 0x2e, 0x1f, 0xc5, 0xb3, 0x6c, 0x1f, 0x3,
    0x80,

    /* U+26 "&" */
    0x3c, 0x1f, 0x86, 0x61, 0x98, 0x6e, 0xf, 0x3,
    0x81, 0xf6, 0xfd, 0xbb, 0xee, 0x71, 0xfe, 0x3d,
    0x80,

    /* U+27 "'" */
    0xff, 0xc0,

    /* U+28 "(" */
    0x13, 0x36, 0x6c, 0xcc, 0xcc, 0xcc, 0xcc, 0x66,
    0x63, 0x10,

    /* U+29 ")" */
    0x8c, 0xc6, 0x62, 0x33, 0x33, 0x33, 0x33, 0x66,
    0x6c, 0x80,

    /* U+2A "*" */
    0x18, 0x18, 0x99, 0xff, 0x1c, 0x3c, 0x66, 0x44,

    /* U+2B "+" */
    0x38, 0x70, 0xe7, 0xff, 0xe7, 0xe, 0x1c, 0x38,

    /* U+2C "," */
    0x6d, 0xbc, 0x0,

    /* U+2D "-" */
    0xff,

    /* U+2E "." */
    0xff, 0x80,

    /* U+2F "/" */
    0xc, 0x61, 0x86, 0x10, 0xc3, 0xc, 0x21, 0x86,
    0x18, 0xc3, 0xc, 0x0,

    /* U+30 "0" */
    0x3c, 0x7e, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7,
    0xe7, 0xe7, 0xe7, 0x7e, 0x3c,

    /* U+31 "1" */
    0xc, 0xff, 0xf7, 0x1c, 0x71, 0xc7, 0x1c, 0x71,
    0xc7, 0x1c,

    /* U+32 "2" */
    0x3c, 0x7e, 0xee, 0xee, 0xe, 0xe, 0x1c, 0x3c,
    0x38, 0x70, 0x70, 0xff, 0xff,

    /* U+33 "3" */
    0x3c, 0x7e, 0xe7, 0x7, 0x7, 0x1e, 0x1e, 0x7,
    0x7, 0xe7, 0xe7, 0x7e, 0x3c,

    /* U+34 "4" */
    0xe, 0x1e, 0x1e, 0x3e, 0x3e, 0x6e, 0x6e, 0xce,
    0xff, 0xff, 0xe, 0xe, 0xe,

    /* U+35 "5" */
    0x7f, 0x7f, 0x60, 0x60, 0xfc, 0xfe, 0x4f, 0x7,
    0x7, 0xc7, 0xe7, 0x7e, 0x3c,

    /* U+36 "6" */
    0x1c, 0x3c, 0x70, 0x60, 0xfc, 0xfe, 0xe7, 0xe7,
    0xe7, 0xe7, 0xe7, 0x7e, 0x3c,

    /* U+37 "7" */
    0xff, 0xff, 0x7, 0x6, 0xe, 0xe, 0xc, 0x1c,
    0x18, 0x38, 0x38, 0x30, 0x70,

    /* U+38 "8" */
    0x7d, 0xff, 0xbf, 0x7e, 0xef, 0x9f, 0x77, 0xef,
    0xdf, 0xbb, 0xe3, 0x80,

    /* U+39 "9" */
    0x3c, 0x7e, 0xe6, 0xe7, 0xe7, 0xe7, 0xe7, 0x7f,
    0x3f, 0x6, 0xe, 0x3c, 0x38,

    /* U+3A ":" */
    0xff, 0x80, 0x7, 0xfc,

    /* U+3B ";" */
    0xff, 0x80, 0x0, 0x6d, 0xbc, 0x0,

    /* U+3C "<" */
    0x2, 0x1c, 0xff, 0x8e, 0x1f, 0xf, 0x87, 0x2,

    /* U+3D "=" */
    0xff, 0xfc, 0x0, 0xf, 0xff, 0xc0,

    /* U+3E ">" */
    0x81, 0xc3, 0xe1, 0xf0, 0xe7, 0xbc, 0x70, 0x80,

    /* U+3F "?" */
    0x7d, 0xff, 0xb8, 0x70, 0xe3, 0x8e, 0x18, 0x30,
    0x0, 0xe1, 0xc3, 0x80,

    /* U+40 "@" */
    0xf, 0x81, 0xfc, 0x38, 0x67, 0x2, 0x67, 0x3c,
    0x79, 0xcd, 0x9c, 0xd9, 0xd9, 0x9d, 0x99, 0xdd,
    0xbc, 0xfe, 0xee, 0xc6, 0x0, 0x70, 0x3, 0xf8,
    0xf, 0x0,

    /* U+41 "A" */
    0xe, 0x1, 0xc0, 0x78, 0xf, 0x81, 0xb0, 0x76,
    0xe, 0xe1, 0x9c, 0x3f, 0x8f, 0xf1, 0xc7, 0x30,
    0xee, 0xc,

    /* U+42 "B" */
    0xfc, 0xff, 0xe7, 0xe7, 0xe7, 0xfe, 0xfe, 0xe7,
    0xe7, 0xe7, 0xe7, 0xfe, 0xfc,

    /* U+43 "C" */
    0x3e, 0x3f, 0x9c, 0xfc, 0x7e, 0x7, 0x3, 0x81,
    0xc0, 0xe0, 0x71, 0xf8, 0xef, 0xe3, 0xe0,

    /* U+44 "D" */
    0xf8, 0xfe, 0xe6, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7,
    0xe7, 0xe7, 0xe6, 0xfe, 0xf8,

    /* U+45 "E" */
    0xff, 0xff, 0xe0, 0xe0, 0xe0, 0xfe, 0xfe, 0xe0,
    0xe0, 0xe0, 0xe0, 0xff, 0xff,

    /* U+46 "F" */
    0xff, 0xff, 0x87, 0xe, 0x1f, 0xff, 0xf0, 0xe1,
    0xc3, 0x87, 0xe, 0x0,

    /* U+47 "G" */
    0x3e, 0x3f, 0xbc, 0xfc, 0x7e, 0x7, 0x3, 0x9f,
    0xcf, 0xe3, 0xf1, 0xfc, 0xef, 0xf3, 0xe0,

    /* U+48 "H" */
    0xe3, 0xf1, 0xf8, 0xfc, 0x7e, 0x3f, 0xff, 0xff,
    0xc7, 0xe3, 0xf1, 0xf8, 0xfc, 0x7e, 0x38,

    /* U+49 "I" */
    0xff, 0xff, 0xff, 0xff, 0xfe,

    /* U+4A "J" */
    0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7, 0x7,
    0x7, 0xe7, 0xe7, 0x7e, 0x3c,

    /* U+4B "K" */
    0xe3, 0xf3, 0xb9, 0xdd, 0xce, 0xe7, 0xe3, 0xf1,
    0xfc, 0xfe, 0x73, 0xb9, 0xdc, 0x7e, 0x38,

    /* U+4C "L" */
    0xe1, 0xc3, 0x87, 0xe, 0x1c, 0x38, 0x70, 0xe1,
    0xc3, 0x87, 0xff, 0xe0,

    /* U+4D "M" */
    0xf0, 0xff, 0xf, 0xf0, 0xff, 0x9f, 0xf9, 0xff,
    0x9f, 0xe9, 0x7e, 0xf7, 0xef, 0x7e, 0xf7, 0xe6,
    0x7e, 0x67, 0xe6, 0x70,

    /* U+4E "N" */
    0xe3, 0xf9, 0xfc, 0xfe, 0x7f, 0xbf, 0xdf, 0xaf,
    0xdf, 0xef, 0xf3, 0xf9, 0xfc, 0xfe, 0x38,

    /* U+4F "O" */
    0x3e, 0x3f, 0x9d, 0xdc, 0x7e, 0x3f, 0x1f, 0x8f,
    0xc7, 0xe3, 0xf1, 0xfd, 0xcf, 0xe3, 0xe0,

    /* U+50 "P" */
    0xfe, 0x7f, 0xb8, 0xfc, 0x7e, 0x3f, 0x1f, 0xfd,
    0xfc, 0xe0, 0x70, 0x38, 0x1c, 0xe, 0x0,

    /* U+51 "Q" */
    0x3e, 0x3f, 0x9d, 0xdc, 0x7e, 0x3f, 0x1f, 0x8f,
    0xc7, 0xe3, 0xf1, 0xdd, 0xcf, 0xe3, 0xf0, 0x1c,
    0xc,

    /* U+52 "R" */
    0xfc, 0xfe, 0xe7, 0xe7, 0xe7, 0xe7, 0xfe, 0xfc,
    0xec, 0xee, 0xe6, 0xe7, 0xe7,

    /* U+53 "S" */
    0x3e, 0x3f, 0xb8, 0xfc, 0x7f, 0x3, 0xe0, 0xfc,
    0x1e, 0x3, 0xf1, 0xf8, 0xef, 0xe3, 0xe0,

    /* U+54 "T" */
    0xff, 0xff, 0xc7, 0x3, 0x81, 0xc0, 0xe0, 0x70,
    0x38, 0x1c, 0xe, 0x7, 0x3, 0x81, 0xc0,

    /* U+55 "U" */
    0xe3, 0xf1, 0xf8, 0xfc, 0x7e, 0x3f, 0x1f, 0x8f,
    0xc7, 0xe3, 0xf1, 0xf8, 0xef, 0xe3, 0xe0,

    /* U+56 "V" */
    0xe1, 0xd8, 0x77, 0x1d, 0xc6, 0x73, 0x8c, 0xe3,
    0x30, 0xec, 0x1f, 0x7, 0xc1, 0xe0, 0x78, 0xe,
    0x0,

    /* U+57 "W" */
    0xe3, 0x3b, 0x39, 0xd9, 0xce, 0xce, 0x77, 0x7b,
    0x3b, 0xd8, 0xfe, 0xc7, 0xbe, 0x3d, 0xf1, 0xe7,
    0xf, 0x38, 0x79, 0xc1, 0x8e, 0x0,

    /* U+58 "X" */
    0x71, 0x9c, 0xe3, 0x38, 0xfc, 0x3f, 0x7, 0x81,
    0xe0, 0x78, 0x3f, 0xf, 0xc7, 0x39, 0xce, 0x61,
    0xc0,

    /* U+59 "Y" */
    0xe3, 0xf1, 0xd8, 0xce, 0xe7, 0x71, 0xb0, 0xf8,
    0x38, 0x1c, 0xe, 0x7, 0x3, 0x81, 0xc0,

    /* U+5A "Z" */
    0xff, 0xff, 0x6, 0xe, 0xc, 0x1c, 0x18, 0x38,
    0x30, 0x70, 0x60, 0xff, 0xff,

    /* U+5B "[" */
    0xff, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee, 0xee,
    0xff,

    /* U+5C "\\" */
    0xe0, 0xc1, 0x83, 0x87, 0x6, 0xe, 0x1c, 0x18,
    0x38, 0x70, 0x60, 0xc1, 0xc1, 0x80,

    /* U+5D "]" */
    0xff, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77,
    0xff,

    /* U+5E "^" */
    0x10, 0x70, 0xe1, 0x46, 0xcd, 0x99, 0x0,

    /* U+5F "_" */
    0xff, 0xfc,

    /* U+61 "a" */
    0x3d, 0xff, 0xb8, 0x77, 0xff, 0xfb, 0xf7, 0xfe,
    0xfc,

    /* U+62 "b" */
    0xe0, 0xe0, 0xe0, 0xe0, 0xfe, 0xfe, 0xe7, 0xe7,
    0xe7, 0xe7, 0xe7, 0xe7, 0xfe, 0xfe,

    /* U+63 "c" */
    0x3c, 0xfb, 0xbf, 0x7e, 0x1c, 0x38, 0x77, 0x7c,
    0x70,

    /* U+64 "d" */
    0x7, 0x7, 0x7, 0x7, 0x7f, 0x7f, 0xe7, 0xe7,
    0xe7, 0xe7, 0xe7, 0xe7, 0x7f, 0x7f,

    /* U+65 "e" */
    0x3c, 0x7e, 0xe7, 0xe7, 0xff, 0xff, 0xe0, 0xe2,
    0x7f, 0x3e,

    /* U+66 "f" */
    0x3b, 0xdc, 0xef, 0xfd, 0xce, 0x73, 0x9c, 0xe7,
    0x38,

    /* U+67 "g" */
    0x3f, 0x7f, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7,
    0x7f, 0x3f, 0x7, 0x47, 0x7e, 0x3c,

    /* U+68 "h" */
    0xe1, 0xc3, 0x87, 0xf, 0xdf, 0xfb, 0xf7, 0xef,
    0xdf, 0xbf, 0x7e, 0xfd, 0xc0,

    /* U+69 "i" */
    0xfc, 0xf, 0xff, 0xff, 0xff, 0xc0,

    /* U+6A "j" */
    0x39, 0xc0, 0x3, 0x9c, 0xe7, 0x39, 0xce, 0x73,
    0x9c, 0xe7, 0xff, 0x80,

    /* U+6B "k" */
    0xe0, 0xe0, 0xe0, 0xe0, 0xe7, 0xee, 0xec, 0xfc,
    0xf8, 0xfc, 0xec, 0xee, 0xe6, 0xe7,

    /* U+6C "l" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xc0,

    /* U+6D "m" */
    0xfd, 0xdf, 0xff, 0xbb, 0xf7, 0x7e, 0xef, 0xdd,
    0xfb, 0xbf, 0x77, 0xee, 0xfd, 0xdc,

    /* U+6E "n" */
    0xfd, 0xff, 0xbf, 0x7e, 0xfd, 0xfb, 0xf7, 0xef,
    0xdc,

    /* U+6F "o" */
    0x3c, 0x7e, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7,
    0x7e, 0x3c,

    /* U+70 "p" */
    0xfe, 0xfe, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7,
    0xfe, 0xfe, 0xe0, 0xe0, 0xe0, 0xe0,

    /* U+71 "q" */
    0x7f, 0x7f, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7, 0xe7,
    0x7f, 0x7f, 0x7, 0x7, 0x7, 0x7,

    /* U+72 "r" */
    0xff, 0xf9, 0xce, 0x73, 0x9c, 0xe7, 0x0,

    /* U+73 "s" */
    0x7d, 0xff, 0xbf, 0xf, 0x87, 0x83, 0xf7, 0x7e,
    0x78,

    /* U+74 "t" */
    0x73, 0x9d, 0xff, 0xb9, 0xce, 0x73, 0x9c, 0xf3,
    0x80,

    /* U+75 "u" */
    0xef, 0xdf, 0xbf, 0x7e, 0xfd, 0xfb, 0xf7, 0xfe,
    0xfc,

    /* U+76 "v" */
    0xe7, 0x66, 0x66, 0x76, 0x7e, 0x3c, 0x3c, 0x3c,
    0x3c, 0x18,

    /* U+77 "w" */
    0xe6, 0x6d, 0xdd, 0xbb, 0xb7, 0x66, 0xfc, 0xf7,
    0x8e, 0xf1, 0xde, 0x39, 0x86, 0x30,

    /* U+78 "x" */
    0x67, 0x76, 0x7e, 0x3c, 0x3c, 0x3c, 0x3c, 0x7e,
    0x76, 0xe7,

    /* U+79 "y" */
    0xe7, 0xe6, 0x66, 0x6e, 0x7e, 0x3c, 0x3c, 0x3c,
    0x38, 0x18, 0x18, 0x38, 0x70, 0x60,

    /* U+7A "z" */
    0xff, 0xfc, 0x30, 0xe3, 0x87, 0x1c, 0x30, 0xff,
    0xfc,

    /* U+7B "{" */
    0x13, 0x66, 0x66, 0x66, 0xcc, 0x66, 0x66, 0x66,
    0x31,

    /* U+7D "}" */
    0x8c, 0x66, 0x66, 0x66, 0x33, 0x66, 0x66, 0x66,
    0xc8
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 66, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 75, .box_w = 3, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 6, .adv_w = 92, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 10, .adv_w = 152, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 23, .adv_w = 146, .box_w = 8, .box_h = 17, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 40, .adv_w = 184, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 57, .adv_w = 167, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 74, .adv_w = 46, .box_w = 2, .box_h = 5, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 76, .adv_w = 93, .box_w = 4, .box_h = 19, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 86, .adv_w = 93, .box_w = 4, .box_h = 19, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 96, .adv_w = 131, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 104, .adv_w = 137, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 112, .adv_w = 71, .box_w = 3, .box_h = 6, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 115, .adv_w = 105, .box_w = 4, .box_h = 2, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 116, .adv_w = 84, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 118, .adv_w = 95, .box_w = 6, .box_h = 15, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 130, .adv_w = 146, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 143, .adv_w = 146, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 153, .adv_w = 146, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 166, .adv_w = 146, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 179, .adv_w = 146, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 192, .adv_w = 146, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 205, .adv_w = 146, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 218, .adv_w = 146, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 231, .adv_w = 146, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 243, .adv_w = 146, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 256, .adv_w = 79, .box_w = 3, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 260, .adv_w = 73, .box_w = 3, .box_h = 14, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 266, .adv_w = 129, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 274, .adv_w = 145, .box_w = 7, .box_h = 6, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 280, .adv_w = 131, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 288, .adv_w = 129, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 300, .adv_w = 221, .box_w = 12, .box_h = 17, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 326, .adv_w = 172, .box_w = 11, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 344, .adv_w = 162, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 357, .adv_w = 164, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 372, .adv_w = 163, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 385, .adv_w = 141, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 398, .adv_w = 137, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 410, .adv_w = 168, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 425, .adv_w = 177, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 440, .adv_w = 78, .box_w = 3, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 445, .adv_w = 141, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 458, .adv_w = 159, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 473, .adv_w = 138, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 485, .adv_w = 218, .box_w = 12, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 505, .adv_w = 176, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 520, .adv_w = 174, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 535, .adv_w = 164, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 550, .adv_w = 174, .box_w = 9, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 567, .adv_w = 159, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 580, .adv_w = 156, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 595, .adv_w = 156, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 610, .adv_w = 165, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 625, .adv_w = 167, .box_w = 10, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 642, .adv_w = 216, .box_w = 13, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 664, .adv_w = 161, .box_w = 10, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 681, .adv_w = 156, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 696, .adv_w = 153, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 709, .adv_w = 76, .box_w = 4, .box_h = 18, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 718, .adv_w = 110, .box_w = 7, .box_h = 15, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 732, .adv_w = 76, .box_w = 4, .box_h = 18, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 741, .adv_w = 113, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 7},
    {.bitmap_index = 748, .adv_w = 115, .box_w = 7, .box_h = 2, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 750, .adv_w = 136, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 759, .adv_w = 143, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 773, .adv_w = 132, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 782, .adv_w = 143, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 796, .adv_w = 138, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 806, .adv_w = 94, .box_w = 5, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 815, .adv_w = 145, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 829, .adv_w = 142, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 842, .adv_w = 73, .box_w = 3, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 848, .adv_w = 71, .box_w = 5, .box_h = 18, .ofs_x = -1, .ofs_y = -4},
    {.bitmap_index = 860, .adv_w = 138, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 874, .adv_w = 73, .box_w = 3, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 880, .adv_w = 214, .box_w = 11, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 894, .adv_w = 142, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 903, .adv_w = 143, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 913, .adv_w = 143, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 927, .adv_w = 143, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 941, .adv_w = 95, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 948, .adv_w = 131, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 957, .adv_w = 88, .box_w = 5, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 966, .adv_w = 142, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 975, .adv_w = 129, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 985, .adv_w = 182, .box_w = 11, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 999, .adv_w = 130, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1009, .adv_w = 129, .box_w = 8, .box_h = 14, .ofs_x = 0, .ofs_y = -4},
    {.bitmap_index = 1023, .adv_w = 130, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1032, .adv_w = 86, .box_w = 4, .box_h = 18, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1041, .adv_w = 86, .box_w = 4, .box_h = 18, .ofs_x = 0, .ofs_y = -3}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 64, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 97, .range_length = 27, .glyph_id_start = 65,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 125, .range_length = 1, .glyph_id_start = 92,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    1, 53,
    3, 3,
    3, 8,
    3, 34,
    3, 65,
    3, 67,
    3, 68,
    3, 69,
    3, 71,
    3, 77,
    3, 78,
    3, 79,
    3, 80,
    3, 81,
    3, 83,
    3, 87,
    8, 3,
    8, 8,
    8, 34,
    8, 65,
    8, 67,
    8, 68,
    8, 69,
    8, 71,
    8, 77,
    8, 78,
    8, 79,
    8, 80,
    8, 81,
    8, 83,
    8, 87,
    9, 55,
    9, 56,
    9, 58,
    13, 3,
    13, 8,
    15, 3,
    15, 8,
    16, 16,
    34, 3,
    34, 8,
    34, 32,
    34, 36,
    34, 40,
    34, 48,
    34, 50,
    34, 53,
    34, 54,
    34, 55,
    34, 56,
    34, 58,
    34, 77,
    34, 78,
    34, 79,
    34, 80,
    34, 84,
    34, 85,
    34, 86,
    34, 87,
    34, 89,
    34, 90,
    35, 53,
    35, 55,
    35, 58,
    36, 10,
    36, 53,
    36, 62,
    36, 92,
    37, 13,
    37, 15,
    37, 34,
    37, 53,
    37, 55,
    37, 57,
    37, 58,
    37, 59,
    38, 53,
    38, 67,
    38, 68,
    38, 69,
    38, 70,
    38, 71,
    38, 79,
    38, 81,
    38, 85,
    38, 86,
    38, 87,
    38, 89,
    39, 13,
    39, 15,
    39, 34,
    39, 43,
    39, 53,
    39, 65,
    39, 67,
    39, 68,
    39, 69,
    39, 71,
    39, 79,
    39, 81,
    39, 82,
    39, 85,
    39, 86,
    39, 89,
    41, 34,
    41, 53,
    41, 57,
    41, 58,
    42, 34,
    42, 53,
    42, 57,
    42, 58,
    43, 34,
    44, 14,
    44, 36,
    44, 40,
    44, 48,
    44, 50,
    44, 67,
    44, 68,
    44, 69,
    44, 71,
    44, 79,
    44, 81,
    44, 85,
    44, 86,
    44, 87,
    44, 89,
    45, 3,
    45, 8,
    45, 34,
    45, 36,
    45, 40,
    45, 48,
    45, 50,
    45, 53,
    45, 54,
    45, 55,
    45, 56,
    45, 58,
    45, 85,
    45, 86,
    45, 87,
    45, 89,
    46, 34,
    46, 53,
    46, 57,
    46, 58,
    47, 34,
    47, 53,
    47, 57,
    47, 58,
    48, 13,
    48, 15,
    48, 34,
    48, 53,
    48, 55,
    48, 57,
    48, 58,
    48, 59,
    49, 13,
    49, 15,
    49, 34,
    49, 43,
    49, 57,
    49, 59,
    49, 65,
    49, 67,
    49, 68,
    49, 69,
    49, 71,
    49, 79,
    49, 81,
    49, 84,
    49, 86,
    49, 89,
    50, 53,
    50, 55,
    50, 56,
    50, 58,
    51, 53,
    51, 55,
    51, 58,
    53, 1,
    53, 13,
    53, 14,
    53, 15,
    53, 34,
    53, 36,
    53, 40,
    53, 43,
    53, 48,
    53, 50,
    53, 52,
    53, 53,
    53, 55,
    53, 56,
    53, 58,
    53, 65,
    53, 67,
    53, 68,
    53, 69,
    53, 71,
    53, 77,
    53, 78,
    53, 79,
    53, 80,
    53, 81,
    53, 82,
    53, 83,
    53, 85,
    53, 86,
    53, 87,
    53, 88,
    53, 89,
    53, 90,
    54, 34,
    55, 10,
    55, 13,
    55, 14,
    55, 15,
    55, 34,
    55, 36,
    55, 40,
    55, 48,
    55, 50,
    55, 62,
    55, 65,
    55, 67,
    55, 68,
    55, 69,
    55, 71,
    55, 79,
    55, 81,
    55, 82,
    55, 85,
    55, 86,
    55, 89,
    55, 92,
    56, 10,
    56, 13,
    56, 14,
    56, 15,
    56, 34,
    56, 53,
    56, 62,
    56, 65,
    56, 67,
    56, 68,
    56, 69,
    56, 71,
    56, 79,
    56, 81,
    56, 82,
    56, 85,
    56, 92,
    57, 14,
    57, 36,
    57, 40,
    57, 48,
    57, 50,
    57, 55,
    57, 67,
    57, 68,
    57, 69,
    57, 71,
    57, 79,
    57, 81,
    57, 85,
    57, 86,
    57, 89,
    58, 7,
    58, 10,
    58, 11,
    58, 13,
    58, 14,
    58, 15,
    58, 34,
    58, 36,
    58, 40,
    58, 43,
    58, 48,
    58, 50,
    58, 52,
    58, 53,
    58, 54,
    58, 55,
    58, 56,
    58, 57,
    58, 58,
    58, 62,
    58, 65,
    58, 67,
    58, 68,
    58, 69,
    58, 70,
    58, 71,
    58, 77,
    58, 78,
    58, 79,
    58, 80,
    58, 81,
    58, 82,
    58, 83,
    58, 84,
    58, 85,
    58, 86,
    58, 88,
    58, 89,
    58, 90,
    58, 92,
    59, 34,
    59, 36,
    59, 40,
    59, 48,
    59, 50,
    59, 67,
    59, 68,
    59, 69,
    59, 71,
    59, 79,
    59, 81,
    59, 85,
    59, 86,
    59, 87,
    59, 89,
    60, 43,
    60, 54,
    65, 3,
    65, 8,
    65, 86,
    65, 89,
    66, 3,
    66, 8,
    66, 86,
    66, 88,
    66, 89,
    66, 90,
    67, 3,
    67, 8,
    69, 3,
    69, 8,
    69, 86,
    69, 89,
    70, 3,
    70, 8,
    70, 10,
    70, 62,
    70, 67,
    70, 68,
    70, 69,
    70, 71,
    70, 81,
    70, 92,
    72, 3,
    72, 8,
    75, 67,
    75, 68,
    75, 69,
    75, 71,
    75, 81,
    77, 3,
    77, 8,
    78, 3,
    78, 8,
    79, 3,
    79, 8,
    79, 86,
    79, 88,
    79, 89,
    79, 90,
    80, 3,
    80, 8,
    80, 86,
    80, 88,
    80, 89,
    80, 90,
    82, 3,
    82, 8,
    82, 13,
    82, 15,
    82, 65,
    82, 67,
    82, 68,
    82, 69,
    82, 70,
    82, 71,
    82, 79,
    82, 81,
    82, 84,
    82, 86,
    82, 87,
    82, 89,
    84, 79,
    86, 3,
    86, 8,
    86, 13,
    86, 15,
    86, 65,
    86, 67,
    86, 68,
    86, 69,
    86, 70,
    86, 71,
    86, 79,
    86, 81,
    87, 13,
    87, 15,
    88, 67,
    88, 68,
    88, 69,
    88, 71,
    88, 79,
    88, 81,
    89, 3,
    89, 8,
    89, 13,
    89, 15,
    89, 65,
    89, 67,
    89, 68,
    89, 69,
    89, 70,
    89, 71,
    89, 79,
    89, 81,
    90, 67,
    90, 68,
    90, 69,
    90, 71,
    90, 79,
    90, 81,
    91, 43,
    91, 54
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    -8, -5, -5, -17, -7, -8, -8, -8,
    -8, -3, -3, -13, -3, -8, -13, 2,
    -5, -5, -17, -7, -8, -8, -8, -8,
    -3, -3, -13, -3, -8, -13, 2, 3,
    5, 3, -40, -40, -40, -40, -35, -17,
    -17, -11, -3, -3, -3, -3, -17, -2,
    -11, -5, -21, -7, -7, -2, -7, -2,
    -2, -7, -5, -7, 2, -4, -3, -8,
    -4, -4, -2, -2, -17, -17, -3, -12,
    -3, -3, -6, -3, 3, -3, -3, -3,
    -3, -3, -3, -3, -2, -4, -3, -4,
    -39, -39, -27, -29, 3, -5, -3, -3,
    -3, -3, -3, -3, -4, -3, -3, -3,
    3, -4, 2, -4, 3, -4, 2, -4,
    -3, -23, -4, -4, -4, -4, -4, -4,
    -4, -4, -4, -4, -3, -6, -9, -6,
    -40, -40, 3, -9, -9, -9, -9, -29,
    -3, -29, -13, -39, -2, -17, -7, -17,
    3, -4, 2, -4, 3, -4, 2, -4,
    -17, -17, -3, -12, -3, -3, -6, -3,
    -57, -57, -25, -26, -7, -5, -2, -2,
    -2, -2, -2, -2, -2, 2, 2, 2,
    -5, -4, -3, -5, -7, -3, -7, -8,
    -36, -38, -36, -17, -4, -4, -30, -4,
    -4, -2, 2, 2, 2, 2, -24, -13,
    -13, -13, -13, -13, -13, -29, -13, -13,
    -9, -11, -9, -12, -7, -11, -12, -8,
    -3, 3, -30, -22, -30, -11, -2, -2,
    -2, -2, 2, -6, -6, -6, -6, -6,
    -6, -6, -4, -4, -2, -2, 3, 2,
    -20, -8, -20, -6, 2, 2, -5, -4,
    -4, -4, -4, -4, -4, -3, -3, 2,
    -22, -4, -4, -4, -4, 2, -4, -4,
    -4, -4, -3, -4, -3, -4, -4, -4,
    3, -7, -32, -21, -32, -21, -4, -4,
    -13, -4, -4, -2, 2, -13, 3, 2,
    2, 3, 3, -9, -9, -9, -9, -3,
    -9, -6, -6, -9, -6, -9, -6, -8,
    -3, -5, -3, -3, -3, -4, 3, 2,
    -4, -4, -4, -4, -3, -3, -3, -3,
    -3, -3, -3, -4, -4, -4, -3, -3,
    -2, -2, -2, -2, -4, -4, -2, -2,
    -2, -2, -2, -2, -2, -2, -2, -2,
    2, 2, 3, 3, -3, -3, -3, -3,
    -3, 3, -11, -11, -3, -3, -3, -3,
    -3, -11, -11, -11, -11, -12, -12, -2,
    -3, -2, -2, -4, -4, -2, -2, -2,
    -2, 2, 2, -24, -24, -4, -3, -3,
    -3, 3, -3, -5, -3, 7, 3, 2,
    3, -4, 2, 2, -23, -23, -2, -2,
    -2, -2, 2, -2, -2, -2, -17, -17,
    -3, -3, -3, -3, -6, -3, 2, 2,
    -23, -23, -2, -2, -2, -2, 2, -2,
    -2, -2, -2, -2, -2, -2, -2, -2,
    -3, -3
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 434,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

/*Store all the custom data of the font*/
static lv_font_fmt_txt_dsc_t font_dsc = {
    .glyph_bitmap = gylph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_pairs,
    .kern_scale = 16,
    .cmap_num = 3,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
lv_font_t roboto_condensed_bold_18 = {
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 19,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};

#endif /*#if ROBOTO_CONDENSED_BOLD_18*/

