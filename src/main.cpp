#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_core.h>
#include <bn_keypad.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_items_dot.h>
#include <bn_log.h>
#include <bn_vector.h>

int main()
{
    bn::core::init();
    bn::backdrop::set_color(bn::color(20, 20, 31));
    bn::sprite_ptr myCircle = bn::sprite_items::dot.create_sprite(20, 50);
    bn::sprite_ptr myCircle1 = bn::sprite_items::dot.create_sprite(40, 50);

    bn::vector<bn::sprite_ptr, 20> circles = {};
    bn::vector<bn::sprite_ptr, 20> circles2 = {};
    for (int x = -60; x <= 60; x += 10)
    {
        BN_LOG("x value", x);
        circles.push_back(bn::sprite_items::dot.create_sprite(x, 40));
        circles2.push_back(bn::sprite_items::dot.create_sprite(x, 20));
    }
    int aRed = 31;
    int aGreen = 10;
    int aBlue = 20;

    int bRed = 10;
    int bGreen = 20;
    int bBlue = 31;

    while (true)
    {
        if (!bn::keypad::a_held() && !bn::keypad::b_held())
        {

            bn::backdrop::set_color(bn::color(20, 20, 31));
        }
        if (bn::keypad::a_held() && bn::keypad::b_held())
        {

            bn::backdrop::set_color(bn::color(aRed - bRed, bGreen - aGreen, bBlue - aBlue));
        }
        if (bn::keypad::a_held() && !bn::keypad::b_held())
        {

            bn::backdrop::set_color(bn::color(aRed, aGreen, aBlue));
        }
        if (bn::keypad::b_held() && !bn::keypad::a_held())
        {

            bn::backdrop::set_color(bn::color(bRed, bGreen, bBlue));
        }
        bn::core::update();
    }
}