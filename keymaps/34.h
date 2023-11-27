// Local Variables:
// compile-command: "cd ..; make build_all_34"
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
#include <dt-bindings/zmk/outputs.h>


#define DEFAULT 0
#define MAC_L 1
#define COLEMAK_L 2  /* Colemak Mod-DH: https://colemakmods.github.io/mod-dh/ */
#define HDG_L 3  /* HandsDown-Gold: https://sites.google.com/alanreiser.com/handsdown/home/hands-down-neu#h.8i2msuo3butx */
#define HDG_MAC_L 4
#define GAME_L 5
#define NAV_L 6
#define NUM_L 7
#define NUM_MAC_L 8
#define SYM_L 9
#define SYM_MAC_L 10
#define ZMK_L 11

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
    combo_del {
      timeout-ms = <50>;
      key-positions = <20 21>;
      bindings = <&kp DEL>;
    };
    combo_tab {
      timeout-ms = <50>;
      key-positions = <21 23>;
      bindings = <&kp TAB>;
    };
    combo_underscore {
      timeout-ms = <50>;
      key-positions = <26 28>;
      bindings = <&kp UNDER>;
    };

    // HandsDown Gold
    combo_z {
      timeout-ms = <50>;
      key-positions = <20 23>;  /* Should be `0 1` but mimicking `Q`*/
      bindings = <&kp Z>;
    };
    combo_q {
      timeout-ms = <50>;
      key-positions = <26 29>;
      bindings = <&kp Q>;
    };

    // Brackets
    combo_left_curly_bracket {
      timeout-ms = <50>;
      key-positions = <2 3>;
      bindings = <&kp LBRC>;  // {
    };
    combo_left_parenthesis {
      timeout-ms = <50>;
      key-positions = <12 13>;
      bindings = <&kp LPAR>;  // (
    };
    combo_left_square_bracket {
      timeout-ms = <50>;
      key-positions = <22 23>;
      bindings = <&kp LBKT>;  // [
    };
    combo_right_curly_bracket {
      timeout-ms = <50>;
      key-positions = <6 7>;
      bindings = <&kp RBRC>;  // }
    };
    combo_right_parenthesis {
      timeout-ms = <50>;
      key-positions = <16 17>;
      bindings = <&kp RPAR>;  // )
    };
    combo_right_square_bracket {
      timeout-ms = <50>;
      key-positions = <26 27>;
      bindings = <&kp RBKT>;  // ]
    };
  };
};

