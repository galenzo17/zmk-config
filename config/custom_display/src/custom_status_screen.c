#include <lvgl.h>

lv_obj_t *zmk_display_status_screen() {
    lv_obj_t *screen = lv_obj_create(NULL);
    lv_obj_t *label = lv_label_create(screen);

    lv_coord_t h = lv_disp_get_ver_res(NULL);

    if (h >= 64) {
        /* Portrait/rotated display: vertical text */
        lv_label_set_text(label, "J\nU\nS\nT\n \nC\nO\nD\nE");
        lv_obj_set_style_text_line_space(label, 2, 0);
    } else {
        /* Landscape display: two lines */
        lv_label_set_text(label, "JUST\nCODE");
        lv_obj_set_style_text_line_space(label, 4, 0);
    }

    lv_obj_set_style_text_align(label, LV_TEXT_ALIGN_CENTER, 0);
    lv_obj_set_width(label, LV_PCT(100));
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);

    return screen;
}
