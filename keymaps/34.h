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
#define COLEMAK_L 2  // Colemak Mod-DH: https://colemakmods.github.io/mod-dh/
#define GAME_L 3
#define NAV_L 4
#define NUM_L 5
#define NUM_MAC_L 6
#define SYM_L 7
#define SYM_MAC_L 8
#define ZMK_L 9



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
      layers = <0 2>;  // DEFAULT/COLEMAK_L
      timeout-ms = <50>;
      key-positions = <2 3>;
      bindings = <&kp AT>;
    };
    combo_speech_mark_mac {
      layers = <1>;  // MAC_L
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

// https://zmk.dev/docs/behaviors/hold-tap#example-use-cases
#define MO_TO(layer) &mo_to layer layer   // Macro to apply momentary-layer-on-hold/to-layer-on-tap to a specific layer


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
  mo_to: behavior_mo_to {
         compatible = "zmk,behavior-hold-tap";
         label = "mo_to";
         #binding-cells = <2>;
         flavor = "hold-preferred";
         tapping-term-ms = <200>;
         bindings = <&mo>, <&to>;
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

    mac_layer {
      bindings = <
        &trans  &trans  &trans  &trans  &trans      &trans  &trans  &trans  &trans  &trans
        &trans  &trans  &trans  &trans  &trans      &trans  &trans  &trans  &trans  &trans
        &trans  &trans  &trans  &trans  &trans      &trans  &trans  &trans  &trans  &trans
         &kp LC(BSPC)  &to SYM_NUM_MAC_L     &lt NUM_MAC_L SPACE  &trans
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

    game_layer {
      bindings = <
        &kp Q  &kp W  &kp E  &kp R  &kp T          &trans      &kp PG_UP     &kp UP        &kp PG_DN  &kp DEL
        &kp A  &kp S  &kp D  &kp F  &kp G          &kp HOME    &kp LEFT      &kp DOWN      &kp RIGHT  &kp END
        &kp Z  &kp X  &kp C  &kp V  &kp B          &kp C_MUTE  &kp C_VOL_DN  &kp C_VOL_UP  &kp INS    &kp PSCRN
               &kp LCTRL  &lt NUM_L SPACE          &trans      &trans
        >;
    };

    nav_layer {
      bindings = <
        &trans      &trans         &trans         &trans       &trans            &trans      &kp PG_UP     &kp UP        &kp PG_DN  &kp DEL
        &trans      &trans         &trans         &trans       &trans            &kp HOME    &kp LEFT      &kp DOWN      &kp RIGHT  &kp END
        &tog MAC_L  &to COLEMAK_L  &to COLEMAK_L  &to DEFAULT  &to GAME_L        &kp C_MUTE  &kp C_VOL_DN  &kp C_VOL_UP  &kp INS    &kp PSCRN
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
        &kp EXCL  &kp DQT &kp LS(N3)  &kp DLLR  &kp PRCNT       &kp CARET  &kp AMPS  &kp STAR  &kp LPAR  &kp RPAR
        &kp N1    &kp N2  &kp N3      &kp N4    &kp N5          &kp N6     &kp N7    &kp N8    &kp N9    &kp N0
        &kp F1    &kp F2  &kp F3      &kp F4    &kp F5          &kp F6     &kp F7    &kp F8    &kp DOT   &kp F12
                                      &trans    &trans          &trans     &trans
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
        &kp EXCL  &kp DQT   &kp LS(N3)  &kp DLLR   &kp PRCNT          &kp CARET   &kp AMPS   &kp STAR   &kp LPAR   &kp RPAR
        &kp LBRC  &kp LBKT  &kp LPAR    &kp MINUS  &kp NON_US_BSLH    &kp LA(N3)  &kp UNDER  &kp RPAR   &kp RBKT   &kp RBRC
        &kp AT    &kp PLUS  &kp PIPE    &kp BSLH   &kp SQT            &kp PIPE2   &kp FSLH   &kp EQUAL  &kp QMARK  &kp FSLH
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


/* New section of layers inspired by Ben Vallack's Sweep layout of going to layers to avoid holds.

- Make the MAC layer a dedicated layer instead of a toggle.
- Joined Symbol/Number (keypad) layer to reduce key presses switching between
  the two layers.
  - Aim is to reduce keypresses, eg. `[0]` was 6 keys + 3 alternate
    thumbs. Will now be 5 with 2 thumbs to enter/exit sym/num layer.
  - Moving back to using shift for getting to shifted symbols from lower
    symbols/numbers. Will be more shift key holding but reduces number of
    layers.
- Function layer (keypad) that is momentary from the Symbols/Number layer.
- Joined ZMK/Navigation layer for consolidation.
- Left thumb to cycle through layers, so no more holding needed.
- Right thumb to go back to DEFAULT layer.
- DEFAULT layer now has `Ctrl+Backspace` on thumb for hungry deletes by
  default. Backspace is on same key for other layers, for original behaviour.
 */

    sym_num_mac_layer {
      bindings = <
        &kp SQT    &kp DQT    &kp LBKT   &kp RBKT  &kp NON_US_HASH    &kp PLUS   &kp N7  &kp N8  &kp N9  &kp EQUAL
        &kp QMARK  &kp UNDER  &kp LPAR   &kp RPAR  &kp NON_USBSLH     &kp N0     &kp N1  &kp N2  &kp N3  &kp COLON
        &kp AT     &kp BSLH   &kp PIPE2  &kp FSLH  &kp PIPE           &kp MINUS  &kp N4  &kp N5  &kp N6  &kp DOT
                                &mt LSHFT BSPC  &to ZMK_NAV_L        &mo_to DEFAULT FUNCTION_L  &trans
        >;
    };

    zmk_nav_layer {
      // https://zmk.dev/docs/behaviors/bluetooth
      // https://zmk.dev/docs/behaviors/outputs
      // https://zmk.dev/docs/behaviors/reset
      bindings = <
        &bt BT_CLR    &out OUT_BLE  &out OUT_USB  &reset        &bootloader       &trans      &kp PG_UP     &kp UP        &kp PG_DN  &kp DEL
        &bt BT_SEL 0  &bt BT_SEL 1  &bt BT_SEL 2  &bt BT_SEL 3  &bt BT_SEL 4      &kp HOME    &kp LEFT      &kp DOWN      &kp RIGHT  &kp END
        &to MAC_L  &to COLEMAK_L  &to COLEMAK_L   &to DEFAULT  &to GAME_L         &kp C_MUTE  &kp C_VOL_DN  &kp C_VOL_UP  &kp INS    &kp PSCRN
                                                  &trans        &to DEFAULT       &to DEFAULT
       >;
   };

    function_layer {
      bindings = <
        &trans  &trans  &trans  &trans  &trans    &kp FN12  &kp FN7  &kp FN8  &kp FN9  &trans
        &trans  &trans  &trans  &trans  &trans    &kp FN10  &kp FN1  &kp FN2  &kp FN3  &trans
        &trans  &trans  &trans  &trans  &trans    &kp FN11  &kp FN4  &kp FN5  &kp FN6  &QMARK
                                &trans  &trans    &trans  &trans
        >;
    };
  };
};