/ {
    conditional_layers {
        compatible = "zmk,conditional-layers";
        mac_handsdown_gold_layer {
            if-layers = <1 3>;
            then-layer = <4>;
        };
        mac_numbers_layer {
            if-layers = <1 7>;
            then-layer = <8>;
        };
        mac_symbols_layer {
            if-layers = <1 9>;
            then-layer = <10>;
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
        &kp Q       &kp W        &kp E       &kp R        &kp T               &kp Y       &kp U        &kp I       &kp O        &kp P
        &hm LGUI A  &hm LSHFT S  &hm LALT D  &hm LCTRL F  &hm RALT G          &hm RALT H  &hm RCTRL J  &hm LALT K  &hm RSHFT L  &hm LGUI SEMI
        &lt ZMK_L Z &kp X        &kp C       &kp V        &kp B               &kp N       &kp M        &kp COMMA   &kp DOT      &lt ZMK_L FSLH
                                    &mt LSHFT BSPC  &lt SYM_L SPACE        &lt NUM_L SPACE  &lt NAV_L ENTER
        >;
    };

    // Momentary toggle of the default layer to trigger Conditional Layer changes on symbols/number layers.
    mac_layer {
      bindings = <
        &trans  &trans  &trans  &trans  &trans      &trans  &trans  &trans  &trans  &trans
        &trans  &trans  &trans  &trans  &trans      &trans  &trans  &trans  &trans  &trans
        &trans  &trans  &trans  &trans  &trans      &trans  &trans  &trans  &trans  &trans
                                &trans  &trans      &trans  &trans
        >;
    };

    colemak_layer {
      bindings = <
        &kp Q       &kp W        &kp F       &kp P        &kp G               &kp J       &kp L        &kp U       &kp Y        &kp SEMI
        &hm LGUI A  &hm LSHFT R  &hm LALT S  &hm LCTRL T  &hm RALT D          &hm RALT H  &hm RCTRL N  &hm LALT E  &hm RSHFT I  &hm LGUI O
        &lt ZMK_L Z &kp X        &kp C       &kp V        &kp B               &kp K       &kp M        &kp COMMA   &kp DOT      &lt ZMK_L FSLH
                                    &mt LSHFT BSPC  &lt SYM_L SPACE        &lt NUM_L SPACE  &lt NAV_L ENTER
        >;
    };


/*
  HandsDown Gold
  jz g  m  p  v   ;: .& /* "? '!
  r  s  n  d  b   ,| a  e  i  h
  x  f  l  c  w   -+ u  o  y  kq
              t   ␣
*/
    hdg_layer {
      bindings = <
        &kp J       &kp G        &kp M       &kp P        &kp V           &kp SEMI         &kp DOT      &kp FSLH    &kp AT       &kp SQT
        &hm LGUI R  &hm LSHFT S  &hm LALT N  &hm LCTRL D  &hm RALT B      &hm RALT COMMA   &hm RCTRL A  &hm LALT E  &hm RSHFT I  &hm LGUI H
        &lt ZMK_L X &kp F        &kp L       &kp C        &kp W           &kp MINUS        &kp U        &kp O       &kp Y        &lt ZMK_L K
                                    &mt LSHFT BSPC  &lt SYM_L T           &lt NUM_L SPACE  &lt NAV_L ENTER
        >;
    };

    hdg_mac_layer {
      bindings = <
        &trans  &trans  &trans  &trans  &trans    &trans  &trans  &trans  &kp DQT  &trans
        &trans  &trans  &trans  &trans  &trans    &trans  &trans  &trans  &trans   &trans
        &trans  &trans  &trans  &trans  &trans    &trans  &trans  &trans  &trans   &trans
                                &trans  &trans    &trans  &trans
        >;
    };

    game_base_layer {
      bindings = <
        &kp Q  &kp W  &kp E  &kp R  &kp T          &trans      &kp PG_UP     &kp UP        &kp PG_DN  &kp DEL
        &kp A  &kp S  &kp D  &kp F  &kp G          &kp HOME    &kp LEFT      &kp DOWN      &kp RIGHT  &kp END
        &kp Z  &kp X  &kp C  &kp V  &kp B          &kp C_MUTE  &kp C_VOL_DN  &kp C_VOL_UP  &kp INS    &kp PSCRN
               &kp LCTRL  &lt NUM_L SPACE          &trans      &trans
        >;
    };

    nav_layer {
      bindings = <
        &trans      &trans      &trans         &trans       &trans            &trans      &kp PG_UP     &kp UP        &kp PG_DN  &kp DEL
        &trans      &trans      &trans         &trans       &trans            &kp HOME    &kp LEFT      &kp DOWN      &kp RIGHT  &kp END
        &tog MAC_L  &to HDG_L   &to COLEMAK_L  &to DEFAULT  &to GAME_L        &kp C_MUTE  &kp C_VOL_DN  &kp C_VOL_UP  &kp INS    &kp PSCRN
                                                  &trans       &trans            &trans      &trans
        >;
    };

    num_layer {
      bindings = <
        &kp EXCL  &kp AT  &kp LS(N3)  &kp DLLR  &kp PRCNT       &kp CARET  &kp AMPS  &kp STAR  &kp LPAR  &kp RPAR
        &kp N1    &kp N2  &kp N3      &kp N4    &kp N5          &kp N6     &kp N7    &kp N8    &kp N9    &kp N0
        &kp F1    &kp F2  &kp F3      &kp F4    &kp F5          &kp F6     &kp F7    &kp F8    &kp DOT   &kp F12
                                      &trans    &trans          &trans     &trans
        >;
    };

    num_mac_layer {
      bindings = <
        &trans  &kp DQT  &trans  &trans  &trans      &trans  &trans  &trans  &trans  &trans
        &trans  &trans   &trans  &trans  &trans      &trans  &trans  &trans  &trans  &trans
        &trans  &trans   &trans  &trans  &trans      &trans  &trans  &trans  &trans  &trans
                                 &trans  &trans      &trans  &trans
        >;
    };

    sym_layer {
      bindings = <
        &kp EXCL  &kp AT    &kp LS(N3)  &kp DLLR         &kp PRCNT        &kp CARET        &kp AMPS   &kp STAR   &kp LPAR   &kp RPAR
        &kp LBRC  &kp LBKT  &kp LPAR    &kp MINUS        &kp GRAVE        &kp NON_US_HASH  &kp UNDER  &kp RPAR   &kp RBKT   &kp RBRC
        &kp DQT   &kp PLUS  &kp PIPE2   &kp NON_US_BSLH  &kp SQT          &kp PIPE         &kp FSLH   &kp EQUAL  &kp QMARK  &kp FSLH
                                        &trans           &trans           &trans           &trans
        >;
    };

    sym_mac_layer {
      bindings = <
        &trans  &kp DQT  &trans     &trans     &trans             &trans      &trans  &trans  &trans  &trans
        &trans  &trans   &trans     &trans     &kp NON_US_BSLH    &kp LA(N3)  &trans  &trans  &trans  &trans
        &kp AT  &trans   &kp PIPE   &kp BSLH   &trans             &kp PIPE2   &trans  &trans  &trans  &trans
                                    &trans     &trans             &trans      &trans
        >;
    };

    zmk_layer {
      // https://zmk.dev/docs/behaviors/bluetooth
      // https://zmk.dev/docs/behaviors/outputs
      // https://zmk.dev/docs/behaviors/reset
      bindings = <
        &bt BT_CLR    &out OUT_BLE  &out OUT_USB  &sys_reset    &bootloader         &bootloader   &sys_reset    &out OUT_USB  &out OUT_BLE  &bt BT_CLR
        &bt BT_SEL 0  &bt BT_SEL 1  &bt BT_SEL 2  &bt BT_SEL 3  &bt BT_SEL 4        &bt BT_SEL 4  &bt BT_SEL 3  &bt BT_SEL 2  &bt BT_SEL 1  &bt BT_SEL 0
        &trans        &trans        &trans        &trans        &trans              &trans        &trans        &trans        &trans        &trans
                                                  &trans        &trans              &trans        &trans
        >;
    };

  };
};
