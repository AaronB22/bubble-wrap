#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_core.h>
#include <bn_keypad.h>

int main()
{
    bn::core::init();
    bn::backdrop::set_color(bn::color(20, 20, 31));

    int aRed=31;
    int aGreen=10;
    int aBlue= 20;

    int bRed=10;
    int bGreen=20;
    int bBlue= 31;

    while (true)
    {
        if(!bn::keypad::a_held() && !bn::keypad::b_held()){
             bn::backdrop::set_color(bn::color(20, 20, 31));
        }
        if(bn::keypad::any_held() && bn::keypad::b_held()){
            bn::backdrop::set_color(bn::color(aRed-bRed,bGreen-aGreen,bBlue-aBlue));
        }
        if (bn::keypad::a_held()&& !bn::keypad::b_held())
        {
            bn::backdrop::set_color(bn::color(aRed, aGreen, aBlue));
        }
        if (bn::keypad::b_held()&& !bn::keypad::a_held())
        {
            bn::backdrop::set_color(bn::color(bRed, bGreen, bBlue));
        }
        bn::core::update();
    }
}