#ifndef LV_CONF_H
#define LV_CONF_H

/*====================
   Graphical settings
 *====================*/

/* Maximal horizontal and vertical resolution to support by the library.*/
#define LV_HOR_RES_MAX          (240)
#define LV_VER_RES_MAX          (320)

/* Color depth:
 * - 1: 1 byte per pixel (monochrome)
 * - 8: 8 byte per pixel (256 colors)
 * - 16: 16 byte per pixel (65k colors)
 * - 32: 32 byte per pixel (true color)
 */
#define LV_COLOR_DEPTH          16

/* Enable anti-aliasing */
#define LV_ANTIALIAS            1

/* Enable GPU interface */
#define LV_USE_GPU              0

/*==================
   Memory settings
 *==================*/

/* Size of the memory used by the library */
#define LV_MEM_SIZE             (32U * 1024U)

/*==================
   Feature usage
 *==================*/

/* Enable or disable features here as needed */
#define LV_USE_LOG              1
#define LV_USE_ASSERT_NULL      1
#define LV_USE_ASSERT_MEM       1
#define LV_USE_ASSERT_STYLE     1
#define LV_USE_ASSERT_OBJ       1

/*==================
   Miscellaneous
 *==================*/

/* Default display refresh period in milliseconds */
#define LV_DISP_DEF_REFR_PERIOD 30

#endif /*LV_CONF_H*/
