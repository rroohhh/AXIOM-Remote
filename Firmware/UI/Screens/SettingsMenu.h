#ifndef SETTINGSMENU_H
#define SETTINGSMENU_H

#include "IMenu.h"
#include "../Painter.h"
#include "../Widgets/MenuItem.h"
#include <vector>

//#include "../Widgets/MainPageButton.h"

#include "../ButtonDefinitions.h"

#include "../../../Bootloader/Periphery/USB/IUSBDevice.h"

class SettingsMenu : public IMenu
{
    IUSBDevice* _usbDevice;

    char* _label;
    std::vector<MenuItem> _menuItems;
    uint8_t _menuSelectionIndex;
    Color565 _backgroundColor;

  public:
    explicit SettingsMenu(IUSBDevice* cdcDevice)
    {
        MenuItem item1 = new MenuItem();
        item1.SetLabel("Test Item 1");
        _menuItems.push_back(item1);

        MenuItem item2 = new MenuItem();
        item2.SetDisabled(true);
        item2.SetLabel("Test Item 2");
        _menuItems.push_back(item2);

        MenuItem item3 = new MenuItem();
        item3.SetLabel("Test Item 3");
        _menuItems.push_back(item3);

        /*
                _menuButton.SetHandler(&MenuButtonHandler);

                _analogGainButton.SetHandler(&AnalogGainButtonHandler);
                _digitalGainButton.SetHandler(&DigitalGainButtonHandler);*/
    }

    void SetLabel(char* value)
    {
        _label = value;
    }

    char* GetLabel()
    {
        return _label;
    }

  protected:
    void Draw(Painter* painter) override
    {
        for (int8_t i = 0; i < (int8_t)_menuItems.size(); i++)
        {
            _menuItems.at(i).Draw(painter);
        }

        /*
        // clear the screen
        painter->DrawFillRectangle(0, 0, FRAMEBUFFER_WIDTH, FRAMEBUFFER_HEIGHT, menu_background_color);

        // draw header background
        painter->DrawFillRectangle(0, FRAMEBUFFER_HEIGHT - 28, FRAMEBUFFER_WIDTH, 28, menu_item_color);

        // draw header bread crumbs
        draw_string(5, FRAMEBUFFER_HEIGHT - 22, menu_breadcrumbs, menu_text_color, menu_text_color, _FreeSans9pt7b,
                    TEXT_ALIGN_LEFT, 0);

        // two header separation lines
        draw_line(0, FRAMEBUFFER_HEIGHT - 29, FRAMEBUFFER_WIDTH - 1, FRAMEBUFFER_HEIGHT - 29, menu_selected_text_color);

        draw_line(0, FRAMEBUFFER_HEIGHT - 30, FRAMEBUFFER_WIDTH - 1, FRAMEBUFFER_HEIGHT - 30, menu_background_color);

        // Side Icons

        // Side Icons Background
        fill_rect(0, 0, 30, FRAMEBUFFER_HEIGHT - 30, menu_item_color);

        // Home Icon
        if (home_icon_highlighted)
        {
            drawRGBBitmap(0, 158, (uint16_t*)(home_icon_highlight.pixel_data), home_icon_highlight.width,
                          home_icon_highlight.height);
        } else
        {
            drawRGBBitmap(0, 158, (uint16_t*)(home_icon.pixel_data), home_icon.width, home_icon.height);
        }

        // Back Icon
        if (back_icon_highlighted)
        {
            drawRGBBitmap(0, 108, (uint16_t*)(back_icon_highlight.pixel_data), back_icon_highlight.width,
                          back_icon_highlight.height);
        } else
        {
            drawRGBBitmap(0, 108, (uint16_t*)(back_icon.pixel_data), back_icon.width, back_icon.height);
        }

        // draw menu items
        uint8_t a;
        for (a = 0; a < main_menu_count; a++)
        {
            if (main_menu[a].menu_id == current_menu)
            {
                uint8_t i;

                // this is the index of the 7 menu items drawn on screen currently
                int8_t display_selection_index = main_menu[a].menu_selection_index - menu_offset;

                // the _menu_offset is added to the item index and defines which item is the first one shown on screen

                // scrolling up from the first item
                if (display_selection_index < 0)
                {
                    menu_offset -= 1;
                }

                // scrolling down from the last item
                if (display_selection_index >= 7)
                {
                    menu_offset += 1;
                }

                // only up to 7 menu items fit on screen at once
                int menu_items_count = main_menu[a].menu_items_count;
                menu_items_count = limit_range(menu_items_count, 0, 7);

                // draw up to 7 menu items
                for (i = 0; i < menu_items_count; i++)
                {
                    draw_menu_item(30, (FRAMEBUFFER_HEIGHT - 29 - 30) - i * 30, a, i + menu_offset);
                }

                // draw scroll bar indicator only if there are 7 or more menu items
                if (menu_items_count == 7)
                {
                    draw_scroll_indicator(menu_items_count, main_menu[a].menu_items_count);
                }

                // draw parameter menu
                if (parameter_menu_active != 0)
                {
                    // the drawing coordinates in this case are provided as top right corner of the menu item
                    // that triggers the parameter menu
                    // the width depends on the text length of the options
                    // the y coordinate may be shifted up or down if the choices would end up off screen
                    uint16_t offset = (FRAMEBUFFER_TOP - 30) - (parameter_menu_active - menu_offset) * 30 - 2;

                    if (menu_items_count == 7)
                    {
                        // if there is a scrollbar
                        draw_parameter_menu(FRAMEBUFFER_RIGHT - 16, offset, a, parameter_menu_active);
                    } else
                    {
                        // if there is no scrollbar
                        draw_parameter_menu(FRAMEBUFFER_RIGHT, offset, a, parameter_menu_active);
                    }
                }
            }
        }
        */
    }

    void Update(Button button) override
    {
    }
};

#endif // SETTINGSMENU_H