#include "ui_resources.h"

#include <map>
#include "base/strings/string16.h"

std::map<int, string16> id_files;

namespace ui_map
{
  void InitUiMap()
  {
    if(id_files.size() > 0) return;

    id_files[IDR_APP_LIST_ITEM_PROGRESS_BACKGROUND] = L"common\\app_list_progress_bar_background.png";
    id_files[IDR_APP_LIST_ITEM_PROGRESS_CENTER] = L"common\\app_list_progress_bar_center.png";
    id_files[IDR_APP_LIST_ITEM_PROGRESS_LEFT] = L"common\\app_list_progress_bar_left.png";
    id_files[IDR_APP_LIST_ITEM_PROGRESS_CENTER] = L"common\\app_list_progress_bar_center.png";
    id_files[IDR_APP_LIST_ITEM_PROGRESS_RIGHT] = L"common\\app_list_progress_bar_right.png";
    id_files[IDR_APP_LIST_TOOLS_HOVER] = L"common\\app_list_tools_hover.png";
    id_files[IDR_APP_LIST_TOOLS_NORMAL] = L"common\\app_list_tools_normal.png";
    id_files[IDR_APP_LIST_TOOLS_PRESSED] = L"common\\app_list_tools_pressed.png";
    id_files[IDR_APP_LIST_USER_INDICATOR] = L"win\\app_list_user_indicator.png";
    id_files[IDR_APP_TOP_CENTER] = L"app_top_center.png";
    id_files[IDR_APP_TOP_LEFT] = L"app_top_left.png";
    id_files[IDR_APP_TOP_RIGHT] = L"app_top_right.png";
    id_files[IDR_AURA_CURSOR_BIG_ALIAS] = L"common\\pointers\\alias_big.png";
    id_files[IDR_AURA_CURSOR_BIG_CELL] = L"common\\pointers\\cell_big.png";
    id_files[IDR_AURA_CURSOR_BIG_COL_RESIZE] = L"common\\pointers\\sb_h_double_arrow_big.png";
    id_files[IDR_AURA_CURSOR_BIG_CONTEXT_MENU] = L"common\\pointers\\context_menu_big.png";
    id_files[IDR_AURA_CURSOR_BIG_COPY] = L"common\\pointers\\copy_big.png";
    id_files[IDR_AURA_CURSOR_BIG_CROSSHAIR] = L"common\\pointers\\crosshair_big.png";
    id_files[IDR_AURA_CURSOR_BIG_EAST_RESIZE] = L"common\\pointers\\sb_h_double_arrow_big.png";
    id_files[IDR_AURA_CURSOR_BIG_EAST_WEST_RESIZE] = L"common\\pointers\\sb_h_double_arrow_big.png";
    id_files[IDR_AURA_CURSOR_BIG_FLEUR] = L"common\\pointers\\fleur_big.png";
    id_files[IDR_AURA_CURSOR_BIG_HAND] = L"common\\pointers\\hand2_big.png";
    id_files[IDR_AURA_CURSOR_BIG_HELP] = L"common\\pointers\\help_big.png";
    id_files[IDR_AURA_CURSOR_BIG_IBEAM] = L"common\\pointers\\xterm_big.png";
    id_files[IDR_AURA_CURSOR_BIG_MOVE] = L"common\\pointers\\move_big.png";
    id_files[IDR_AURA_CURSOR_BIG_NORTH_EAST_RESIZE] = L"common\\pointers\\top_right_corner_big.png";
    id_files[IDR_AURA_CURSOR_BIG_NORTH_EAST_SOUTH_WEST_RESIZE] = L"common\\pointers\\top_right_corner_big.png";
    id_files[IDR_AURA_CURSOR_BIG_NORTH_RESIZE] = L"common\\pointers\\sb_v_double_arrow_big.png";
    id_files[IDR_AURA_CURSOR_BIG_NORTH_SOUTH_RESIZE] = L"common\\pointers\\sb_v_double_arrow_big.png";
    id_files[IDR_AURA_CURSOR_BIG_NORTH_WEST_RESIZE] = L"common\\pointers\\top_left_corner_big.png";
    id_files[IDR_AURA_CURSOR_BIG_NORTH_WEST_SOUTH_EAST_RESIZE] = L"common\\pointers\\top_left_corner_big.png";
    id_files[IDR_AURA_CURSOR_BIG_NO_DROP] = L"common\\pointers\\nodrop_big.png";
    id_files[IDR_AURA_CURSOR_BIG_PTR] = L"common\\pointers\\left_ptr_big.png";
    id_files[IDR_AURA_CURSOR_BIG_ROW_RESIZE] = L"common\\pointers\\sb_v_double_arrow_big.png";
    id_files[IDR_AURA_CURSOR_BIG_SOUTH_EAST_RESIZE] = L"common\\pointers\\top_left_corner_big.png";
    id_files[IDR_AURA_CURSOR_BIG_SOUTH_RESIZE] = L"common\\pointers\\sb_v_double_arrow_big.png";
    id_files[IDR_AURA_CURSOR_BIG_SOUTH_WEST_RESIZE] = L"common\\pointers\\top_right_corner_big.png";
    id_files[IDR_AURA_CURSOR_BIG_WEST_RESIZE] = L"common\\pointers\\sb_h_double_arrow_big.png";
    id_files[IDR_AURA_CURSOR_BIG_XTERM_HORIZ] = L"common\\pointers\\xterm_horiz_big.png";
    id_files[IDR_AURA_CURSOR_BIG_ZOOM_IN] = L"common\\pointers\\zoom_in_big.png";
    id_files[IDR_AURA_CURSOR_BIG_ZOOM_OUT] = L"common\\pointers\\zoom_out_big.png";
    id_files[IDR_AURA_CURSOR_BIG_GRAB] = L"common\\pointers\\fleur_big.png";
    id_files[IDR_AURA_CURSOR_BIG_GRABBING] = L"common\\pointers\\hand3_big.png";
    id_files[IDR_AURA_CURSOR_ALIAS] = L"common\\pointers\\alias.png";
    id_files[IDR_AURA_CURSOR_CELL] = L"common\\pointers\\cell.png";
    id_files[IDR_AURA_CURSOR_COL_RESIZE] = L"common\\pointers\\sb_h_double_arrow.png";
    id_files[IDR_AURA_CURSOR_CONTEXT_MENU] = L"common\\pointers\\context_menu.png";
    id_files[IDR_AURA_CURSOR_COPY] = L"common\\pointers\\copy.png";
    id_files[IDR_AURA_CURSOR_CROSSHAIR] = L"common\\pointers\\crosshair.png";
    id_files[IDR_AURA_CURSOR_EAST_RESIZE] = L"common\\pointers\\sb_h_double_arrow.png";
    id_files[IDR_AURA_CURSOR_EAST_WEST_RESIZE] = L"common\\pointers\\sb_h_double_arrow.png";
    id_files[IDR_AURA_CURSOR_FLEUR] = L"common\\pointers\\fleur.png";
    id_files[IDR_AURA_CURSOR_HAND] = L"common\\pointers\\hand2.png";
    id_files[IDR_AURA_CURSOR_HELP] = L"common\\pointers\\help.png";
    id_files[IDR_AURA_CURSOR_IBEAM] = L"common\\pointers\\xterm.png";
    id_files[IDR_AURA_CURSOR_MOVE] = L"common\\pointers\\move.png";
    id_files[IDR_AURA_CURSOR_NORTH_EAST_RESIZE] = L"common\\pointers\\top_right_corner.png";
    id_files[IDR_AURA_CURSOR_NORTH_EAST_SOUTH_WEST_RESIZE] = L"common\\pointers\\top_right_corner.png";
    id_files[IDR_AURA_CURSOR_NORTH_RESIZE] = L"common\\pointers\\sb_v_double_arrow.png";
    id_files[IDR_AURA_CURSOR_NORTH_SOUTH_RESIZE] = L"common\\pointers\\sb_v_double_arrow.png";
    id_files[IDR_AURA_CURSOR_NORTH_WEST_RESIZE] = L"common\\pointers\\top_left_corner.png";
    id_files[IDR_AURA_CURSOR_NORTH_WEST_SOUTH_EAST_RESIZE] = L"common\\pointers\\top_left_corner.png";
    id_files[IDR_AURA_CURSOR_NO_DROP] = L"common\\pointers\\nodrop.png";
    id_files[IDR_AURA_CURSOR_PTR] = L"common\\pointers\\left_ptr.png";
    id_files[IDR_AURA_CURSOR_ROW_RESIZE] = L"common\\pointers\\sb_v_double_arrow.png";
    id_files[IDR_AURA_CURSOR_SOUTH_EAST_RESIZE] = L"common\\pointers\\top_left_corner.png";
    id_files[IDR_AURA_CURSOR_SOUTH_RESIZE] = L"common\\pointers\\sb_v_double_arrow.png";
    id_files[IDR_AURA_CURSOR_SOUTH_WEST_RESIZE] = L"common\\pointers\\top_right_corner.png";
    id_files[IDR_AURA_CURSOR_WEST_RESIZE] = L"common\\pointers\\sb_h_double_arrow.png";
    id_files[IDR_AURA_CURSOR_XTERM_HORIZ] = L"common\\pointers\\xterm_horiz.png";
    id_files[IDR_AURA_CURSOR_ZOOM_IN] = L"common\\pointers\\zoom_in.png";
    id_files[IDR_AURA_CURSOR_ZOOM_OUT] = L"common\\pointers\\zoom_out.png";
    id_files[IDR_AURA_CURSOR_GRAB] = L"common\\pointers\\fleur.png";
    id_files[IDR_AURA_CURSOR_GRABBING] = L"common\\pointers\\hand3.png";
    id_files[IDR_AURA_SHADOW_ACTIVE_BOTTOM] = L"common\\window_shadow_active_bottom.png";
    id_files[IDR_AURA_SHADOW_ACTIVE_BOTTOM_LEFT] = L"common\\window_shadow_active_bottom_left.png";
    id_files[IDR_AURA_SHADOW_ACTIVE_BOTTOM_RIGHT] = L"common\\window_shadow_active_bottom_right.png";
    id_files[IDR_AURA_SHADOW_ACTIVE_LEFT] = L"common\\window_shadow_active_left.png";
    id_files[IDR_AURA_SHADOW_ACTIVE_RIGHT] = L"common\\window_shadow_active_right.png";
    id_files[IDR_AURA_SHADOW_ACTIVE_TOP] = L"common\\window_shadow_active_top.png";
    id_files[IDR_AURA_SHADOW_ACTIVE_TOP_LEFT] = L"common\\window_shadow_active_top_left.png";
    id_files[IDR_AURA_SHADOW_ACTIVE_TOP_RIGHT] = L"common\\window_shadow_active_top_right.png";
    id_files[IDR_AURA_SHADOW_INACTIVE_BOTTOM] = L"common\\window_shadow_inactive_bottom.png";
    id_files[IDR_AURA_SHADOW_INACTIVE_BOTTOM_LEFT] = L"common\\window_shadow_inactive_bottom_left.png";
    id_files[IDR_AURA_SHADOW_INACTIVE_BOTTOM_RIGHT] = L"common\\window_shadow_inactive_bottom_right.png";
    id_files[IDR_AURA_SHADOW_INACTIVE_LEFT] = L"common\\window_shadow_inactive_left.png";
    id_files[IDR_AURA_SHADOW_INACTIVE_RIGHT] = L"common\\window_shadow_inactive_right.png";
    id_files[IDR_AURA_SHADOW_INACTIVE_TOP] = L"common\\window_shadow_inactive_top.png";
    id_files[IDR_AURA_SHADOW_INACTIVE_TOP_LEFT] = L"common\\window_shadow_inactive_top_left.png";
    id_files[IDR_AURA_SHADOW_INACTIVE_TOP_RIGHT] = L"common\\window_shadow_inactive_top_right.png";
    id_files[IDR_BROWSER_ACTION_BADGE_CENTER] = L"common\\browser_action_badge_center.png";
    id_files[IDR_BROWSER_ACTION_BADGE_LEFT] = L"common\\browser_action_badge_left.png";
    id_files[IDR_BROWSER_ACTION_BADGE_RIGHT] = L"common\\browser_action_badge_right.png";
    id_files[IDR_BUBBLE_B] = L"bubble_bottom.png";
    id_files[IDR_BUBBLE_BL] = L"bubble_bottom_left.png";
    id_files[IDR_BUBBLE_BR] = L"bubble_bottom_right.png";
    id_files[IDR_BUBBLE_B_ARROW] = L"bubble_pointer_bottom.png";
    id_files[IDR_BUBBLE_L] = L"bubble_left.png";
    id_files[IDR_BUBBLE_L_ARROW] = L"bubble_pointer_left.png";
    id_files[IDR_BUBBLE_R] = L"bubble_right.png";
    id_files[IDR_BUBBLE_R_ARROW] = L"bubble_pointer_right.png";
    id_files[IDR_BUBBLE_SHADOW_B] = L"bubble_shadow_bottom.png";
    id_files[IDR_BUBBLE_SHADOW_BL] = L"bubble_shadow_bottom_left.png";
    id_files[IDR_BUBBLE_SHADOW_BR] = L"bubble_shadow_bottom_right.png";
    id_files[IDR_BUBBLE_SHADOW_L] = L"bubble_shadow_left.png";
    id_files[IDR_BUBBLE_SHADOW_R] = L"bubble_shadow_right.png";
    id_files[IDR_BUBBLE_SHADOW_T] = L"bubble_shadow_top.png";
    id_files[IDR_BUBBLE_SHADOW_TL] = L"bubble_shadow_top_left.png";
    id_files[IDR_BUBBLE_SHADOW_TR] = L"bubble_shadow_top_right.png";
    id_files[IDR_BUBBLE_T] = L"bubble_top.png";
    id_files[IDR_BUBBLE_TL] = L"bubble_top_left.png";
    id_files[IDR_BUBBLE_TR] = L"bubble_top_right.png";
    id_files[IDR_BUBBLE_T_ARROW] = L"bubble_pointer_top.png";

    /*id_files[IDR_BUBBLE_SHADOW_1_B] = L"search_tip_bar_border_B.png";
    id_files[IDR_BUBBLE_SHADOW_1_BL] = L"search_tip_bar_border_BL.png";
    id_files[IDR_BUBBLE_SHADOW_1_BR] = L"search_tip_bar_border_br.png";
    id_files[IDR_BUBBLE_SHADOW_1_L] = L"search_tip_bar_border_l.png";
    id_files[IDR_BUBBLE_SHADOW_1_R] = L"search_tip_bar_border_r.png";
    id_files[IDR_BUBBLE_SHADOW_1_T] = L"search_tip_bar_border_t.png";
    id_files[IDR_BUBBLE_SHADOW_1_TL] = L"search_tip_bar_border_tl.png";
    id_files[IDR_BUBBLE_SHADOW_1_TR] = L"search_tip_bar_border_tr.png";
    id_files[IDR_BUBBLE_TRANSPARENT_BG] = L"trans_bg.png";*/

    id_files[IDR_BUTTON_DISABLED] = L"common\\button_inactive.png";
    id_files[IDR_BUTTON_FOCUSED_HOVER] = L"common\\button_focused_hover.png";
    id_files[IDR_BUTTON_FOCUSED_NORMAL] = L"common\\button_focused.png";
    id_files[IDR_BUTTON_FOCUSED_PRESSED] = L"common\\button_focused_pressed.png";
    id_files[IDR_BUTTON_HOVER] = L"common\\button_hover.png";
    id_files[IDR_BUTTON_NORMAL] = L"common\\button.png";
    id_files[IDR_BUTTON_PRESSED] = L"common\\button_pressed.png";
    id_files[IDR_BUY_WITH_GOOGLE_BUTTON] = L"common\\buy_with_google_button.png";
    id_files[IDR_BUY_WITH_GOOGLE_BUTTON_H] = L"common\\buy_with_google_button_hover.png";
    id_files[IDR_BUY_WITH_GOOGLE_BUTTON_P] = L"common\\buy_with_google_button_pressed.png";
    id_files[IDR_BLUE_BUTTON_DISABLED] = L"common\\blue_button_inactive.png";
    id_files[IDR_BLUE_BUTTON_FOCUSED_HOVER] = L"common\\blue_button_focused_hover.png";
    id_files[IDR_BLUE_BUTTON_FOCUSED_NORMAL] = L"common\\blue_button_focused.png";
    id_files[IDR_BLUE_BUTTON_FOCUSED_PRESSED] = L"common\\blue_button_focused_pressed.png";
    id_files[IDR_BLUE_BUTTON_HOVER] = L"common\\blue_button_hover.png";
    id_files[IDR_BLUE_BUTTON_NORMAL] = L"common\\blue_button.png";
    id_files[IDR_BLUE_BUTTON_PRESSED] = L"common\\blue_button_pressed.png";
    id_files[IDR_CHECKBOX] = L"common\\checkbox.png";
    id_files[IDR_CHECKBOX_CHECKED] = L"common\\checkbox_checked.png";
    id_files[IDR_CHECKBOX_CHECKED_DISABLED] = L"common\\checkbox_checked_inactive.png";
    id_files[IDR_CHECKBOX_CHECKED_HOVER] = L"common\\checkbox_checked_hover.png";
    id_files[IDR_CHECKBOX_CHECKED_PRESSED] = L"common\\checkbox_checked_pressed.png";
    id_files[IDR_CHECKBOX_DISABLED] = L"common\\checkbox_inactive.png";
    id_files[IDR_CHECKBOX_FOCUSED] = L"common\\checkbox_focused.png";
    id_files[IDR_CHECKBOX_FOCUSED_CHECKED] = L"common\\checkbox_focused_checked.png";
    id_files[IDR_CHECKBOX_FOCUSED_CHECKED_HOVER] = L"common\\checkbox_focused_checked_hover.png";
    id_files[IDR_CHECKBOX_FOCUSED_CHECKED_PRESSED] = L"common\\checkbox_focused_checked_pressed.png";
    id_files[IDR_CHECKBOX_FOCUSED_HOVER] = L"common\\checkbox_focused_hover.png";
    id_files[IDR_CHECKBOX_FOCUSED_PRESSED] = L"common\\checkbox_focused_pressed.png";
    id_files[IDR_CHECKBOX_HOVER] = L"common\\checkbox_hover.png";
    id_files[IDR_CHECKBOX_PRESSED] = L"common\\checkbox_pressed.png";
    id_files[IDR_CHECKMARK] = L"common\\checkmark.png";
    id_files[IDR_RADIO] = L"common\\radio.png";
    id_files[IDR_RADIO_CHECKED] = L"common\\radio_checked.png";
    id_files[IDR_RADIO_CHECKED_DISABLED] = L"common\\radio_checked_inactive.png";
    id_files[IDR_RADIO_CHECKED_HOVER] = L"common\\radio_checked_hover.png";
    id_files[IDR_RADIO_CHECKED_PRESSED] = L"common\\radio_checked_pressed.png";
    id_files[IDR_RADIO_DISABLED] = L"common\\radio_inactive.png";
    id_files[IDR_RADIO_FOCUSED] = L"common\\radio_focused.png";
    id_files[IDR_RADIO_FOCUSED_CHECKED] = L"common\\radio_focused_checked.png";
    id_files[IDR_RADIO_FOCUSED_CHECKED_HOVER] = L"common\\radio_focused_checked_hover.png";
    id_files[IDR_RADIO_FOCUSED_CHECKED_PRESSED] = L"common\\radio_focused_checked_pressed.png";
    id_files[IDR_RADIO_FOCUSED_HOVER] = L"common\\radio_focused_hover.png";
    id_files[IDR_RADIO_FOCUSED_PRESSED] = L"common\\radio_focused_pressed.png";
    id_files[IDR_RADIO_HOVER] = L"common\\radio_hover.png";
    id_files[IDR_RADIO_PRESSED] = L"common\\radio_pressed.png";
    id_files[IDR_TEXT_SELECTION_HANDLE] = L"common\\text_selection_handle_small.png";
    id_files[IDR_CLOSE] = L"linux\\linux_close.png";
    id_files[IDR_CLOSE] = L"close.png";
    id_files[IDR_CLOSE_2] = L"close_2.png";
    id_files[IDR_CLOSE_2_H] = L"close_2_hover.png";
    id_files[IDR_CLOSE_2_MASK] = L"close_2_mask.png";
    id_files[IDR_CLOSE_2_P] = L"close_2_pressed.png";
    id_files[IDR_CLOSE_DIALOG] = L"close_dialog.png";
    id_files[IDR_CLOSE_DIALOG_H] = L"close_dialog_hover.png";
    id_files[IDR_CLOSE_DIALOG_P] = L"close_dialog_pressed.png";
    id_files[IDR_CLOSE_H] = L"linux\\linux_close_hover.png";
    id_files[IDR_CLOSE_P] = L"linux\\linux_close_pressed.png";
    id_files[IDR_CLOSE_H] = L"close_hover.png";
    id_files[IDR_CLOSE_P] = L"close_pressed.png";
    id_files[IDR_CLOSE_SA] = L"close_sa.png";
    id_files[IDR_CLOSE_SA_H] = L"close_sa_hover.png";
    id_files[IDR_CLOSE_SA_P] = L"close_sa_pressed.png";
    id_files[IDR_CONTENT_BOTTOM_CENTER] = L"content_bottom_center.png";
    id_files[IDR_CONTENT_BOTTOM_LEFT_CORNER] = L"content_bottom_left_corner.png";
    id_files[IDR_CONTENT_BOTTOM_RIGHT_CORNER] = L"content_bottom_right_corner.png";
    id_files[IDR_CONTENT_LEFT_SIDE] = L"content_left_side.png";
    id_files[IDR_CONTENT_RIGHT_SIDE] = L"content_right_side.png";
    id_files[IDR_DEFAULT_FAVICON] = L"common\\default_favicon.png";
    id_files[IDR_DEFAULT_FAVICON_32] = L"common\\default_favicon_32.png";
    id_files[IDR_DEFAULT_FAVICON_64] = L"common\\default_favicon_64.png";
    id_files[IDR_FOLDER_CLOSED] = L"common\\folder_closed.png";
    id_files[IDR_FOLDER_CLOSED_RTL] = L"common\\folder_closed_rtl.png";
    id_files[IDR_FOLDER_OPEN] = L"common\\folder_open.png";
    id_files[IDR_FOLDER_OPEN_RTL] = L"common\\folder_open_rtl.png";
    id_files[IDR_FRAME] = L"frame_default.png";
    id_files[IDR_FRAME_APP_PANEL] = L"frame_app_panel_default.png";
    id_files[IDR_FRAME_INACTIVE] = L"frame_default_inactive.png";
    id_files[IDR_MAXIMIZE] = L"linux\\linux_maximize.png";
    id_files[IDR_MAXIMIZE_H] = L"linux\\linux_maximize_hover.png";
    id_files[IDR_MAXIMIZE_P] = L"linux\\linux_maximize_pressed.png";
    id_files[IDR_MAXIMIZE] = L"maximize.png";
    id_files[IDR_MAXIMIZE_H] = L"maximize_hover.png";
    id_files[IDR_MAXIMIZE_P] = L"maximize_pressed.png";
    id_files[IDR_MENU_HIERARCHY_ARROW] = L"common\\menu_hierarchy_arrow.png";
    id_files[IDR_MENU_HIERARCHY_ARROW_DARK_BACKGROUND] = L"common\\menu_hierarchy_arrow_white.png";
    //id_files[IDR_MENU_HIERARCHY_ARROW] = L"mac\\menu_hierarchy_arrow.png";
    id_files[IDR_MENU_CHECK] = L"cros\\menu_check.png";
    id_files[IDR_MENU_CHECK_CHECKED] = L"common\\menu_check.png";
    id_files[IDR_MENU_RADIO_EMPTY] = L"common\\menu_radio_empty.png";
    id_files[IDR_MENU_RADIO_SELECTED] = L"common\\menu_radio_selected.png";
    id_files[IDR_SLIDER_ACTIVE_LEFT] = L"slider_left_active.png";
    id_files[IDR_SLIDER_ACTIVE_RIGHT] = L"slider_right_active.png";
    id_files[IDR_SLIDER_ACTIVE_CENTER] = L"slider_center_active.png";
    id_files[IDR_SLIDER_DISABLED_LEFT] = L"slider_left_disabled.png";
    id_files[IDR_SLIDER_DISABLED_RIGHT] = L"slider_right_disabled.png";
    id_files[IDR_SLIDER_DISABLED_CENTER] = L"slider_center_disabled.png";
    id_files[IDR_SLIDER_PRESSED_LEFT] = L"slider_left_pressed.png";
    id_files[IDR_SLIDER_PRESSED_RIGHT] = L"slider_right_pressed.png";
    id_files[IDR_SLIDER_PRESSED_CENTER] = L"slider_center_pressed.png";
    id_files[IDR_SLIDER_ACTIVE_THUMB] = L"slider_thumb.png";
    id_files[IDR_SLIDER_DISABLED_THUMB] = L"slider_thumb_disabled.png";
    id_files[IDR_MENU_DROPARROW] = L"cros\\menu_droparrow.png";
    id_files[IDR_MESSAGE_CLOSE] = L"common\\message_close.png";
    id_files[IDR_MINIMIZE] = L"linux\\linux_minimize.png";
    id_files[IDR_MINIMIZE_H] = L"linux\\linux_minimize_hover.png";
    id_files[IDR_MINIMIZE_P] = L"linux\\linux_minimize_pressed.png";
    id_files[IDR_MINIMIZE] = L"minimize.png";
    id_files[IDR_MINIMIZE_H] = L"minimize_hover.png";
    id_files[IDR_MINIMIZE_P] = L"minimize_pressed.png";
    id_files[IDR_NOTIFICATION_ARROW] = L"common\\notification_arrow.png";
    id_files[IDR_NOTIFICATION_ARROW_HOVER] = L"common\\notification_arrow_hover.png";
    id_files[IDR_NOTIFICATION_ARROW_PRESSED] = L"common\\notification_arrow_pressed.png";
    id_files[IDR_NOTIFICATION_CLEAR_ALL] = L"common\\notification_clear_all.png";
    id_files[IDR_NOTIFICATION_CLEAR_ALL_DISABLED] = L"common\\notification_clear_all_disabled.png";
    id_files[IDR_NOTIFICATION_CLEAR_ALL_HOVER] = L"common\\notification_clear_all_hover.png";
    id_files[IDR_NOTIFICATION_CLEAR_ALL_PRESSED] = L"common\\notification_clear_all_pressed.png";
    id_files[IDR_NOTIFICATION_CLOSE] = L"win\\notification_close.png";
    id_files[IDR_NOTIFICATION_CLOSE_HOVER] = L"win\\notification_close_hover.png";
    id_files[IDR_NOTIFICATION_CLOSE_PRESSED] = L"win\\notification_close_pressed.png";
    id_files[IDR_NOTIFICATION_CLOSE] = L"common\\notification_close.png";
    id_files[IDR_NOTIFICATION_CLOSE_HOVER] = L"common\\notification_close_hover.png";
    id_files[IDR_NOTIFICATION_CLOSE_PRESSED] = L"common\\notification_close_pressed.png";
    id_files[IDR_NOTIFICATION_EXPAND] = L"common\\notification_expand.png";
    id_files[IDR_NOTIFICATION_EXPAND_HOVER] = L"common\\notification_expand_hover.png";
    id_files[IDR_NOTIFICATION_EXPAND_PRESSED] = L"common\\notification_expand_pressed.png";
    id_files[IDR_NOTIFICATION_DO_NOT_DISTURB] = L"common\\notification_do_not_disturb.png";
    id_files[IDR_NOTIFICATION_DO_NOT_DISTURB_HOVER] = L"common\\notification_do_not_disturb_hover.png";
    id_files[IDR_NOTIFICATION_DO_NOT_DISTURB_PRESSED] = L"common\\notification_do_not_disturb_pressed.png";
    id_files[IDR_NOTIFICATION_SETTINGS] = L"common\\notification_settings.png";
    id_files[IDR_NOTIFICATION_SETTINGS_HOVER] = L"common\\notification_settings_hover.png";
    id_files[IDR_NOTIFICATION_SETTINGS_PRESSED] = L"common\\notification_settings_pressed.png";
    id_files[IDR_OAK] = L"oak.png";
    id_files[IDR_OOBE_ACTION_BOX_BUTTON_HOVER] = L"cros\\action_box_button_hover.png";
    id_files[IDR_OOBE_ACTION_BOX_BUTTON_NORMAL] = L"cros\\action_box_button_normal.png";
    id_files[IDR_OOBE_ACTION_BOX_BUTTON_PRESSED] = L"cros\\action_box_button_pressed.png";
    id_files[IDR_PANEL_TOP_LEFT_CORNER] = L"panel_top_left_corner.png";
    id_files[IDR_PANEL_TOP_RIGHT_CORNER] = L"panel_top_right_corner.png";
    id_files[IDR_PANEL_BOTTOM_LEFT_CORNER] = L"panel_bottom_left_corner.png";
    id_files[IDR_PANEL_BOTTOM_RIGHT_CORNER] = L"panel_bottom_right_corner.png";
    id_files[IDR_PROGRESS_BAR] = L"linux\\linux-progress-bar.png";
    id_files[IDR_PROGRESS_BORDER_LEFT] = L"linux\\linux-progress-border-left.png";
    id_files[IDR_PROGRESS_BORDER_RIGHT] = L"linux\\linux-progress-border-right.png";
    id_files[IDR_PROGRESS_VALUE] = L"linux\\linux-progress-value.png";
    id_files[IDR_PROGRESS_BAR] = L"linux\\linux-progress-bar.png";
    id_files[IDR_PROGRESS_BORDER_LEFT] = L"linux\\linux-progress-border-left.png";
    id_files[IDR_PROGRESS_BORDER_RIGHT] = L"linux\\linux-progress-border-right.png";
    id_files[IDR_PROGRESS_VALUE] = L"linux\\linux-progress-value.png";
    id_files[IDR_SCROLL_BASE_HORIZONTAL_CENTER_H] = L"cros\\aura_scrollbar_base_horizontal_hover_center.png";
    id_files[IDR_SCROLL_BASE_HORIZONTAL_LEFT_H] = L"cros\\aura_scrollbar_base_horizontal_hover_left.png";
    id_files[IDR_SCROLL_BASE_HORIZONTAL_RIGHT_H] = L"cros\\aura_scrollbar_base_horizontal_hover_right.png";
    id_files[IDR_SCROLL_BASE_VERTICAL_BOTTOM_H] = L"cros\\aura_scrollbar_base_vertical_hover_bottom.png";
    id_files[IDR_SCROLL_BASE_VERTICAL_CENTER_H] = L"cros\\aura_scrollbar_base_vertical_hover_center.png";
    id_files[IDR_SCROLL_BASE_VERTICAL_TOP_H] = L"cros\\aura_scrollbar_base_vertical_hover_top.png";
    id_files[IDR_SCROLL_THUMB_HORIZONTAL_CENTER] = L"cros\\aura_scrollbar_thumb_horizontal_normal_center.png";
    id_files[IDR_SCROLL_THUMB_HORIZONTAL_CENTER_H] = L"cros\\aura_scrollbar_thumb_horizontal_hover_center.png";
    id_files[IDR_SCROLL_THUMB_HORIZONTAL_CENTER_P] = L"cros\\aura_scrollbar_thumb_horizontal_pressed_center.png";
    id_files[IDR_SCROLL_THUMB_HORIZONTAL_LEFT] = L"cros\\aura_scrollbar_thumb_horizontal_normal_left.png";
    id_files[IDR_SCROLL_THUMB_HORIZONTAL_LEFT_H] = L"cros\\aura_scrollbar_thumb_horizontal_hover_left.png";
    id_files[IDR_SCROLL_THUMB_HORIZONTAL_LEFT_P] = L"cros\\aura_scrollbar_thumb_horizontal_pressed_left.png";
    id_files[IDR_SCROLL_THUMB_HORIZONTAL_RIGHT] = L"cros\\aura_scrollbar_thumb_horizontal_normal_right.png";
    id_files[IDR_SCROLL_THUMB_HORIZONTAL_RIGHT_H] = L"cros\\aura_scrollbar_thumb_horizontal_hover_right.png";
    id_files[IDR_SCROLL_THUMB_HORIZONTAL_RIGHT_P] = L"cros\\aura_scrollbar_thumb_horizontal_pressed_right.png";
    id_files[IDR_SCROLL_THUMB_VERTICAL_BOTTOM] = L"cros\\aura_scrollbar_thumb_vertical_normal_bottom.png";
    id_files[IDR_SCROLL_THUMB_VERTICAL_BOTTOM_H] = L"cros\\aura_scrollbar_thumb_vertical_hover_bottom.png";
    id_files[IDR_SCROLL_THUMB_VERTICAL_BOTTOM_P] = L"cros\\aura_scrollbar_thumb_vertical_pressed_bottom.png";
    id_files[IDR_SCROLL_THUMB_VERTICAL_CENTER] = L"cros\\aura_scrollbar_thumb_vertical_normal_center.png";
    id_files[IDR_SCROLL_THUMB_VERTICAL_CENTER_H] = L"cros\\aura_scrollbar_thumb_vertical_hover_center.png";
    id_files[IDR_SCROLL_THUMB_VERTICAL_CENTER_P] = L"cros\\aura_scrollbar_thumb_vertical_pressed_center.png";
    id_files[IDR_SCROLL_THUMB_VERTICAL_TOP] = L"cros\\aura_scrollbar_thumb_vertical_normal_top.png";
    id_files[IDR_SCROLL_THUMB_VERTICAL_TOP_H] = L"cros\\aura_scrollbar_thumb_vertical_hover_top.png";
    id_files[IDR_SCROLL_THUMB_VERTICAL_TOP_P] = L"cros\\aura_scrollbar_thumb_vertical_pressed_top.png";
    id_files[IDR_RESTORE] = L"linux\\linux_restore.png";
    id_files[IDR_RESTORE_H] = L"linux\\linux_restore_hover.png";
    id_files[IDR_RESTORE_P] = L"linux\\linux_restore_pressed.png";
    id_files[IDR_RESTORE] = L"restore.png";
    id_files[IDR_RESTORE_H] = L"restore_hover.png";
    id_files[IDR_RESTORE_P] = L"restore_pressed.png";
    id_files[IDR_TEXTBUTTON_HOVER_BOTTOM] = L"common\\textbutton_hover_bottom.png";
    id_files[IDR_TEXTBUTTON_HOVER_BOTTOM_LEFT] = L"common\\textbutton_hover_bottom_left.png";
    id_files[IDR_TEXTBUTTON_HOVER_BOTTOM_RIGHT] = L"common\\textbutton_hover_bottom_right.png";
    id_files[IDR_TEXTBUTTON_HOVER_CENTER] = L"common\\textbutton_hover_center.png";
    id_files[IDR_TEXTBUTTON_HOVER_LEFT] = L"common\\textbutton_hover_left.png";
    id_files[IDR_TEXTBUTTON_HOVER_RIGHT] = L"common\\textbutton_hover_right.png";
    id_files[IDR_TEXTBUTTON_HOVER_TOP] = L"common\\textbutton_hover_top.png";
    id_files[IDR_TEXTBUTTON_HOVER_TOP_LEFT] = L"common\\textbutton_hover_top_left.png";
    id_files[IDR_TEXTBUTTON_HOVER_TOP_RIGHT] = L"common\\textbutton_hover_top_right.png";
    id_files[IDR_TEXTBUTTON_PRESSED_BOTTOM] = L"common\\textbutton_pressed_bottom.png";
    id_files[IDR_TEXTBUTTON_PRESSED_BOTTOM_LEFT] = L"common\\textbutton_pressed_bottom_left.png";
    id_files[IDR_TEXTBUTTON_PRESSED_BOTTOM_RIGHT] = L"common\\textbutton_pressed_bottom_right.png";
    id_files[IDR_TEXTBUTTON_PRESSED_CENTER] = L"common\\textbutton_pressed_center.png";
    id_files[IDR_TEXTBUTTON_PRESSED_LEFT] = L"common\\textbutton_pressed_left.png";
    id_files[IDR_TEXTBUTTON_PRESSED_RIGHT] = L"common\\textbutton_pressed_right.png";
    id_files[IDR_TEXTBUTTON_PRESSED_TOP] = L"common\\textbutton_pressed_top.png";
    id_files[IDR_TEXTBUTTON_PRESSED_TOP_LEFT] = L"common\\textbutton_pressed_top_left.png";
    id_files[IDR_TEXTBUTTON_PRESSED_TOP_RIGHT] = L"common\\textbutton_pressed_top_right.png";
    id_files[IDR_THROBBER] = L"throbber.png";
    id_files[IDR_TRAY_ATTENTION] = L"mac\\notification_tray_attention.png";
    id_files[IDR_TRAY_ATTENTION_PRESSED] = L"mac\\notification_tray_attention_pressed.png";
    id_files[IDR_TRAY_DO_NOT_DISTURB_ATTENTION] = L"mac\\notification_tray_do_not_disturb_attention.png";
    id_files[IDR_TRAY_DO_NOT_DISTURB_ATTENTION_PRESSED] = L"mac\\notification_tray_do_not_disturb_attention_pressed.png";
    id_files[IDR_TRAY_DO_NOT_DISTURB_EMPTY] = L"mac\\notification_tray_do_not_disturb_empty.png";
    id_files[IDR_TRAY_DO_NOT_DISTURB_EMPTY_PRESSED] = L"mac\\notification_tray_do_not_disturb_empty_pressed.png";
    id_files[IDR_TRAY_EMPTY] = L"mac\\notification_tray_empty.png";
    id_files[IDR_TRAY_EMPTY_PRESSED] = L"mac\\notification_tray_empty_pressed.png";
    id_files[IDR_WINDOW_BOTTOM_CENTER] = L"common\\window_bottom_center.png";
    id_files[IDR_WINDOW_BOTTOM_LEFT_CORNER] = L"common\\window_bottom_left_corner.png";
    id_files[IDR_WINDOW_BOTTOM_RIGHT_CORNER] = L"common\\window_bottom_right_corner.png";
    id_files[IDR_WINDOW_LEFT_SIDE] = L"common\\window_left_side.png";
    id_files[IDR_WINDOW_RIGHT_SIDE] = L"common\\window_right_side.png";
    id_files[IDR_WINDOW_TOP_CENTER] = L"common\\window_top_center.png";
    id_files[IDR_WINDOW_TOP_LEFT_CORNER] = L"common\\window_top_left_corner.png";
    id_files[IDR_WINDOW_TOP_RIGHT_CORNER] = L"common\\window_top_right_corner.png";
    id_files[IDR_WINDOW_BUBBLE_SHADOW_BIG_BOTTOM] = L"common\\window_bubble_shadow_big_bottom.png";
    id_files[IDR_WINDOW_BUBBLE_SHADOW_BIG_BOTTOM_LEFT] = L"common\\window_bubble_shadow_big_bottom_left.png";
    id_files[IDR_WINDOW_BUBBLE_SHADOW_BIG_BOTTOM_RIGHT] = L"common\\window_bubble_shadow_big_bottom_right.png";
    id_files[IDR_WINDOW_BUBBLE_SHADOW_BIG_LEFT] = L"common\\window_bubble_shadow_big_left.png";
    id_files[IDR_WINDOW_BUBBLE_SHADOW_BIG_RIGHT] = L"common\\window_bubble_shadow_big_right.png";
    id_files[IDR_WINDOW_BUBBLE_SHADOW_BIG_TOP] = L"common\\window_bubble_shadow_big_top.png";
    id_files[IDR_WINDOW_BUBBLE_SHADOW_BIG_TOP_LEFT] = L"common\\window_bubble_shadow_big_top_left.png";
    id_files[IDR_WINDOW_BUBBLE_SHADOW_BIG_TOP_RIGHT] = L"common\\window_bubble_shadow_big_top_right.png";
    id_files[IDR_WINDOW_BUBBLE_SHADOW_SPIKE_BIG_BOTTOM] = L"common\\window_bubble_shadow_spike_big_bottom.png";
    id_files[IDR_WINDOW_BUBBLE_SHADOW_SPIKE_BIG_LEFT] = L"common\\window_bubble_shadow_spike_big_left.png";
    id_files[IDR_WINDOW_BUBBLE_SHADOW_SPIKE_BIG_RIGHT] = L"common\\window_bubble_shadow_spike_big_right.png";
    id_files[IDR_WINDOW_BUBBLE_SHADOW_SPIKE_BIG_TOP] = L"common\\window_bubble_shadow_spike_big_top.png";
    id_files[IDR_WINDOW_BUBBLE_SHADOW_SMALL_BOTTOM] = L"common\\window_bubble_shadow_small_bottom.png";
    id_files[IDR_WINDOW_BUBBLE_SHADOW_SMALL_BOTTOM_LEFT] = L"common\\window_bubble_shadow_small_bottom_left.png";
    id_files[IDR_WINDOW_BUBBLE_SHADOW_SMALL_BOTTOM_RIGHT] = L"common\\window_bubble_shadow_small_bottom_right.png";
    id_files[IDR_WINDOW_BUBBLE_SHADOW_SMALL_LEFT] = L"common\\window_bubble_shadow_small_left.png";
    id_files[IDR_WINDOW_BUBBLE_SHADOW_SMALL_RIGHT] = L"common\\window_bubble_shadow_small_right.png";
    id_files[IDR_WINDOW_BUBBLE_SHADOW_SMALL_TOP] = L"common\\window_bubble_shadow_small_top.png";
    id_files[IDR_WINDOW_BUBBLE_SHADOW_SMALL_TOP_LEFT] = L"common\\window_bubble_shadow_small_top_left.png";
    id_files[IDR_WINDOW_BUBBLE_SHADOW_SMALL_TOP_RIGHT] = L"common\\window_bubble_shadow_small_top_right.png";
    id_files[IDR_WINDOW_BUBBLE_SHADOW_SPIKE_SMALL_BOTTOM] = L"common\\window_bubble_shadow_spike_small_bottom.png";
    id_files[IDR_WINDOW_BUBBLE_SHADOW_SPIKE_SMALL_LEFT] = L"common\\window_bubble_shadow_spike_small_left.png";
    id_files[IDR_WINDOW_BUBBLE_SHADOW_SPIKE_SMALL_RIGHT] = L"common\\window_bubble_shadow_spike_small_right.png";
    id_files[IDR_WINDOW_BUBBLE_SHADOW_SPIKE_SMALL_TOP] = L"common\\window_bubble_shadow_spike_small_top.png";

    id_files[IDR_NEWUI_DIALOG_BG] = L"360se\\s7_Dl_BG1.png";
    id_files[IDR_NEWUI_BUTTON_MASK] = L"360se\\Button_BG1.png";
    id_files[IDR_NEWUI_IMAGE_BUTTON] = L"360se\\add_plugin_app.png";
    id_files[IDR_NEWUI_IMAGE_ICON] = L"360se\\xinlangweibo_icon.png";
    id_files[IDR_NEWUI_IMAGE_MAX] = L"360se\\s7_dl_max_1.png";
    id_files[IDR_NEWUI_IMAGE_MIN] = L"360se\\s7_dl_min_1.png";
    id_files[IDR_NEWUI_IMAGE_RESTORE] = L"360se\\s7_dl_restore_1.png";
    id_files[IDR_NEWUI_IMAGE_CLOSE] = L"360se\\s7_dl_close_1.png";

    id_files[IDR_NEWUI_FRAME_ALPHA] = L"360se\\whilt_bkg.png";
    id_files[IDR_NEWUI_FRAME_MAIN] = L"360se\\main.png";
    id_files[IDR_NEWUI_FRAME_SHADOW] = L"360se\\fringe_bkg.png";
  }
};

string16 GetImageFileNameById(int nid)
{
  ui_map::InitUiMap();
  std::map<int, string16>::iterator itr = id_files.find(nid);
  if(itr != id_files.end())
    return itr->second;
  return L"";
}