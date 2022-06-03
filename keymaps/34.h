// Local Variables:
// compile-command: "cd ~/github_forks/zmk/; source .venv/bin/activate; cd app/; west build -p -d build/34 --board ferris_rev02 -- -DZMK_CONFIG=$HOME/github_repos/zmk-config/keymaps/"
// End:
/*
 * Shared 34 key keymap.
 *
 * On my linux laptop:
 * - AT = Speech mark.
 * - DQT = Ampersand.
 * - LS(N3) = GBP.
 * - PIPE = Tilda.
 * - BSLH/NON_US_HASH = hash.
 */

#include <behaviors.dtsi>
#include <dt-bindings/zmk/keys.h>
#include <dt-bindings/zmk/bt.h>

#define DEFAULT 0
#define COLEMAK_L 1  // Colemak Mod-DH: https://colemakmods.github.io/mod-dh/
#define NAV_L 2
#define NUM_L 3
#define SYM_L 4

// Using layer taps on thumbs, having quick tap as well helps w/ repeating space/backspace
&lt { quick_tap_ms = <200>; };

/ {  // https://zmk.dev/docs/features/combos
    combos {
        compatible = "zmk,combos";
        combo_esc {
            timeout-ms = <50>;
            key-positions = <0 1>;
            bindings = <&kp ESC>;
        };
        combo_speech_mark {
            timeout-ms = <50>;
            key-positions = <2 3>;
            bindings = <&kp AT>;
        };
        combo_del {
            timeout-ms = <50>;
            key-positions = <20 21>;
            bindings = <&kp DEL>;
        };
        combo_tab {
            timeout-ms = <50>;
            key-positions = <22 23>;
            bindings = <&kp TAB>;
        };
        combo_underscore {
            timeout-ms = <50>;
            key-positions = <26 27>;
            bindings = <&kp UNDER>;
        };
    };
};

/ {
    behaviors {
        hm: homerow_mods {
            compatible = "zmk,behavior-hold-tap";
            label = "homerow mods";
            #binding-cells = <2>;
            tapping_term_ms = <200>;
            flavor = "tap-preferred";
            bindings = <&kp>, <&kp>;
        };
    };

    keymap {
        compatible = "zmk,keymap";

        default_layer {
            bindings = <
                &kp Q      &kp W      &kp E       &kp R           &kp T               &kp Y            &kp U          &kp I       &kp O       &kp P
                &hm LGUI A &hm LSHFT S &hm LALT D &hm LCTRL F     &hm RALT G          &hm RALT H       &hm RCTRL J    &hm LALT K  &hm RSHFT L &hm LGUI SEMI
                &kp Z      &kp X      &kp C       &kp V           &kp B               &kp N            &kp M          &kp COMMA   &kp DOT     &kp FSLH
                                                  &mt LSHFT BSPC  &lt SYM_L SPACE     &lt NUM_L SPACE  &lt NAV_L ENTER
            >;
        };

        colemak_layer {
            bindings = <
                &kp Q      &kp W      &kp F       &kp P           &kp B               &kp J            &kp L          &kp U       &kp Y       &kp SEMI
                &hm LGUI A &hm LSHFT R &hm LALT S &hm LCTRL T     &hm RALT D          &hm RALT H       &hm RCTRL N    &hm LALT E  &hm RSHFT I &hm LGUI O
                &kp Z      &kp X      &kp C       &kp V           &kp B               &kp K            &kp M          &kp COMMA   &kp DOT     &kp FSLH
                                                  &mt LSHFT BSPC  &lt SYM_L SPACE     &lt NUM_L SPACE  &lt NAV_L ENTER
            >;
        };

        nav_layer {
            bindings = <
                &trans   &trans   &trans           &trans        &trans       &trans      &kp PG_UP      &kp UP        &kp PG_DN  &kp DEL
                &trans   &trans   &trans           &trans        &trans       &kp HOME    &kp LEFT       &kp DOWN      &kp RIGHT  &kp END
                &trans   &trans   &to COLEMAK_L    &to DEFAULT   &trans       &kp C_MUTE  &kp C_VOL_DN   &kp C_VOL_UP  &kp INS    &kp PSCRN
                                                   &trans        &trans       &trans      &trans
            >;
        };

        num_layer {
            bindings = <
                &kp EXCL  &kp AT   &kp LS(N3)  &kp DLLR  &kp PRCNT       &kp CARET   &kp AMPS   &kp STAR    &kp LPAR   &kp RPAR
                &kp N1    &kp N2   &kp N3      &kp N4    &kp N5          &kp N6      &kp N7     &kp N8      &kp N9     &kp N0
                &kp F1    &kp F2   &kp F3      &kp F4    &kp F5          &kp F6      &kp F7     &kp F8      &kp DOT    &kp F12
                                               &trans    &trans          &trans      &trans
            >;
        };

        sym_layer {
            bindings = <
                &kp EXCL   &kp AT    &kp LS(N3)  &kp DLLR         &kp PRCNT       &kp CARET        &kp AMPS   &kp STAR   &kp LPAR   &kp RPAR
                &kp LBRC   &kp LBKT  &kp LPAR    &kp MINUS        &kp GRAVE       &kp NON_US_HASH  &kp UNDER  &kp RPAR   &kp RBKT   &kp RBRC
                &kp DQT    &kp PLUS  &kp PIPE2   &kp NON_US_BSLH  &kp SQT         &kp PIPE         &kp FSLH   &kp EQUAL  &kp QMARK  &kp FSLH
                                                 &trans           &trans          &trans           &trans
            >;
        };
    };
};
